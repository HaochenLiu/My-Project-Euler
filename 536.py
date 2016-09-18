import itertools
import math
import sys

class ProblemImpl():
    def __init__(self, number_theory):
        self.number_theory = number_theory
        self.n = number_theory.n
        self.primes = number_theory.primes
        self.count = len(number_theory.primes)
        self.prime_pos_vector = []
        self.prime_vector = []
        self.product = 1
        self.all_solutions = [1, 2, 3, 5, 21]

    def get(self):
        self.__backtrack()
        print(sum(self.all_solutions))

    def __get_solutions(self, prime_vector, product):
        if len(prime_vector) < 2:
            return []
        solutions = []
        divisors = self.number_theory.get_all_divisors(product + 3)[::-1]
        for x in divisors:
            q = x + 1
            d = product * q
            if d > self.n:
                continue
            if q <= prime_vector[-1]:
                break
            if not self.number_theory.is_prime(q):
                continue
            if self.__has_korselt_criterion(prime_vector, d):
                solutions.append(d)
        return solutions

    def __has_korselt_criterion(self, prime_vector, d):
        for prime in prime_vector:
            if (d + 3) % (prime - 1) != 0:
                return False
        return True

    def __backtrack(self):
        begin_pos = self.__get_begin_pos()

        solutions = self.__get_solutions(self.prime_vector, self.product)
        if solutions:
            print(solutions, '<=', self.prime_vector, self.product)
        self.all_solutions += solutions

        for i in range(begin_pos, self.count):
            prime = self.primes[i]
            if self.product * prime * (prime + 2) > self.n:
                break
            self.prime_pos_vector.append(i)
            self.prime_vector.append(prime)
            self.product *= prime
            self.__backtrack()
            self.product //= prime
            self.prime_vector.pop()
            self.prime_pos_vector.pop()

    def __get_begin_pos(self):
        if not self.prime_pos_vector:
            return 1
        else:
            return self.prime_pos_vector[-1] + 1

class NumberTheory():
    def __init__(self, n):
        self.n = n
        self.primes = self.__init_primes((int)(math.sqrt(n)))

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

    def is_prime(self, n):
        for p in self.primes:
            if p**2 > n:
                return True
            if n % p == 0:
                return False
        raise NotImplementedError('We cannot check large n')

    def factor(self, n):
        result = {}
        d = n
        for p in self.primes:
            if p**2 > d:
                break
            if d % p == 0:
                e = 0
                while d % p == 0:
                    e += 1
                    d = d // p
                result[p] = e
        if d > 1:
            result[d] = 1
        return result

    def get_all_divisors(self, n):
        factorization = self.factor(n)
        unpacking = [[p**e for e in range(factorization[p] + 1)] for p in factorization]
        return sorted([self.__product(divisor) for divisor in itertools.product(*unpacking)])

    def __product(self, list):
        result = 1
        for number in list:
            result *= number
        return result

class Problem():
    def solve(self):
        self.get(10**12)

    def get(self, n):
        ProblemImpl(NumberTheory(n)).get()
        
def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
