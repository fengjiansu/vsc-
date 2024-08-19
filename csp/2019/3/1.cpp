#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n,max,min,x;
    cin>>n;
    vector<gg>a;
    for(gg i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    max=*max_element(a.begin(),a.end());
    min=*min_element(a.begin(),a.end());
    if(n%2==0)
    {
        if((a[n/2-1]+a[n/2])%2==0)
        {
            cout<<max<<" "<<(a[n/2-1]+a[n/2])/2<<" "<<min;
        }
        else
        {
         cout<<max<<" "<<fixed<<setprecision(1)<<(a[n/2-1]+a[n/2])/2.0<<" "<<min;
        }

    }
    else
    {
         cout<<max<<" "<<a[n/2]<<" "<<min;
    }
    return 0;
}