#include <bits/stdc++.h>
using namespace std;
bool is_valid(vector<vector<int>> &board, int x, int y, int color) {
    if (x >= 2 && board[x - 1][y] == color && board[x - 2][y] == color)
        return false;
    if (y >= 2 && board[x][y - 1] == color && board[x][y - 2] == color)
        return false;
    int x_cnt = 0, y_cnt = 0;
    for (int i = 0; i < 6; i++) {
        if (board[x][i] == color)
            x_cnt++;
    }
    if (x_cnt >= 3)
        return false;
    for (int i = 0; i < 6; i++) {
        if (board[i][y] == color)
            y_cnt++;
    }
    if (y_cnt >= 3)
        return false;
    return true;
}
bool compare(vector<vector<int>> &board) {
    for (int i = 0; i < (6 - 1); i++) {
        for (int j = i + 1; j < 6; j++) {
            if (board[i] == board[j])
                return false;
            bool flag = true;
            for (int k = 0; k < 6; k++) {
                if (board[k][i] != board[k][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board, int x, int y) {
    if (x == 6)
        return compare(board);
    int nx = 0, ny = 0;
    if (y == 5) {
        nx = x + 1;
        ny = 0;
    } else {
        nx = x;
        ny = y + 1;
    }
    if (board[x][y] != -1)
        return solve(board, nx, ny);
    for (auto &color : {0, 1}) {
        if (is_valid(board, x, y, color) == true) {
            board[x][y] = color;
            if (solve(board, nx, ny) == true)
                return true;
            board[x][y] = -1;
        }
    }
    return false;
}
int main() {
    // -1 -> empty, 0 -> white, 1 -> black
    vector<vector<int>> board(6, vector<int>(6, -1));
    board[0][0] = 1;
    board[0][1] = 0;
    board[0][3] = 0;
    board[1][3] = 0;
    board[2][4] = 0;
    board[2][5] = 0;
    board[4][2] = 1;
    board[4][5] = 1;
    board[5][1] = 0;
    board[5][4] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    bool flag = solve(board, 0, 0);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i][j];
        }
    }
    cout << endl;
    return 0;
}
