# ==========================================
#  ██████╗ ██╗  ██╗███████╗██╗   ██╗███╗   ██╗
#  ██╔═████╗╚██╗██╔╝██╔════╝██║   ██║████╗  ██║
#  ██║██╔██║ ╚███╔╝ █████╗  ██║   ██║██╔██╗ ██║
#  ████╔╝██║ ██╔██╗ ██╔══╝  ██║   ██║██║╚██╗██║
#  ╚██████╔╝██╔╝ ██╗██║     ╚██████╔╝██║ ╚████║
#   ╚═════╝ ╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═╝  ╚═══╝
#
#                  Author:Hadi
#		  Challenge:Hawk_II
# ==========================================

from Crypto.Util.number import long_to_bytes
from random import randint
from sage.all import *
from hashlib import sha256
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from os import urandom
import random
import math

FLAG = open("flag.txt").read().strip().encode()

proof.all(0)


load("hawk.sage")


n = 256
sigma_kg  = 2
sigma_sig = sqrt(2)
sigma_ver = 2*2
num_leaks = n

Sig = SignatureScheme(n, sigma_kg, sigma_sig, sigma_ver)
sk,pk = Sig.KGen()

key = sha256(str(sk).encode()).digest()
iv = urandom(16)
cipher = AES.new(key=key, mode=AES.MODE_CBC, iv=iv)
enc = cipher.encrypt(pad(FLAG, 16))
print("iv = "+'"'+ iv.hex()+'"')
print("enc ="+'"'+ enc.hex()+'"')
print(f"{pk = }")
K = sk[0].parent()
sk0, sk1 = sk[:2]
N = n

assert len(list(sk1)) == N and 1 <= num_leaks <= N

I = set([0..n-1])
idx0 = set(random.sample(range(n), n//2))
idx1 = list(I.difference(idx0))
idx0 = list(idx0)

leak_vec0 = K([int(sk0[i]) if i in idx0 else 0 for i in range(n)])
leak_vec1 = K([int(sk1[i]) if i in idx1 else 0 for i in range(n)])

print("sk = ",sk)

combined_leaks = {
    'indices0': idx0,
    'indices1': idx1,
    'leak_vec0': leak_vec0,
    'leak_vec1': leak_vec1
}

print("leak_data = ",repr(combined_leaks))
