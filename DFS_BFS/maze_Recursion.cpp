#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M;
int min = 99999999;

stack <pair<int, int>> stack_;
vector<vector<int>> map;

void dfs(int x, int y, int cnt) {

	cout << "현재 위치 : " << x << "," << y << endl;

	//N,M인지 확인 후 종료
	if (x == (N - 1) && y == (M - 1)) {
		if(min > cnt){
			min = cnt;
		}
		return;
	}

	else {
		//4방위에 갈 곳이 있는지 확인
		if (x + 1 < N && map[x + 1][y] == 1) {
			stack_.push(make_pair(x+1, y));
			map[x+1][y] = 2;
			dfs(x + 1, y, cnt+1);
		}
		if (x - 1 > 0 && map[x - 1][y] == 1) {
			stack_.push(make_pair(x-1, y));
			map[x-1][y] = 2;
			dfs(x - 1, y,cnt+1);
		}
		if (y + 1 < M && map[x][y + 1] == 1) {
			stack_.push(make_pair(x, y+1));
			map[x][y+1] = 2;
			dfs(x, y + 1,cnt+1);
		}
		if (y - 1 > 0 && map[x][y - 1] == 1) {
			stack_.push(make_pair(x, y-1));
			map[x][y-1] = 2;
			dfs(x, y - 1,cnt+1);
		}


		//없으면 pop
		stack_.pop();
		pair<int, int> top = stack_.top();
		dfs(top.first, top.second,cnt-1);
	}

}

int main()
{
	cin >> N >> M;

	//input map
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

	dfs(0,0,1);


	return 0;
}
