#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 优化解法
void optimized_solution() {
    // 实现你的优化解法
}

// 暴力解法
void brute_force_solution() {
    // 实现你的暴力解法
}

int main() {
    srand(time(0));  // 随机数种子
    int t = 100;  // 生成 100 个测试点
    while (t--) {
        // 随机生成测试数据
        int n = rand() % 100 + 1;  // 生成大小为 1 到 100 的随机测试点
        int q = rand() % 100 + 1;

        // 输出测试数据
        cout << "Testing with n = " << n << ", q = " << q << endl;

        // 运行暴力解法
        brute_force_solution();

        // 运行优化解法
        optimized_solution();

        // 比较结果
        if (/*比较结果不一致*/) {
            cout << "Discrepancy found!" << endl;
            // 输出错误的测试数据并退出
            break;
        }
    }

    return 0;
}
