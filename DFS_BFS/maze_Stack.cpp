#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int N, M;
int min_ = 99999999;

stack <pair<int, int>> stack_;
vector<vector<int>> map;

void printM() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}


void dfs(int x, int y) {
    int cnt = 0;

    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    while (!stack_.empty()) {
        pair<int, int> top = stack_.top();
        cnt++;
        cout << "현재 위치 : " << top.first << "," << top.second << endl;

        if (top.first == (N - 1) && top.second == (M - 1)) {
            cout << cnt << endl << endl;
            if (cnt < min_) {
                min_ = cnt;
            }

            cnt -= 2;

            cout << top.first << "," << top.second << endl;
            stack_.pop();
        }
        else {
            int flag = 0;
            for (int i = 0; i < 4; i++) {

                int current_x = top.first + dx[i];
                int current_y = top.second + dy[i];
                if (current_x < 0 || current_y < 0 || current_x > N - 1 || current_y > M - 1) continue;
                if (map[current_x][current_y] == 1) {
                    stack_.push(make_pair(current_x, current_y));
                    map[current_x][current_y] = 2;
                    flag = 1;
                }
            }
            if (flag == 0) {
                cnt--;
                //map[top.first][top.second] = 1;

                stack_.pop();
                cout << top.first << "," << top.second << endl;
                cout << "거리뺀다!!!!!!!!!!!" << endl;
            }
        }

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


    stack_.push(make_pair(0, 0));
    map[0][0] = 2;

    dfs(0, 0);

    cout << min_;
    return 0;
}