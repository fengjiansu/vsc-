#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg n,max,mid,min,x;
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
        mid=(a[n/2-1]+a[n/2])/2;
    }
    else
    {
        mid=a[n/2+1];
    }
    cout<<max<<' '<<mid<<' '<<min;
    return 0;
}