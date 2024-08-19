#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n,m,t,d,e;
    t=0;
    d=0;
    e=0;
    cin>>n;
    bool flag[n];
    for(gg i=0;i<n;i++)
    {
        flag[i]=false;
    }
    for(gg i=0;i<n;i++)
    {
        gg ai,bi;
        cin>>m>>ai;
      while(--m)
    {
        cin>>bi;
        if(bi<=0)
        {
            ai+=bi;
        }
        else 
        {
            if(ai>bi)
              {
                  flag[i]=true;
              }
            ai=bi;
            
        }

    }
    t+=ai;
    }
    for(auto i: flag)
    {
        if(i)
        d++;
    }
    for(gg i=0;i<n;i++)
    {
        if(flag[i]&&flag[(i+1)%n]&&flag[(i+2)%n])
        e++;
    }
    cout<<t<<" "<<d<<' '<<e;
    return 0;
}