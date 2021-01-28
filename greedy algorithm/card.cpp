#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
	clock_t start, finish; 
	double duration; 


	int N, M;
	int result = 0;
	cin >> N >> M;

	vector<vector<int>> card;
	vector<int> temp;
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &input);
			temp.push_back(input);
		}
		card.push_back(temp);
		temp.clear();
	}
	start = clock();
	vector<int> min;
	for (int i = 0; i < N; i++) {
		min.push_back(*min_element(card[i].begin(), card[i].end()));
	}

	result = *max_element(min.begin(), min.end());
	
	
	cout << result << endl;
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC; 
	cout << duration << "ÃÊ" << endl;

	return 0;

}