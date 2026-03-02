import random
import math

p = get_prime(1024)
q = get_prime(1024)
n = p * q
e = 65537

m = bytes_to_long(flag)
c = pow(m, e, n)

bases = get_primes_up_to(100)

hints = []
for i in range(len(bases)):
    for j in range(i+1, len(bases)):
        hint_value = (pow(bases[i], p-1, n) + pow(bases[j], p-1, n)) % n
        hints.append((bases[i], bases[j], hint_value))

