#include<bits/stdc++.h>
using namespace std;
bool isPass(int a)
{
    if(a%7==0)
    {
        return true;
    }
    while(a)
    {
        if(a%10==7)
        return true;
        a/=10;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r[4]={0};
    int n;
    cin>>n;
    for(int i=1;i<n+1;i++)
    {
        if(isPass(i))
        {
            r[(i-1)%4]+=1;
            n++;
        }

    }
    for(auto i: r)
    cout<<i<<endl;
    return 0;
}