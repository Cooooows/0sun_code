#include <iostream>
#include <queue>

/*
DFS : 스택, 재귀 함수 이용
BFS : 큐, 큐 자료구조 이용

DFS는 보통 재귀함수로 구현되어 있음
따라서 컴퓨터 시스템의 동작 특성상 실제 프로그램의 수행 시간이 느려질 수 있다.
==> 스택 라이브러리를 이용해 시간 복잡도를 완화하는 테크닉이 필요하다.
그치만,, 코테과정에서는 굳이?
DFS 구현보다는 BFS 구현이 조금 더 빠르게 동작한다고 기억하자!
*/

using namespace std;


int N, M;
vector<vector<int>> map;
queue<pair<int, int>> q;


bool BFS(int x, int y) {
	if (map[x][y] == 1) return false;

	pair<int, int> _temp = { x, y };
	q.push(_temp);
	map[x][y] = 1;
	while (!q.empty()) {
		_temp = q.front();
		q.pop();

		if ((_temp.second + 1) < M && map[_temp.first][_temp.second + 1]== 0) {			//오
			q.push({ _temp.first, _temp.second + 1 });
			map[_temp.first][_temp.second + 1] = 1;
		}
		if ((_temp.second - 1) > -1 && map[_temp.first][_temp.second - 1]== 0 ) {		//왼
			q.push({ _temp.first, _temp.second - 1 });
			map[_temp.first][_temp.second - 1] = 1;
		}
		if ((_temp.first + 1) < N && map[_temp.first + 1][_temp.second]== 0) {			//아래
			q.push({ _temp.first + 1, _temp.second });
			map[_temp.first + 1][_temp.second] = 1;
		}
		if ((_temp.first - 1) > -1 && map[_temp.first - 1][_temp.second]== 0) {			//위
			q.push({ _temp.first - 1 , _temp.second });
			map[_temp.first - 1][_temp.second] = 1;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	cin.ignore();

	string input;
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			temp.push_back(input[j] - '0');
		}
		map.push_back(temp);
		temp.clear();
	}
	//입력끝

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (BFS(i, j) == true) cnt++;
		}
	}


	cout << cnt;
	
	return 0;
}