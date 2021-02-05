#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;

string map[100];
int check[100][100];

bool v[100][100] = { false, };


void bfs() {
    v[0][0] = true;
    queue <pair<int, int>> queue_;

    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    queue_.push(make_pair(0, 0));

    while (!queue_.empty()) {

        int x = queue_.front().first;
        int y = queue_.front().second;
        queue_.pop();

        for (int i = 0; i < 4; i++) {

            int current_x = x + dx[i];
            int current_y = y + dy[i];
            if (current_x < 0 || current_y < 0 || current_x >= N || current_y >= M) continue;
            if (map[current_x][current_y] == 1 && check[current_x][current_y] == 0 ) {
                check[current_x][current_y] = check[x][y] + 1;
                queue_.push(make_pair(current_x, current_y));
            }
        }
    }


}



int main()
{
    cin >> N >> M;

    //input map

    for (int i = 0; i < N; i++) cin >> map[i];


    bfs();

    cout << (check[N - 1][M - 1] + 1);
    return 0;
}