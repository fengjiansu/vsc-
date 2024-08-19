#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using gg = long long;
using namespace std;
int main() {
    int n;
    cin >> n;
    
    vector<gg> fish_price(n);
    vector<gg> storage_cost(n);
    for (int i = 0; i < n; i++) {
        cin >> fish_price[i] >> storage_cost[i];
    }
  	vector<vector<gg>(n,0)> cost(n,0);
	for (int i=0; i < n; i++)
    {
      for (int j = i+1; j < n; j++)
      {
        cost[i][j] = fish_price[i]+storage_cost[i];
      }
    }
    vector<gg> dp(n, LLONG_MAX);
    dp[0] = fish_price[0]; 
   
    for (int i= 1; i < n; i++) {

        for (int j = 0; j < i; j++) {
          	
            dp[i] = min(dp[i], dp[j] + min(fish_price[i], fish_price[j] + cost[i][j]));
        }
    }
    
    cout << dp[n-1];
    
    return 0;
}
