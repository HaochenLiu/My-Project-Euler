#include <iostream>

using namespace std;

int main() {
    int res = 0;
	int f1 = 1;
	int f2 = 1;
	int f3;
	while(true) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		if(f3 > 4000000) {
			break;
		}

		if(f3 % 2 == 0) {
			res += f3;
		}
	}

	cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
