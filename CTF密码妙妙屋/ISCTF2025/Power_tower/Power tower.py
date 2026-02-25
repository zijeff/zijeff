from Crypto.Util.number import *
import random
from numpy import number

m = b'ISCTF{****************}'
flag = bytes_to_long(m)
n = getPrime(256)
t = getPrime(63)
l = pow(2,pow(2,t),n)
c = flag ^ l
print(t)
print(n)
print(c)


'''
t = 6039738711082505929
n = 107502945843251244337535082460697583639357473016005252008262865481138355040617
c = 114092817888610184061306568177474033648737936326143099257250807529088213565247
'''