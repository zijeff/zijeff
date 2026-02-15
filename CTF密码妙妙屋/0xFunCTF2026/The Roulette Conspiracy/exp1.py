import random
from pwn import *

# --- 1. MT19937 逆向核心函数 ---
def inverse_right_shift(val, shift):
    res = val
    for i in range(32 // shift):
        res = val ^ (res >> shift)
    return res

def inverse_left_shift(val, shift, mask):
    res = val
    for i in range(32 // shift):
        res = val ^ ((res << shift) & mask)
    return res

def untemper(v):
    """撤销 MT19937 的 Tempering 过程，还原内部状态数组的值"""
    v = inverse_right_shift(v, 18)
    v = inverse_left_shift(v, 15, 0xefc60000)
    v = inverse_left_shift(v, 7, 0x9d2c5680)
    v = inverse_right_shift(v, 11)
    return v

# --- 2. 网络交互配置 ---
HOST = 'chall.0xfun.org' 
PORT = 43843

io = remote(HOST, PORT)

def get_next_raw():
    """发送 spin 指令并获取还原 XOR 后的原始随机数"""
    # 匹配提示符 "> " (注意可能有空格)
    io.sendlineafter(b">", b"spin")
    # 接收返回的一行数字
    line = io.recvline().decode().strip()
    # 兼容性处理：如果读到的是空行，再读一行
    while not line or not line.isdigit():
        line = io.recvline().decode().strip()
    
    obfuscated = int(line)
    # 题目逻辑：obfuscated = raw ^ 0xCAFEBABE
    raw = obfuscated ^ 0xCAFEBABE
    return raw

# --- 3. 收集 624 个状态以克隆生成器 ---
print("[*] 正在从服务器收集 624 个数据点...")
state_elements = []
for i in range(624):
    raw_val = get_next_raw()
    state_elements.append(untemper(raw_val))
    if (i + 1) % 100 == 0:
        print(f"已收集: {i+1}/624")

print("[+] 状态还原成功！")

# --- 4. 同步本地生成器 ---
# 设置 index 为 624，确保下一次 getrandbits 会触发 twist() 生成下一组序列
predictor = random.Random()
predictor.setstate((3, tuple(state_elements + [624]), None))

# --- 5. 提交预测 (一行提交) ---
print("[*] 正在准备预测结果...")
io.sendlineafter(b">", b"predict")

# 生成接下来 10 个原始值 (raw bits)
predictions = []
for i in range(10):
    val = predictor.getrandbits(32)
    predictions.append(str(val))
    print(f"预测值 {i+1:2d}: {val}")

# 将 10 个数字用空格连接成一行发送
payload = " ".join(predictions)
print(f"[*] 发送 Payload: {payload}")
io.sendline(payload.encode())

# --- 6. 获取 Flag ---
print("[!] 等待服务器响应 Flag...")
try:
    # 使用 interactive() 方便在拿到 Flag 后手动操作，或直接 recvall
    # io.interactive() 
    print(io.recvall(timeout=5).decode())
except Exception as e:
    print("\n[!] 读取结束或连接已关闭。")

io.close()