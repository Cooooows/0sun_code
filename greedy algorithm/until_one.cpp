#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int result = 0;
	while (N != 1) {
		if (N % K == 0) N /= K;
		else N -= 1;

		result++;
	}

	cout << result;

	return 0;
}