#很简单的考察RSA基础的题目，已知RSA加密的基础条件，简单调用一下库函数即可解决。
from Crypto.Util.number import *

p = 1325465431
q = 152317153
e = 65537
phi = (p-1)*(q-1)
d = inverse(e, phi)
print(d)
