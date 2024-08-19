#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni, ai;
    cin >> ni;
    gg M1, M2, Mid1, Mid2;
    for (gg i = 0; i < ni; ++i) {
        cin >> ai;
        if (i == 0) {
            M1 = ai;
        } else if (i == ni - 1) {
            M2 = ai;
        } else if (ni % 2 == 1 and i == ni / 2) {
            Mid1 = Mid2 = ai;
        } else if (i == ni / 2) {
            Mid1 = ai;
        } else if (i == ni / 2 - 1) {
            Mid2 = ai;
        }
    }
    cout << max(M1, M2) << " " << fixed
         << setprecision((Mid1 + Mid2) % 2 == 0 ? 0 : 1) << (Mid1 + Mid2) / 2.0
         << " " << min(M1, M2);
    return 0;
}