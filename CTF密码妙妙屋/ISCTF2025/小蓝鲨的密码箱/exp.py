cipher = "4a 54 44 55 47 7c 66 34 35 65 34 66 66 37 2e 39 31 64 31 2e 35 37 33 34 2e 63 39 67 37 2e 63 67 32 39 63 64 36 39 32 33 67 31 7e"

# 转为字节列表
bytes_list = [int(b, 16) for b in cipher.split()]

# 解密：每个字节 -1
plain_bytes = [(b - 1) & 0xFF for b in bytes_list]

# 转为字符串
result = ''.join(chr(b) for b in plain_bytes)
print(result)