import os
import random

class GiantLinearRNG:
    def __init__(self, seed_int, state_size=32):
        self.size = state_size
        self.state = []
        for i in range(self.size):
            shift = 64 * (self.size - 1 - i)
            self.state.append((seed_int >> shift) & 0xFFFFFFFFFFFFFFFF)

    def next(self):
        s = self.state
        taps = [0, 1, 3, 7, 13, 22, 28, 31]
        
        new_val = 0
        for i in taps:
            val = s[i]
            mixed = val ^ ((val << 11) & 0xFFFFFFFFFFFFFFFF) ^ (val >> 7)
            rot = (i * 3) % 64
            mixed = ((mixed << rot) | (mixed >> (64 - rot))) & 0xFFFFFFFFFFFFFFFF
            
            new_val ^= mixed
 
        new_val ^= (s[-1] >> 13) ^ ((s[-1] << 5) & 0xFFFFFFFFFFFFFFFF)
        new_val &= 0xFFFFFFFFFFFFFFFF
        self.state = s[1:] + [new_val]
        
        out = 0
        for i in range(self.size):
            if i % 2 == 0:
                out ^= self.state[i]
            else:
                val = self.state[i]
                out ^= ((val >> 2) | (val << 62)) & 0xFFFFFFFFFFFFFFFF
                
        return out

def main():
    flag = os.environ.get('FLAG', '0xfun{fake_f4lag_for_testing}')
    
    if flag.startswith('0xfun{') and flag.endswith('}'):
        content = flag[6:-1]
    else:
        print("Invalid flag format")
        return

    content_bytes = content.encode()
    if len(content_bytes) < 256:
        content_bytes = content_bytes.ljust(256, b'\0')
    else:
        content_bytes = content_bytes[:256]
        
    seed_int = int.from_bytes(content_bytes, 'big')
    
    rng = GiantLinearRNG(seed_int, state_size=32)
    
    print("Generating output...")
    outputs = []
    for _ in range(60):
        outputs.append(rng.next())
        
    print(outputs)

if __name__ == '__main__':
    main()
