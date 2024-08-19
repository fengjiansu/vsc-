#include<bits/stdc++.h>
using namespace std;
 

 
int main()
{
    int n, m;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> m;
        num.push_back(m);
    }
    sort(num.begin(), num.end());
    cout << num[(n-1) / 2];
    return 0;
}