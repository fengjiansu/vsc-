#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const int INF = 1e9;

int n;
int D[MAXN][MAXN];
int dp[1 << MAXN][MAXN];
int parent[1 << MAXN][MAXN];

void solve() {
    // Initialize dp array with infinity
    memset(dp, INF, sizeof(dp));

    // Initialize base case
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    // DP transition
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) { // j not in mask
                    int new_mask = mask | (1 << j);
                    if (dp[new_mask][j] > dp[mask][i] + D[i][j]) {
                        dp[new_mask][j] = dp[mask][i] + D[i][j];
                        parent[new_mask][j] = i;
                    } else if (dp[new_mask][j] == dp[mask][i] + D[i][j]) {
                        // Ensure lexicographical order
                        int current_parent = parent[new_mask][j];
                        if (current_parent > i) {
                            parent[new_mask][j] = i;
                        }
                    }
                }
            }
        }
    }

    // Find minimum total cost
    int min_cost = INF;
    int end_point = -1;
    for (int i = 0; i < n; ++i) {
        if (min_cost > dp[(1 << n) - 1][i]) {
            min_cost = dp[(1 << n) - 1][i];
            end_point = i;
        }
    }

    // Output the minimum total cost
    cout << min_cost << endl;

    // Output the lexicographically smallest path
    vector<int> path;
    int mask = (1 << n) - 1;
    while (mask) {
        path.push_back(end_point);
        int next_point = parent[mask][end_point];
        mask ^= (1 << end_point);
        end_point = next_point;
    }
    reverse(path.begin(), path.end());

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << path[i] + 1; // convert to 1-based index
    }
    cout << endl;
}

int main() {
    cin >> n;

    // Read D matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> D[i][j];
        }
    }

    solve();

    return 0;
}
