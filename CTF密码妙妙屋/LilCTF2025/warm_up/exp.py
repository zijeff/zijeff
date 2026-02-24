from random import Random
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

def solve():
    ciphertext_hex = "ae39cfab1ba8d38fc3761216c393caf16e3c3f13fe57e2dedd52f1b13072fa93df405c7e731a193cabe5fd88ee3241f79aded62d139faba8c767a3b8efc5a855" 
    
    ct = bytes.fromhex(ciphertext_hex)

    key = Random(2025).randbytes(16)
    print(f"[+] Recovered Key: {key.hex()}")

    # 我们使用 ECB 模式来手动处理每个块的解密和异或操作
    aes_ecb = AES.new(key, AES.MODE_ECB)

    plaintext_suffix = b""
    for i in range(16, len(ct), 16):
        curr_blk = ct[i:i+16]
        prev_blk = ct[i-16:i]
        
        dec_out = aes_ecb.decrypt(curr_blk)
        pt_blk = bytes(a ^ b for a, b in zip(dec_out, prev_blk))
        plaintext_suffix += pt_blk

    print(f"[+] Recovered suffix (block 1+): {plaintext_suffix}")

    # 我们构建一个列表来存放 flag，目前已知的是 suffix 部分
    # 前16个字节初始化为0
    flag_bytes = list(b'\x00' * 16) + list(plaintext_suffix)
    
    # 计算第一块密文经过 AES 解密后的中间状态 X0
    # P0 = X0 ^ IV  =>  flag[0:16] = X0 ^ flag[9:25]
    x0 = aes_ecb.decrypt(ct[0:16])

    for i in range(7, 16):
        flag_bytes[i] = x0[i] ^ flag_bytes[i+9]
    
    for i in range(0, 7):
        flag_bytes[i] = x0[i] ^ flag_bytes[i+9]

    full_flag_padded = bytes(flag_bytes)
    try:
        flag = unpad(full_flag_padded, 16)
        print(f"[SUCCESS] FLAG: {flag.decode()}")
    except Exception as e:
        print(f"[!] Padding error or logic error: {e}")
        print(f"Raw recovered bytes: {full_flag_padded}")

if __name__ == "__main__":
    solve()