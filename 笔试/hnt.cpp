#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    int n;
    cin >> n;

    // 初始化火药程度矩阵
    vector<vector<int>> D(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> D[i][j];

    // 初始化排列数组 perm
    vector<int> perm(n);
    for (int i = 0; i < n; ++i)
        perm[i] = i;

    int min_powder = INT_MAX;  // 记录最小的火药程度之和
    vector<int> best_perm(n);  // 记录火药程度最小的排列

    // 计算排列数量 n!
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // 生成所有排列并计算每个排列的火药程度之和
    int half_factorial = factorial / 2; // 只遍历一半的排列
    for (int count = 0; count < half_factorial; ++count) {

            int current_powder = 0;
            for (int i = 0; i < n - 1; ++i)
                current_powder += D[perm[i]][perm[i + 1]];

            // 如果当前排列的火药程度之和更小，或者相同但字典序更小，则更新最小火药程度和最佳排列
            if (current_powder < min_powder) {
                min_powder = current_powder;
                best_perm = perm;
            } else if (current_powder == min_powder && perm < best_perm) {
                best_perm = perm;
            }
        next_permutation(perm.begin(), perm.end());
    }

    // 输出最小火药程度之和
    cout << min_powder << endl;

    // 输出火药程度最小的排列（1-based）
    for (int i = 0; i < n; ++i)
        cout << best_perm[i] + 1 << " ";
    cout << endl;

    return 0;
}