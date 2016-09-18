import sys

class Problem():
    def solve(self):
        count = 0
        factorial = 1
        # F(n) = n F(n - 1) + (n - 1)! (2^{n - 1} - 1)
        for n in range(2, 30 + 1):
            count = count * n + (2**(n - 1) - 1) * factorial
            factorial = factorial * n
            expected_value = 1.0 * count / factorial
            print(n, '=>', expected_value)

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
