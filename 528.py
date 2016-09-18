import itertools
import sys

class BaseConverter():
    def convert_decimal(self, n, base):
        reversed_rep = []
        d = n
        while d:
            d, r = divmod(d, base)
            reversed_rep.append(r)
        return reversed_rep[::-1]

    def convert_rep(self, rep, base):
        result = 0
        for digit in rep:
            result = result * base + digit
        return result

class BinomialCoefficient():
    def __init__(self, prime):
        self.prime = prime
        self.cache_values = {}
        self.base_converter = BaseConverter()

    def get(self, m, n):
        if m not in self.cache_values:
            self.cache_values[m] = {}
        if n not in self.cache_values[m]:
            m_rep = self.base_converter.convert_decimal(m, self.prime)
            n_rep = self.base_converter.convert_decimal(n, self.prime)
            offset = len(m_rep) - len(n_rep)
            result = 1
            for i in range(len(n_rep)):
                m_i = m_rep[offset + i]
                n_i = n_rep[i]
                if m_i < n_i:
                    return 0
                result = (result * self.__get_base_value(m_i, n_i)) % self.prime
            self.cache_values[m][n] = result
        return self.cache_values[m][n]

    def __get_base_value(self, m, n):
        if 2 * n > m:
            return self.__get_base_value(m, m - n)
        result = 1
        for i in range(1, n + 1):
            result = result * (m - i + 1) // i
        return result

class Problem():
    def __init__(self):
        self.mod = 1000000007
        self.binomial_coefficient = BinomialCoefficient(self.mod)

    def solve(self):
        self.benchmark()
        total_count = 0
        for k in range(10, 15 + 1):
            count = self.get(10**k, k, k)
            total_count = (total_count + count) % self.mod
            print(k, count, '=>', total_count)
        print(total_count)

    def benchmark(self):
        assert(self.get(14, 3, 2) == 135)
        assert(self.get(200, 5, 3) == 12949440)
        assert(self.get(1000, 10, 5) == 624839075)

    def get(self, n, k, b):
        bound_list = [b**(i + 1) for i in range(k)]
        total_count = 0
        for i in range(k + 1):
            for j in itertools.combinations(bound_list, i):
                reduced_n = n - sum(j) - i
                count = self.__get_k_multicombination(k + 1, reduced_n)
                total_count = (total_count + count * (-1)**i) % self.mod
        return total_count

    def __get_k_multicombination(self, n, k):
        if k < 0:
            return 0
        return self.binomial_coefficient.get(n + k - 1, k)

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
