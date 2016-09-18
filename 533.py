import math
import sys

class PrimeTable():
    def get(self, bound):
        primes = []
        visited = [False] * (bound + 1)
        for i in range(2, bound + 1):
            if not visited[i]:
                primes.append(i)
            for j in range(i * i, bound + 1, i):
                visited[j] = True
        print('[DEBUG] Prime count:', len(primes))
        return primes

class Problem():
    def __init__(self):
        self.mod = 10**12

    def solve(self):
        #self.benchmark()
        print(self.get(20000000) % 10**9)

    def benchmark(self):
        assert self.get(6) == 241
        assert self.get(100) == 20174525281

    def get(self, n):
        primes = PrimeTable().get(n)
        value_map = [{} for i in range(0, n + 1, 2)]
        for p in primes:
            a = 1
            if p == 2:
                a = 3
            while True:
                q = self.__carmichael_function(p, a)
                if q > n:
                    break
                for j in range(q, n + 1, q):
                    value_map[j // 2][p] = a
                a += 1

        max_log_value_so_far = 0.0
        max_value_map_so_far = None
        max_index_so_far = None
        for i in range(2, n + 1, 2):
            x = value_map[i // 2]
            log_value = self.__get_log_value(x)
            if log_value > max_log_value_so_far:
                max_log_value_so_far = log_value
                max_value_map_so_far = x
                max_index_so_far = i
                print('[DEBUG]', max_index_so_far, '=>', max_log_value_so_far, '=>', max_value_map_so_far)
        return (self.__get_value(max_value_map_so_far) + 1) % self.mod

    def __carmichael_function(self, p, a):
        # compute carmichael function of p^a where p is a prime.
        if p == 2 and a > 2:
            return p**(a - 2)
        else:
            return p**(a - 1) * (p - 1)

    def __get_log_value(self, value_map):
        log_value = 0
        for p in value_map:
            a = value_map[p]
            log_value += math.log(p) * a
        return log_value

    def __get_value(self, value_map):
        value = 1
        for p in value_map:
            a = value_map[p]
            value = (value * pow(p, a, self.mod)) % self.mod
        return value

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
