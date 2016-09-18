import itertools
import math
import sys

class Primes():
    def get(self, n):
        sqrt_n = int(math.sqrt(n))
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
            print('ValueError =>', d)
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
        self.primes = Primes().get(10**8)
        self.factorization_algorithm = FactorizationAlgorithm(self.primes)
        self.gozinta_value_cache = { 1 : 1 }

    def solve(self):
        print(self.get(10**16))

    def get(self, n):
        output = 0
        for prime_signature in self.__iterate_prime_signatures(n):
            gozinta_value = self.__get_gozinta_value(prime_signature)
            if gozinta_value > n:
                continue
            if self.__get_gozinta_value(gozinta_value) == gozinta_value:
                output += gozinta_value
                print(prime_signature, gozinta_value)
        return output

    def __get_gozinta_value(self, n):
        if n not in self.gozinta_value_cache:
            n_factorization = self.factorization_algorithm.get(n)
            all_divisors = self.factorization_algorithm.get_all_divisors(n_factorization)

            # g(n) = 1 + \sum_{d|n, d: proper} g(d)
            output = 1
            for d in all_divisors:
                if d > 1 and d < n:
                    output += self.__get_gozinta_value(d)
            self.gozinta_value_cache[n] = output
        return self.gozinta_value_cache[n]

    def __iterate_prime_signatures(self, n):
        stack = []

        # add 2^1, 2^2, ..., 2^e (less than or equal to n) to the stack.
        e = 1
        while True:
            d = 2**e
            if d > n:
                break
            stack.append([e])
            e += 1 

        while stack:
            top = stack.pop()
            value = self.__get_state_value(top)
            if value > n:
                continue
            yield value

            # Given a = p_0^e_0 p_1^e_1 ... p_k^e_k where e_0 >= ... >= e_k,
            # we add p_{k+1}^e_{k+1} to a where a * p_{k+1}^e_{k+1} <= n and e_{k+1} <= e_k
            e_bound = top[-1]
            for e in range(1, e_bound + 1):
                next_state = top + [e]
                stack.append(next_state)

    def __get_state_value(self, state):
        output = 1
        for i in range(len(state)):
            p = self.primes[i]
            e = state[i]
            output *= p**e
        return output

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
