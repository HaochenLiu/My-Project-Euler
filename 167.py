import sys

class Problem():
    def __init__(self):
        self.period_list = [32, 26, 444, 1628, 5906, 80, 126960, 380882, 2097152] # A100729
        self.difference_list = [126, 126, 1778, 6510, 23622, 510, 507842, 1523526, 8388606] # A100730

    def solve(self):
        total_sum = sum([self.get(n, 10**11) for n in range(2, 10 + 1)])
        print(total_sum)

    # U(2, 2n+1)
    def get(self, n, which_term): 
        t = n + 5
        period = self.period_list[n - 2]
        difference = self.difference_list[n - 2]
        q, r = divmod(which_term - t, period)
        period_term = self.__get_period_term(n, r)
        ulam = q * difference + period_term
        print(n, t, period, difference, '=>', q, r, '=>', ulam)
        return ulam
        
    def __get_period_term(self, n, which_one):
        first_even_term = 2
        second_even_term = 4 * n + 4
        odd_terms = set([2 * i + 1 for i in range(n, 2 * n + 2)])

        d = 4 * n + 5
        count = 0
        while True:
            if (d - first_even_term in odd_terms) ^ (d - second_even_term in odd_terms):
                if count == which_one:
                    return d
                odd_terms.add(d)
                count += 1
            d += 2

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
