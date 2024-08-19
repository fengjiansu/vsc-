#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    int n;
    cin >> n;

    // ��ʼ����ҩ�̶Ⱦ���
    vector<vector<int>> D(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> D[i][j];

    // ��ʼ���������� perm
    vector<int> perm(n);
    for (int i = 0; i < n; ++i)
        perm[i] = i;

    int min_powder = INT_MAX;  // ��¼��С�Ļ�ҩ�̶�֮��
    vector<int> best_perm(n);  // ��¼��ҩ�̶���С������

    // ������������ n!
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // �����������в�����ÿ�����еĻ�ҩ�̶�֮��
    int half_factorial = factorial / 2; // ֻ����һ�������
    for (int count = 0; count < half_factorial; ++count) {

            int current_powder = 0;
            for (int i = 0; i < n - 1; ++i)
                current_powder += D[perm[i]][perm[i + 1]];

            // �����ǰ���еĻ�ҩ�̶�֮�͸�С��������ͬ���ֵ����С���������С��ҩ�̶Ⱥ��������
            if (current_powder < min_powder) {
                min_powder = current_powder;
                best_perm = perm;
            } else if (current_powder == min_powder && perm < best_perm) {
                best_perm = perm;
            }
        next_permutation(perm.begin(), perm.end());
    }

    // �����С��ҩ�̶�֮��
    cout << min_powder << endl;

    // �����ҩ�̶���С�����У�1-based��
    for (int i = 0; i < n; ++i)
        cout << best_perm[i] + 1 << " ";
    cout << endl;

    return 0;
}