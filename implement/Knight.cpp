#include <iostream>

using namespace std;


int x, y;
int cnt = 0;

void check() {
    if ((x + 2 <= 8) && (y + 1 <= 8)) cnt++;
    if ((x + 2 <= 8) && (y - 1 > 0)) cnt++;
    if ((x - 2 > 0) && (y + 1 <= 8)) cnt++;
    if ((x - 2 > 0) && (y - 1 > 0)) cnt++;
    if ((x + 1 <= 8) && (y + 2 <= 8)) cnt++;
    if ((x + 1 <= 8) && (y - 2 > 0)) cnt++;
    if ((x - 1 > 0) && (y + 2 <= 8)) cnt++;
    if ((x - 1 > 0) && (y - 2 > 0)) cnt++;
}

int main() {
    char input[2];
    cin >> input[0] >> input[1];

    x = (int)input[0] - '0' -48;
    y = (int)input[1] - 48;

    check();

    cout << cnt;
    return 0;
}