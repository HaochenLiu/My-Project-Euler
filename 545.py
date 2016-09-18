import itertools
import math
import sys

class Primes():
    def get(self, n):
        sqrt_n = math.floor(math.sqrt(n))
        visited = [False] * (n + 1)
        for i in range(2, sqrt_n + 1):
            if visited[i]:
                continue
            for j in range(i * i, n + 1, i):
                visited[j] = True
        
        primes = []
        for i in range(2, n + 1):
            if not visited[i]:
                primes.append(i)
        return primes

class FactorizationAlgorithm():
    def __init__(self, primes):
        self.primes = primes

    def get(self, n):
        output = {}
        d = n
        for prime in self.primes:
            if prime * prime > d:
                break
            e = 0
            while d % prime == 0:
                d //= prime
                e += 1
            if e > 0:
                output[prime] = e
        if d > 1:
            output[d] = 1

        if self.primes[-1] * self.primes[-1] < d:
            raise ValueError
        else:
            return output

    def is_prime(self, n):
        for prime in self.primes:
            if prime * prime > n:
                break
            if n % prime == 0:
                return False
        if self.primes[-1] * self.primes[-1] < n:
            raise ValueError
        else:
            return True

    def get_all_divisors(self, factorization):
        unpacking = [[prime**j for j in range(factorization[prime] + 1)] for prime in factorization]
        return sorted([self.__product(divisor) for divisor in itertools.product(*unpacking)])

    def __product(self, number_list):
        output = 1
        for number in number_list:
            output *= number
        return output

class Problem():
    def __init__(self):
        self.primes = Primes().get(10**5)
        self.factorization_algorithm = FactorizationAlgorithm(self.primes)

    def solve(self):
        print(self.get(10**5))

    def get(self, n):
        if n == 1:
            return 308

        count = 1
        visited_range = 100 * n
        visited = [False] * (visited_range + 1)
        for i in range(2, visited_range + 1):
            if visited[i]:
                continue
            denominator = self.__get_denominator(308 * i)
            if denominator != 20010:
                for j in range(i, visited_range, i):
                    visited[j] = True
            else:
                count += 1
                if count % 1000 == 0:
                    print(count, '=>', i)
                if count == n:
                    return 308 * i
        raise ValueError

    def __get_denominator(self, n):
        factorization = self.factorization_algorithm.get(n)
        all_divisors = self.factorization_algorithm.get_all_divisors(factorization)
        output = 1
        for divisor in all_divisors:
            if self.factorization_algorithm.is_prime(divisor + 1):
                output *= (divisor + 1)
        return output

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
