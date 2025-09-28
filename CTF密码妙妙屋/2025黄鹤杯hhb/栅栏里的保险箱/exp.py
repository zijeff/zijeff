from Crypto.Util.number import *

p = 475983529392229563986300263627
q = 50994851324392722608175048292980313487272936248176620246821369736608473
c = 14357527460442347355096404625497793506543049498914015672502337590355030280127374107997576931872991169
n = p*q
phi_n = (p - 1)*(q - 1)
for e in range(3, 65537):
    if e % 2 == 0:
        continue
    if GCD(e, phi_n) != 1:
        continue
    d = inverse(e, phi_n)
    m = pow(c, d, n)
    if b'{'in long_to_bytes(m) and b'}'in long_to_bytes(m) and b'f'in long_to_bytes(m):
        if b'l'in long_to_bytes(m) and b'a'in long_to_bytes(m) and b'g'in long_to_bytes(m):
            print(e)
            print(long_to_bytes(m))

# m = b'f513lb9f22}a1a161gfe1f9{74ac82cc27cf23'
# flag{2fc7f1b59ae4c22a11f126fc73c89123}
