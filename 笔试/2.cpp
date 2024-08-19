#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sorted_lists(const vector<int>& L1, const vector<int>& L2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < L1.size() && j < L2.size()) {
        if (L1[i] <= L2[j]) {
            merged.push_back(L1[i]);
            i++;
        } else {
            merged.push_back(L2[j]);
            j++;
        }
    }
    // 将剩余的元素添加到 merged 中
    while (i < L1.size()) {
        merged.push_back(L1[i]);
        i++;
    }
    while (j < L2.size()) {
        merged.push_back(L2[j]);
        j++;
    }
    return merged;
}

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    
    vector<int> L1(N1), L2(N2);
    for (int i = 0; i < N1; ++i) {
        cin >> L1[i];
    }
    for (int i = 0; i < N2; ++i) {
        cin >> L2[i];
    }
    
    vector<int> merged_list = merge_sorted_lists(L1, L2);
    
    // 输出合并后的结果
    for (int num : merged_list) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
