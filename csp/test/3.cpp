#include<bits/stdc++.h>
using namespace std;
using gg = long long;
gg p(gg tmp)
{
       vector<gg> b;
       gg r=0;
       for(gg i=1;i<(tmp);i++)
        {
            if((tmp)%i==0)
            {
                b.push_back(i);
            }
        } 
        for(auto & i: b)
        r=b.size();
        b.shrink_to_fit();
        return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni,a1,tmp,xi, r=0;
    cin>>ni;
    vector<gg> a;
    for(gg i=0;i<ni;i++)
    {
        cin>>xi;
        a.push_back(xi);
    }
    if(ni==2)
    {
        vector<gg> b;
       for(gg i=1;i<(a[1]-a[0]);i++)
        {
            if((a[1]-a[0])%i==0)
            {
                b.push_back(i);
            }
        } 
        for(auto & i: b)
        r=b.size();
        b.shrink_to_fit();
        cout<<r;
    }
    if(ni>2)
    {
         vector<gg> b;
        for(gg i=0;i<ni-1;i++)
        {
            r+=p(a[i+1]-a[i]);
        }
        for(gg i=0;i<ni;i++)
        {
            if(a[ni-1]-a[0]%i==0)
            {
                 b.push_back(i);
            }
        }
        if(b.                                                           )
       cout<<r;                            
       /*for(gg i=1;i<ni-1;i++)
       {
           tmp=a[i+1]-a[1];
           r+=p(tmp);
       }
       for(gg i=0;i<ni;i++)
       {
           tmp=a[i]
       }*/
        
    }
    
    return 0;
}