import secrets
import binascii

def simple_lfsr_encrypt(plaintext, init_state):
    mask = [random.randint(0,1) for _ in range(128)]
    
    state = init_state.copy()
    for _ in range(256):
        feedback = sum(state[i] & mask[i] for i in range(128)) % 2
        state.append(feedback)
    
    key = bytes(int(''.join(str(bit) for bit in mask[i*8:(i+1)*8]), 2) 
               for i in range(16))
    
    keystream = (key * (len(plaintext)//16 + 1))[:len(plaintext)]
    return bytes(p ^ k for p, k in zip(plaintext, keystream)), mask