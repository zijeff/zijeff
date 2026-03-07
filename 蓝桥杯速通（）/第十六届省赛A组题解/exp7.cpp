#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#define Pi 3.1415926
using namespace std;
// 定义炸弹结构体
typedef struct {
    int x;
    int y;
    int r;
} Bomb;
// 定义区间结构体
typedef struct {
    double left;
    double right;
} Interval;
int main() {
    int n = 0;
    cin >> n;
    // 读入数据
    vector<Bomb> danger(n);
    for (int i = 0; i < n; i++) {
        cin >> danger[i].x >> danger[i].y >> danger[i].r;
    }
    vector<Interval> res(n);
    for (int i = 0; i < n; i++) {
        double alpha = atan2(danger[i].y, danger[i].x);
        double d = sqrt(pow(danger[i].x, 2) + pow(danger[i].y, 2));
        double beta = asin(danger[i].r / d);
        res[i] = {alpha - beta, alpha + beta};
    }
    // 区间合并
    sort(res.begin(), res.end(), [](const Interval &a, const Interval &b) { return a.left < b.left; });
    double sum = 0;
    double current_left = res[0].left, current_right = res[0].right;
    for (int i = 1; i < n; i++) {
        if (res[i].left > current_right) {
            sum += (current_right - current_left);
            current_left = res[i].left;
            current_right = res[i].right;
        } else {
            current_left = min(current_left, res[i].left);
            current_right = max(current_right, res[i].right);
        }
    }
    sum += (current_right - current_left);
    double ans = 1 - (2 * sum / Pi);
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
