#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<gg, array<gg, 2>> r;
    gg mi, y, res;
    cin >> mi;
    for (gg i = 0; i < mi; ++i) {
        cin >> y >> res;
        r[y][res]++;
    }
    gg p0 = 0, p1 = 0, ans = 0, c = 0;
    for (auto& i : r) {
        gg t = p0 + mi - p1;
        if (t >= c) {
            c = t;
            ans = i.first;
        }
        cout<<'t'<<t<<'c'<<c<<'a'<<ans<<endl;
        p0 += i.second[0];
        p1 += i.second[1];
        cout<<p0<<p1<<endl;
    }
    cout << ans << "\n";
    return 0;
}