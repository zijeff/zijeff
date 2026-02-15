from base64 import b16encode, b32encode, b64encode, b85encode
from hashlib import sha1
from random import choice
from secret import flag

SCHEMES = [b16encode, b32encode, b64encode, b85encode]

ROUNDS = 16
current = flag.encode()
for _ in range(ROUNDS):
    checksum = sha1(current).digest() # this is to help you check the integrity of your decryption
    current = choice(SCHEMES)(current) 
    current += checksum

with open("output", "wb") as f:
    f.write(current)
