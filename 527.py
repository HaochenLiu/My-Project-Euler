import math
import sys

class Problem():
    def __init__(self):
        self.gamma = 0.5772156649015329

    def solve(self):
        print('%.8f' % self.get(6))
        print('%.8f' % self.get(10**10))

    def get(self, n):
        r = self.__get_in_random_binary_search(n)
        b = self.__get_in_standard_binary_search(n)
        return r - b

    def __get_in_standard_binary_search(self, n):
        m = n + 1
        k = self.__find_least_2_power(m)
        g = m - 2**(k - 1)
        a = 1 + m * k - 2**k
        return float(a) / float(n)

    def __get_in_random_binary_search(self, n):
        h = self.__find_harmonic_number(n)
        return 2.0 * (n + 1) / n * h - 3.0

    def __find_least_2_power(self, n):
        # Binary string is starting with '0b'. So we need to minus 2 from the length of binary string.
        return len(bin(n)) - 2

    def __find_harmonic_number(self, n):
        if n < 10:
            return sum(1.0 / i for i in range(1, n + 1))
        return math.log(n) + self.gamma + 1.0 / (2.0 * n) - 1.0 / (12.0 * n**2) + 1.0 / (120.0 * n**4)

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
