#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> fish_cost(n), save_cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> fish_cost[i] >> save_cost[i];
    }

    vector<int> min_costs(n, 0);
    min_costs[0] = fish_cost[0]; 


    for (int i = 1; i < n; ++i) {
        min_costs[i] = min_costs[i - 1] + fish_cost[i];
        for (int j = 0; j < i; ++j) {
            min_costs[i] = min(min_costs[i], min_costs[j] + save_cost[j] * (i - j));
        }
    }

    
    cout << min_costs[n - 1] << endl;

    return 0;
}
