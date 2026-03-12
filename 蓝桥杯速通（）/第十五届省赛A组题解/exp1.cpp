#include <iostream>
#include <vector>
using namespace std;

// 检查某一种颜色是否已经形成五连
bool check(vector<vector<int>> &board, int color) {
    for (int i = 0; i < 5; i++) {
        if (board[i][0] == color && board[i][1] == color && board[i][2] == color && board[i][3] == color &&
            board[i][4] == color) {
            return false;
        }
        if (board[0][i] == color && board[1][i] == color && board[2][i] == color && board[3][i] == color &&
            board[4][i] == color) {
            return false;
        }
    }

    if (board[0][0] == color && board[1][1] == color && board[2][2] == color && board[3][3] == color &&
        board[4][4] == color) {
        return false;
    }

    if (board[0][4] == color && board[1][3] == color && board[2][2] == color && board[3][1] == color &&
        board[4][0] == color) {
        return false;
    }

    return true;
}

// pos：当前处理到第几个格子（0~24）
// black：当前已经放了多少个黑棋
void solve(vector<vector<int>> &board, int pos, int black, int &ans) {
    // 黑棋超过 12 个，不合法
    if (black > 12)
        return;
    // 剩余格子不够放满 12 个黑棋，剪枝
    if (25 - pos < 12 - black)
        return;
    // 25 个格子都处理完了
    if (pos == 25) {
        if (black == 12) {
            // 此时白棋自动是 13 个
            // 检查黑白双方都没有五连
            if (check(board, -1) && check(board, 1)) {
                ans++;
            }
        }
        return;
    }
    int x = pos / 5;
    int y = pos % 5;
    // 方案1：这个位置放黑棋
    board[x][y] = -1;
    if (check(board, -1))
        solve(board, pos + 1, black + 1, ans);

    // 方案2：这个位置放白棋
    board[x][y] = 1;
    if (check(board, 1))
        solve(board, pos + 1, black, ans);

    // 回溯
    board[x][y] = 0;
}
int main() {
    // 0->empty, 1->white, -1->black
    vector<vector<int>> board(5, vector<int>(5, 0));
    int ans = 0;
    solve(board, 0, 0, ans);
    cout << ans << endl;
    return 0;
}
