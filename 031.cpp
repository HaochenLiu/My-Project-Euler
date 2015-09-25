#include <iostream>

using namespace std;

int tot = 200;

bool isBigger(int f200, int f100, int p50, int p20, int p10, int p5, int p2) {
    int res = 0;
    res += (f200 * 200);
    res += (f100 * 100);
    res += (p50 * 50);
    res += (p20 * 20);
    res += (p10 * 10);
    res += (p5 * 5);
    res += (p2 * 2);

    return (res > tot);
}

int main() {
    int res = 0;
    for(int f200 = 0; f200 <= tot / 200; f200++) {
        if(isBigger(f200, 0, 0, 0, 0, 0, 0)) break;
        for(int f100 = 0; f100 <= tot / 100; f100++) {
            if(isBigger(f200, f100, 0, 0, 0, 0, 0)) break;
            for(int p50 = 0; p50 <= tot / 50; p50++) {
                if(isBigger(f200, f100, p50, 0, 0, 0, 0)) break;
                for(int p20 = 0; p20 <= tot / 20; p20++) {
                    if(isBigger(f200, f100, p50, p20, 0, 0, 0)) break;
                    for(int p10 = 0; p10 <= tot / 10; p10++) {
                        if(isBigger(f200, f100, p50, p20, p10, 0, 0)) break;
                        for(int p5 = 0; p5 <= tot / 5; p5++) {
                            if(isBigger(f200, f100, p50, p20, p10, p5, 0)) break;
                            for(int p2 = 0; p2 <= tot / 2; p2++) {
                                if(isBigger(f200, f100, p50, p20, p10, p5, p2)) break;
                                res++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<res<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
