import sys

class Problem():
    def solve(self):
        assert(self.get(904961, 8) == 2714886)
        print(self.get(904961, 10**12))

    def get(self, m, n):
        assert(m % 2 == 1)
        assert(n % 2 == 0)
        return self.__get_even_power_sum(n // 2) * (m + 1)

    def __get_even_power_sum(self, upper_bound):
        total_sum = 0
        d = 2
        while d <= upper_bound:
            total_sum += upper_bound // d
            d *= 2 
        return total_sum

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
