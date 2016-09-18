import sys

class NumberTheory():
    def __init__(self, n):
        self.n = n
        self.primes = self.__init_primes(n)

    def __init_primes(self, n):
        primes = [] 
        visited = [False] * n
        visited[0] = visited[1] = True
        for i in range(2, n):
            if not visited[i]:
                primes.append(i)
                for j in range(i * i, n, i):
                    visited[j] = True
        return primes

class Problem():
    def __init__(self):
        self.mod = 1004535809
        self.values = {}
        self.performance_count = 0

    def solve(self):
        self.__init_values()
        print(self.get(20000, 20000))

    def benchmark(self):
        assert(self.get(3, 3) == 19)
        assert(self.get(1000, 1000) == 578270566)

    def get(self, n, k):
        if k not in self.values[n]:
            value = 0
            for i in range(n + 1):
                value += self.get(i, k // 2) * self.get(n - i, (k + 1) // 2)
            self.values[n][k] = value % self.mod
            self.performance_count += 1
            if self.performance_count % 1000 == 0:
                print(self.performance_count, n, k, '=>', self.values[n][k])
        return self.values[n][k]

    def __init_values(self):
        number_theory = NumberTheory(250000)
        n, prev_prime = 0, 1
        for prime in number_theory.primes:
            solution_count = prime - prev_prime
            self.values[n] = {}
            self.values[n][1] = solution_count
            n, prev_prime = n + 1, prime

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
