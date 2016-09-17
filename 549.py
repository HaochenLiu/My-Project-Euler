import sys

class Problem():
    def solve(self):
        assert(self.get(100) == 2012)
        print(self.get(10**8))
        
    def get(self, n):
        m_values = [1 for i in range(n + 1)]
        m_values[0] = m_values[1] = 0
        for i in range(2, n + 1):
            if m_values[i] == 1:
                d = i
                e = 1
                while d <= n:
                    m = self.__get_smallest_number_m(i, e)
                    for j in range(d, n + 1, d):
                        m_values[j] = max(m_values[j], m)
                    d = d * i
                    e += 1
        return sum(m_values)

    def __get_smallest_number_m(self, prime, exponent):
        lower_bound, upper_bound = 1, exponent 
        while lower_bound <= upper_bound:
            middle = (lower_bound + upper_bound) // 2
            middle_value = self.__adic_valuation(middle * prime, prime)
            if middle_value < exponent:
                lower_bound = middle + 1
            elif middle_value == exponent:
                return middle * prime
            else:
                upper_bound = middle - 1
        return lower_bound * prime

    def __adic_valuation(self, factorial_n, prime):
        output = 0
        d, k = prime, 1
        while d <= factorial_n: 
            output += factorial_n // d
            d *= prime
        return output

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())
