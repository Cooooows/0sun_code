#include <iostream>
#include <queue>

/*
DFS : ����, ��� �Լ� �̿�
BFS : ť, ť �ڷᱸ�� �̿�

DFS�� ���� ����Լ��� �����Ǿ� ����
���� ��ǻ�� �ý����� ���� Ư���� ���� ���α׷��� ���� �ð��� ������ �� �ִ�.
==> ���� ���̺귯���� �̿��� �ð� ���⵵�� ��ȭ�ϴ� ��ũ���� �ʿ��ϴ�.
��ġ��,, ���װ��������� ����?
DFS �������ٴ� BFS ������ ���� �� ������ �����Ѵٰ� �������!
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

		if ((_temp.second + 1) < M && map[_temp.first][_temp.second + 1]== 0) {			//��
			q.push({ _temp.first, _temp.second + 1 });
			map[_temp.first][_temp.second + 1] = 1;
		}
		if ((_temp.second - 1) > -1 && map[_temp.first][_temp.second - 1]== 0 ) {		//��
			q.push({ _temp.first, _temp.second - 1 });
			map[_temp.first][_temp.second - 1] = 1;
		}
		if ((_temp.first + 1) < N && map[_temp.first + 1][_temp.second]== 0) {			//�Ʒ�
			q.push({ _temp.first + 1, _temp.second });
			map[_temp.first + 1][_temp.second] = 1;
		}
		if ((_temp.first - 1) > -1 && map[_temp.first - 1][_temp.second]== 0) {			//��
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
	//�Է³�

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (BFS(i, j) == true) cnt++;
		}
	}


	cout << cnt;
	
	return 0;
}