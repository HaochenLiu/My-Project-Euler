import math
import sys

class Problem():
    def __init__(self):
        self.hyperbola_point_count_cache = { 1 : 1 }
        self.hyperbola_coprime_point_count_cache = { 1 : 1 }

    def solve(self):
        for n in [10**15]:
            print(n, '=>', self.get(n))
            
    def get(self, n):
        total_count = 0
        m = math.floor(math.sqrt(n))
        r = math.floor(math.sqrt(m))
        g_bound = math.floor(math.sqrt(n // (r + 1)))
        for d in range(1, r + 1):
            coprime_point_count = self.__get_hyperbola_coprime_point_count(d)
            g_upper = self.__get_triangular_number(math.floor(math.sqrt(n // d)))
            g_lower = self.__get_triangular_number(math.floor(math.sqrt(n // (d + 1))))
            total_count += (g_upper - g_lower) * coprime_point_count
        print('d =>', total_count)
        for g in range(1, g_bound + 1):
            coprime_point_count = self.__get_hyperbola_coprime_point_count(n // g**2)
            total_count += g * coprime_point_count
            print('g =>', g, n // g**2, coprime_point_count, total_count)
        return total_count

    def __get_hyperbola_point_count(self, n):
        if n not in self.hyperbola_point_count_cache:
            total_count = 0
            m = math.floor(math.sqrt(n))
            for k in range(1, n // (m + 1) + 1):
                total_count += n // k
            for d in range(1, m + 1):
                total_count += d * (n // d - n // (d + 1))
            self.hyperbola_point_count_cache[n] = total_count
        return self.hyperbola_point_count_cache[n]

    def __get_hyperbola_coprime_point_count(self, n):
        if n not in self.hyperbola_coprime_point_count_cache:
            total_count = self.__get_hyperbola_point_count(n)
            m = math.floor(math.sqrt(n))
            for g in range(2, m + 1):
                total_count -= self.__get_hyperbola_coprime_point_count(n // g**2)
            self.hyperbola_coprime_point_count_cache[n] = total_count
        return self.hyperbola_coprime_point_count_cache[n]

    def __get_triangular_number(self, n):
        return (n * (n + 1)) // 2

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
