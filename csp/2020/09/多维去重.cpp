#include<bits/stdc++.h>
using namespace std;
using gg = long long;
void print_vec2(vector<vector<gg>>& vec)
{
    for (auto v : vec) {
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
}
int main()
{
      ios::sync_with_stdio(false);
    cin.tie(0);
    gg n,k,t,xl,yd,xr,yu,xt,yt;
    gg f,r,count;
    f=0;
    r=0;
  
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    // Remove Redundancy
    vector<vector<gg>> p(2);
    for(gg i=0;i<n;i++)
    {
          count=0;
        for(gg j=0;j<t;j++)
        {
            cin>>xt>>yt;
            p[0].push_back(xt);
            p[1].push_back(yt);
        }
    }
     sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    print_vec2(p);
    
    return 0;
}