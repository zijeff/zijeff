import json, secrets
from Crypto.Util.number import getPrime, bytes_to_long
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

e = 3
N = getPrime(512) * getPrime(512)

a2_high = a2 >> LOW_BITS

aes_key = secrets.token_bytes(16)
m = bytes_to_long(aes_key)

f = a2 * (m * m) + a1 * m + a0

c = (pow(m, e) + f) % N

iv = secrets.token_bytes(16)
cipher = AES.new(aes_key, AES.MODE_CBC, iv=iv)
ct = cipher.encrypt(pad(FLAG, 16))