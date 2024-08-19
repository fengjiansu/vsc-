#include<bits/stdc++.h>
using namespace std;
using gg = long long;
constexpr gg INF = -2e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n,m,tmp,a,b;
    cin>>n>>m;
    vector<gg> t;
    vector<vector<gg>>ap(n);
    vector<gg> ans(3);
    for(gg i=0;i<n;i++)
    {
        cin>>a;
        t.push_back(a);
        for(gg j=0;j<m;j++)
        {
            cin>>b;
            ap[i].push_back(-b);
        }
    }
    ans[0]=0;
    ans[2]=INF;
    for(gg i=0;i<n;i++)
    {
        tmp=0;
        for(gg j=0;j<m;j++)
        {
           tmp+=ap[i][j];
        }
        ans[0]=ans[0]+t[i]-tmp;
        if(tmp>ans[2])
        {
            ans[2]=tmp;
            ans[1]=i+1;
        }
    }
    
    for(gg i=0;i<3;i++)
    {
        cout<<ans[i];
        if(i!=2)
        cout<<' ';
    }
    return 0;
}