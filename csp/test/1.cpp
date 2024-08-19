#include<bits/stdc++.h>
using namespace std;
using gg = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni,mi,li,t,xi;
    cin>>ni>>mi>>li;
    vector<gg> l(li);
    for(gg i=0;i<li;i++)
    {
        l[i]=0;
    }
    t=ni*mi;;
    
    while(t--)
    {   
        cin>>xi;
        for(gg i=0;i<li;i++)
        {
            if(xi==i)
                l[i]++;
        }
    }
    for(gg i=0;i<li;i++)
    {
        cout<<l[i];
        if(i!=li-1)
            cout<<' ';
    }
    return 0;
}