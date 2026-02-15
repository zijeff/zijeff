import random
from pwn import *
from randcrack import RandCrack

# --- 1. 初始化 ---
HOST = 'chall.0xfun.org'
PORT = 61868

io = remote(HOST, PORT)
rc = RandCrack()

def get_next_raw():
    """从服务器获取混淆值并还原为原始 raw 值"""
    io.sendlineafter(b">", b"spin")
    line = io.recvline().decode().strip()
    
    # 防止空行或非数字干扰
    while not line or not line.isdigit():
        line = io.recvline().decode().strip()
        
    obfuscated = int(line)
    # 题目逻辑：obfuscated = raw ^ 0xCAFEBABE
    raw = obfuscated ^ 0xCAFEBABE
    return raw

# --- 2. 收集 624 个数据点 ---
print("[*] 正在通过 randcrack 收集 624 个数据点...")
for i in range(624):
    raw_val = get_next_raw()
    # randcrack 会在内部自动调用 untemper 并填充状态数组
    rc.submit(raw_val)
    
    if (i + 1) % 100 == 0:
        print(f"进度: {i+1}/624")

print("[+] 状态克隆完成！")

# --- 3. 提交预测 (一行提交) ---
print("[*] 正在请求预测模式...")
io.sendlineafter(b">", b"predict")

# 使用 rc.predict_getrandbits(32) 获取预测出的接下来 10 个原始值
predictions = []
for i in range(10):
    p = rc.predict_getrandbits(32)
    predictions.append(str(p))
    print(f"预测值 {i+1:2d}: {p}")

# 将预测值以空格分隔拼成一行发送
payload = " ".join(predictions)
print(f"[*] 发送 Payload: {payload}")
io.sendline(payload.encode())

# --- 4. 获取 Flag ---
print("[!] 等待 Flag...")
try:
    # 预测成功后，服务器通常会打印 Flag
    print(io.recvall(timeout=5).decode())
except Exception as e:
    print("\n[!] 连接已关闭。")

io.close()