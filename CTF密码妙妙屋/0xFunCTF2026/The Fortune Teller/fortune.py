#!/usr/bin/env python3

import random

class FortuneTeller:
    def __init__(self, seed=None):
        self.M = 2**64
        self.A = 2862933555777941757
        self.C = 3037000493
        self.state = seed if seed is not None else random.randint(1, self.M - 1)

    def next(self):
        self.state = (self.A * self.state + self.C) % self.M
        return self.state

    def glimpse(self):
        full = self.next()
        return full >> 32


if __name__ == "__main__":
    print("Fortune Teller Test")
    print("=" * 40)

    ft = FortuneTeller(seed=123456789)

    print("First 10 glimpses:")
    for i in range(10):
        g = ft.glimpse()
        print(f"Glimpse {i+1:2d}: {g}")
