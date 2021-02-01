#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				int i_1 = i % 10;
				int i_2 = i / 10;
				int j_1 = j % 10;
				int k_1 = k % 10;
				int j_2 = j / 10;
				int k_2 = k / 10;
				if (i_1 == 3 or i_2 == 3 or j_1 == 3 or j_2 == 3 or k_1 == 3 or k_2 == 3) {
					result++;
				}
			}
		}
	}

	cout << result << endl;;
	return 0;
}