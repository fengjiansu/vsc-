#include <iostream>
#include <vector>
using namespace std;
using gg = long long;
gg longest_alternating_subsequence(vector<gg>& a) {
    gg n = a.size();
    if (n == 0) return 0;
    
    vector<gg> inc(n, 1); 
    vector<gg> dec(n, 1); 
    
    for (gg i = 1; i < n; ++i) {
        for (gg j = 0; j < i; ++j) {
            if (a[i] > a[j]) {
                inc[i] = max(inc[i], dec[j] + 1);
            } else if (a[i] < a[j]) {
                dec[i] = max(dec[i], inc[j] + 1);
            }
        }
    }
    
    gg max_len = 0;
    for (gg i = 0; i < n; ++i) {
        max_len = max(max_len, max(inc[i], dec[i]));
    }
    
    return max_len;
}

int main() {
    gg n;
    cin >> n;
    
    vector<gg> a(n);
    for (gg i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    gg result = longest_alternating_subsequence(a);
    cout << result << endl;
    
    return 0;
}
