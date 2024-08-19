#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2001;
const int INF = 1e9;

int n, m;
int t[MAXN][MAXN];
int dp[2][MAXN];

int main() {
    cin >> n >> m;

    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> t[i][j];
        }
    }

    for (int j = 1; j <= m; ++j) {
        dp[0][j] = t[1][j];
    }

    
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[(i-1) % 2][j] = INF;
            for (int k = 1; k <= m; ++k) {
                if (k == j || k == (j == 1 ? m : j - 1)) {
                    dp[(i-1) % 2][j] = min(dp[(i-1) % 2][j], dp[(i-2) % 2][k] + t[i][j]);
                }
            }
        }
    }

    
    int min_time = INF;
    for (int j = 1; j <= m; ++j) {
        min_time = min(min_time, dp[(n-1) % 2][j]);
    }

    cout << min_time << endl;

    return 0;
}
