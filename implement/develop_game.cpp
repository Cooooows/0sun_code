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
		int idx = find(direction, direction + 4, d) - direction; //현재 방향
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int _idx = (idx + i) % 4;
			d = direction[_idx];
			//아직 가본적이 없는 칸 이라면,
			if (map[move.first + x[_idx]][move.second + y[_idx]] == 0) {
				map[move.first + x[_idx]][move.second + y[_idx]] = 2; //가본 칸은 2
				move.first += x[_idx];
				move.second += y[_idx];
				cnt++;		//카운팅
				flag = 1;
				break;
			}
		}

		//네 방향 모두 이미 가본 칸이거나 바다로 되어 있는 칸이면
		//바라보는 방향을 유지한 채로 한 칸 뒤로 간다.
		//단 이때 뒤쪽 방향이 바다인 칸이라 뒤로 갈 수 없는 경우에는 움직임을 멈춘다.
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