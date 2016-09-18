import sys

class Problem():
    def __init__(self):
        self.mod = 987654321
        self.sum_cache = { 1 : 1 }
        self.last_number_left_cache = { 1 : 1 }

    def solve(self):
        for n in [1000, 10**18]:
            print('S({n}) = {value}'.format(n=n, value=self.get(n) % self.mod))

    def get(self, n):
        if n not in self.sum_cache:
            m, r = divmod(n, 2)
            if r == 0:
                self.sum_cache[n] = 2 * n - 1 + 2 * m * m - 4 * self.get(m) + 2 * self.get_last_number_left(m)
            else:
                self.sum_cache[n] = 2 * n - 1 + 2 * m * (m + 1) - 4 * self.get(m)
        return self.sum_cache[n]

    def get_last_number_left(self, n):
        if n not in self.last_number_left_cache:
            self.last_number_left_cache[n] = 2 * (n // 2) + 2 - 2 * self.get_last_number_left(n // 2)
        return self.last_number_left_cache[n]

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
