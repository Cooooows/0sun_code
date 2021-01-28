#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int N, M, K;
	vector<int> arr;
	int input;
	scanf("%d %d %d ", &N, &M, &K);

	while (N!=0) {
		scanf("%d", &input);
		arr.push_back(input);
		N--;
	}

	sort(arr.begin(), arr.end(), greater<int>());
	
	for (auto& e : arr) {
		cout << e << " ";
	}
	cout << endl;

	int first = arr[0];
	int second = arr[1];
	
	int result = 0;
	int calcu = M / (K + 1);
	int calcu2 = M % (K + 1);
	result += calcu*(first*K + second)+ calcu2*(first*K+second);

	cout << result << endl;



	return 0;
}