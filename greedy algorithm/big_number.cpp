#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b) { return a > b; }

int main() {
	int N, K, M; //배열의 크기, 더하기 횟수, K만큼 반복
	vector<int> arr;
	int temp;
	cin >> N >> M >> K;

	for (int i=0;i< N;i++){
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);

	int result = 0;
	int cnt = -1;
	for (int i = 0; i < M; i++) {
		cnt++;
		if (cnt != K) {
			result += arr[0];
		}
		else {
			result += arr[1];
			cnt = 0;
		}
	}

	cout << result;

	return 0;
}