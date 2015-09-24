#include <set>
#include <iostream>

using namespace std;

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int reverse(int n) {
	if(n <= 0) return 0;
	int res = 0;
	while(n > 0) {
		res *= 10;
		res += n % 10;
		n /= 10;
	}

	return res;
}

bool isPalindrome(int n) {
	if(n < 0) return false;
	return (n == reverse(n));
}

int main() {
	set<int> product;
	for(int i = 100; i < 1000; i++) {
		for(int j = i; j < 1000; j++) {
			product.insert(i * j);
		}
		cout<<i<<endl;
	}

	set<int>::reverse_iterator it = product.rbegin();
	while(it != product.rend()) {
		cout<<*it<<endl;
		if(isPalindrome(*it)) {
			cout<<"res "<<*it<<endl;
			break;
		} else {
			it++;
		}
	}

    int wait = 0;
    cin>>wait;

    return 0; 
}
