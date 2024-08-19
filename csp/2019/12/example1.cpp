#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> ans(4);
    for (gg i = 1; ni > 0; ++i) {
        if (i % 7 != 0 and to_string(i).find('7') == -1) {
            --ni;
        } else {
            ++ans[(i - 1) % 4];
        }
    }
    for (gg i : ans)
        cout << i << "\n";
    return 0;
}