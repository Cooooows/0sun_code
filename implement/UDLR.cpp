#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N;
    cin >> N;
    cin.ignore();
    int x[] = { 0, -1, 0, 1 };
    int y[] = { -1, 0, 1, 0}; //ÁÂ, À§, ¿ì, ¾Æ·¡
    vector<int> direction = { 'L','U','R','D' };

    char move[200] = { NULL };
    cin.getline(move, 200);

    vector<int> result = { 1,1 };
    int i = 0;
    while (move[i] != NULL) {
        vector<int> temp = result;

        for (int e = 0; e < direction.size(); e++) {
            if (move[i] == ' ') {
                temp[0] = -1;
                break;
            }
            if (move[i] == direction[e]) {
                temp[0] += x[e];
                temp[1] += y[e];
            }
        }

        i++;
        if (temp[0]<1 || temp[0] >N || temp[1] <1 || temp[1] > N) continue;

        result = temp;
    }
    cout << result[0] <<" "<< result[1] << endl;
    return 0;
}