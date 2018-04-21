#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isInteger(float f) {
	int i = (int)f;
	return f - (float)i < 0.0001;
}

int main(int argc, char* argv[]) {
	int P = 10000000;
	float sum = 0.0;

	// a <= b <= c
	// p = a + b + c
	for (int p = 1; p <= P; p++) {
		for (int a = 1; a <= p / 3; a++) {
			for (int b = a; b < p; b++) {
				int c = p - a - b;
				if (c >= a + b) {
					continue;
				}

				if (c < b) {
					break;
				}

				float fa = (float)a;
				float fb = (float)b;
				float fc = (float)c;
				float fs = (a + b + c) / 2.0;
				float IA = sqrt((fs - fa) * (fs - fa) + (fs - fa) * (fs - fb) * (fs - fc) / fs);
				if (!isInteger(IA)) {
					continue;
				}

				float IB = sqrt((fs - fb) * (fs - fb) + (fs - fa) * (fs - fb) * (fs - fc) / fs);
				if (!isInteger(IB)) {
					continue;
				}

				float IC = sqrt((fs - fc) * (fs - fc) + (fs - fa) * (fs - fb) * (fs - fc) / fs);
				if (!isInteger(IC)) {
					continue;
				}

				// printf("IA = %f\n", IA);
				// printf("IB = %f\n", IB);
				// printf("IC = %f\n", IC);
				sum += fa + fb + fc + IA + IB + IC;
			}
		}

		if (p % 1000 == 0) {
			printf("sum = %f p = %d\n", sum, p);
		}
	}

	printf("sum = %f\n", sum);

	system("pause");

	return 0;
}
