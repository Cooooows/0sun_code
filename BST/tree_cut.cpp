#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long N, M, input;
	long long result = 0;
	cin >> N >> M;
	vector<long long> length;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &input);
		length.push_back(input);
	}

	long long total = 0;
	long long mid = 0;
	long long start = 0;
	long long end = *max_element(length.begin(), length.end());

	while (start <= end) {
		total = 0;
		mid = (start + end) / 2;

		//�߶��� �� ���� �� ���
		for (auto e : length) {
			if (e > mid) {
				total += e - mid;
			}
		}

		//BST
		//�� ���� (���� �κФ�)
		if (total < M) {
			end = mid - 1;
		}
		//�� ��ħ (���������Τ�)
		else {
			result = mid;
			start = mid + 1;
		}
	}



	cout << result;

	return 0;
}