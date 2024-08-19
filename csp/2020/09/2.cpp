#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n,k,t,xl,yd,xr,yu,xt,yt;
    gg f,r,count;
    f=0;
    r=0;
  
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;

    for(gg i=0;i<n;i++)
    {
        vector<vector<gg>> p(2);
        count=0;
        for(gg j=0;j<t;j++)
        {
            cin>>xt>>yt;
            p[0].push_back(xt);
            p[1].push_back(yt);
            if(p[0][j]>=xl&&p[0][j]<=xr&&p[1][j]>=yd&&p[1][j]<=yu)
        {
              count++;
        }
        }
        p.shrink_to_fit();
    
        if(count>=k)
        {
            f++;
            r++;
        }
       
    }
    cout<<f<<endl<<r;
    return 0;

}