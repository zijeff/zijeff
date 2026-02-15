#!/usr/bin/env python3

import random

class MersenneOracle:
    def __init__(self):
        self.mt = random.Random()
        self.mt.seed(random.randint(0, 2**32 - 1))

    def spin(self):
        raw = self.mt.getrandbits(32)
        obfuscated = raw ^ 0xCAFEBABE
        return obfuscated

    def _get_state(self):
        return self.mt.getstate()[1][:624]


if __name__ == "__main__":
    print("Mersenne Oracle Test")
    print("=" * 40)

    oracle = MersenneOracle()

    print("First 10 spins:")
    for i in range(10):
        spin = oracle.spin()
        print(f"Spin {i+1:2d}: {spin}")
