#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const int N = 1000; 

struct bignum {
    int a[N];
    int point; 
} num; 

bignum operator*(bignum x, bignum y) {
    bignum z;
    z.point = x.point + y.point;
    memset(z.a, 0, sizeof(z.a)); 

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            z.a[i] += x.a[j] * y.a[i - j];
        }
    }

    int carry = 0;

    for(int i = 0; i < N; i++) {
        z.a[i] = z.a[i] + carry;
        carry = z.a[i] / 10;
        z.a[i] %= 10;
    }

    return z;
} 
                 
bignum square(bignum x) {
    return x * x;
}

/*
x^y
*/
bignum operator&(bignum x,int y) {
    if(y == 1) return x;
    if((y & 1) == 0) {
        return square(x & (y >> 1));
    } else {
        return x * square(x & (y >> 1));
    }
}

void printNum(bignum num) {
    for(int i = 0; i < N; i++) {
        cout<<num.a[i];
    }
    cout<<endl;
    cout<<"num.point "<<num.point<<endl;

    return;
}

int main() {
	bignum num;
	memset(num.a, 0, sizeof(num.a));
	num.a[0] = 2;
	num = (num & 1000);

	int res = 0;
	for(int i = 0; i < N; i++) {
		res += num.a[i];
	}

	cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
