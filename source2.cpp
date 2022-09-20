#include <iostream>
#include <string>

#define MAX 100000000000
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		long long num;
		int ans = 0;
		
		cin >> num;

		while (num != 0) {
			int first_digit, second_digit;
			long long digits;

			for (long long i = MAX; i > 0; i /= 10) {
				if (num / i != 0) {
					digits = i;
					first_digit = num / i;
					if (i != 1) {
						second_digit = (num - first_digit * i) / (i / 10);
					}
					else {
						second_digit = 0;
					}
					break;
				}
			}

			if (first_digit >= 6) {
				num = abs(num - digits * 10);
				ans += 1;
			}
			else if (first_digit == 5 && second_digit >= 5) {
				num = abs(num - digits * 10);
				ans += 1;
			}
			else if (second_digit >= 6) {
				num = abs(num - (first_digit + 1) * digits);
				ans += (first_digit + 1);
			}
			else {
				num = abs(num - first_digit * digits);
				ans += first_digit;
			}
		}
		cout << ans << "\n";
	}
}