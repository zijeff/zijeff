#!/usr/bin/env python3
from  random import *
from secret import FLAG
from Crypto.Util.number import *



m = bytes_to_long(FLAG)
a = [427,403,267,235,187,123,115,91,35,51]
D = choice(a)
while True:
    V = getRandomInteger(2 ** 2048)
    numbers = D * V ** 2 + 1
    if numbers % 4 == 0:
        p = numbers // 4
        if isPrime(p):
            q = getPrime(2048)
            n = p * q
            e = 0x10001
            c = pow(m, e, n)
            print(f"n : {n}","\n",f"e : {e}","\n",f"c : {c}")
            exit(0)
        else:
            print("numbers is not Prime!!!")
    else:
        print("It is not divisible by 4!!!")


