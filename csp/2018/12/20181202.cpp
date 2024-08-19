#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ri,yi,gi,ni,ki,ti,r=0;
    cin>>ri>>yi>>gi;
    cin>>ni;
    while(ni--)
    {
        cin>>ki>>ti;
        if(ki==0)
        {
            r+=ti;
        }
        else if(ki==1)
        {
            if(r<=ti)
            {
                r+=ti;
            }
            else 
            {
                r
            }

        }
        else if(ki==2)
        {
            r+=ti+ri;
        }
        else if(ki==3)
        {

        }
    }
    cout<<r;
    return 0;
   
}