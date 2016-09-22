#include <assert.h> 
#include <stdio.h>

#define N 701408734
#define PRIME_COUNT 36322186

long fibonacci_numbers[45] = {};
long primes[PRIME_COUNT] = {};

void initPrimes() {
    static bool visited[N] = {};
    int d = 0;
    for (long i = 2; i < N; i++) {
        if (!visited[i]) {
            for (long j = i * i; j < N; j += i) {
                visited[j] = true;
            }
            primes[d] = i;
            d++;
        }
    }
}

void initFibonacciNumbers() {
    fibonacci_numbers[0] = 0L;
    fibonacci_numbers[1] = 1L;
    for (long i = 2; i < 45; i++) {
        fibonacci_numbers[i] = fibonacci_numbers[i - 1] + fibonacci_numbers[i - 2];
    }
}

long getPrimeCounting(long n) {
    long lower_bound = 0L;
    long upper_bound = PRIME_COUNT - 1L;
    while (lower_bound <= upper_bound) {
        long middle = lower_bound + (upper_bound - lower_bound) / 2;
        if (primes[middle] < n) {
            lower_bound = middle + 1;
        }
        else if (primes[middle] == n) {
            return middle + 1;
        }
        else {
            upper_bound = middle - 1;
        }
    }
    return lower_bound;
}

long get(long n) {
    long total_sum = getPrimeCounting(n);

    if (n >= 4) {
        total_sum += n / 2 - 1; 
    }
    if (n >= 5) {
        total_sum += getPrimeCounting(n - 2) - 1;
    }

    if (n > 5) {
        long max_k = n / 2;
        long first_term = n - 6 + 1;
        long last_term = n - 2 * (n / 2) + 1;
        long term_count = (first_term - last_term) / 2 + 1;
        total_sum += (first_term + last_term) * term_count / 2;
    }

    return total_sum;
}

void benchmark() {
    assert(get(2) == 1);
    assert(get(3) == 2);
    assert(get(4) == 3);
    assert(get(10) == 20);
    assert(get(100) == 2402);
    assert(get(1000) == 248838);
}

void solve() {
    initFibonacciNumbers();

    long total_sum = 0;
    for (long i = 3; i <= 44; i++) {
        long partial_sum = get(fibonacci_numbers[i]);
        total_sum += partial_sum;
    }

    printf("Sum[S(F(k))] = %ld \n", total_sum);
}

int main() {
    initPrimes();
    benchmark();
    solve();
    return 0;
}
