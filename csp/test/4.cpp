#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni,a1,tmp,xi, r=0;
    cin>>ni;
    vector<gg> a;
    vector<gg> b;
    for(gg i=0;i<ni;i++)
    {
        cin>>xi;
        a.push_back(xi);
    }
    if(ni==2)
    {
       for(gg i=1;i<(a[1]-a[0]);i++)
        {
            if((a[ni-1]-a[0])%i==0)
            {
                b.push_back(i);
            }
        } 
        for(auto & i: b)
        r=b.size();
    }
    else if(n==3)
    {
        
    }
    for(gg i=1;i<=ni;i++)
    {
        if((a[ni-1]-a[0])%i==0)
        {
            b.push_back(i);
        }
    }
    cout<<r;
    return 0;
}