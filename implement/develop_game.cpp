#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


int main() {

	int cnt = 0;
	int N, M, d, input;
	pair<int, int> move;
	
	cin >> N >>M >> move.first >> move.second >> d;

	int** map;
	map = new int*[N];
	for (int i = 0; i < N; ++i) {
		map[i] = new int[M];
	}
	cin.ignore();
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &input);
			map[i][j] = input;
		}
	}

	int direction[] = { 0,3,2,1};
	int x[] = { 0,-1,0,1 };
	int y[] = { 1,0,-1,0 };

	map[move.first][move.second] = 2; 
	cnt++;
	while (1) {
		int idx = find(direction, direction + 4, d) - direction; //���� ����
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int _idx = (idx + i) % 4;
			d = direction[_idx];
			//���� �������� ���� ĭ �̶��,
			if (map[move.first + x[_idx]][move.second + y[_idx]] == 0) {
				map[move.first + x[_idx]][move.second + y[_idx]] = 2; //���� ĭ�� 2
				move.first += x[_idx];
				move.second += y[_idx];
				cnt++;		//ī����
				flag = 1;
				break;
			}
		}

		//�� ���� ��� �̹� ���� ĭ�̰ų� �ٴٷ� �Ǿ� �ִ� ĭ�̸�
		//�ٶ󺸴� ������ ������ ä�� �� ĭ �ڷ� ����.
		//�� �̶� ���� ������ �ٴ��� ĭ�̶� �ڷ� �� �� ���� ��쿡�� �������� �����.
		if (flag == 0) {
			int _x = move.first + x[(idx + 2)%4];
			int _y = move.second + y[(idx + 2)%4];
			if (map[_x][_y] == 1) break;
			else { 
				move.first = _x;
				move.second = _y;
			}
		}
	}

	cout << cnt;
	return 0;
}