from base64 import b16decode, b32decode, b64decode, b85decode
from hashlib import sha1

# 定义解码函数列表
DECODERS = [b16decode, b32decode, b64decode, b85decode]

def solve():
    # 1. 读取 output 文件内容
    with open("output", "rb") as f:
        current = f.read()

    rounds = 16

    for i in range(rounds):
        # 2. 提取最后 20 字节的校验和
        checksum = current[-20:]
        # 3. 提取前面的编码数据
        payload = current[:-20]
        
        found = False
        # 4. 尝试四种解码方式
        for decode_func in DECODERS:
            try:
                decoded = decode_func(payload)
                # 5. 校验 SHA1 是否匹配
                if sha1(decoded).digest() == checksum:
                    current = decoded
                    print(f"第 {i+1} 轮解密成功: 使用了 {decode_func.__name__}")
                    found = True
                    break
            except Exception:
                # 如果解码失败（比如字符不符合规范），尝试下一种
                continue
        
        if not found:
            print(f"错误：在第 {i+1} 轮未能匹配到正确的解码方式。")
            break
    
    # 输出结果
    print("\n最终结果 (Flag):")
    print(current.decode(errors='ignore'))

if __name__ == "__main__":
    solve()