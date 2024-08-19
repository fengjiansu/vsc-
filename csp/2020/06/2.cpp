#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni,ai,bi,x,y,r=0;
    cin>>ni>>ai>>bi;
    map<gg,gg> u;
    while(ai--)
    {
        cin>>x>>y;
        u[x]=y;
    }
    while(bi--)
    {
        cin>>x>>y;
       r+=u[x]*y;
    }
    cout<<r;
    return 0;
}