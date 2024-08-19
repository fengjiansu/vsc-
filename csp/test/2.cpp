#include<bits/stdc++.h>
using namespace std;
using gg = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    gg ni,li,ri,ti,xi;
    gg r=0;
    cin>>ni>>li>>ri>>ti;
    vector<vector<gg>> a(ni);
    gg t=ni;
    while(t--)
    {
        for(gg i=0;i<ni;i++)
        {
            cin>>xi;
            a[i].push_back(xi);
        }
        
    }
    for(gg i=0;i<ni;i++)
    {
        for(gg j=0;j<ni;j++)
        {
            gg tmp=0;
            double c=0;
            for(gg x=i-ri;x<=i+ri;x++)
            {
                if(x>=0&&x<ni)
                {
                    for(gg y=j-ri;y<=j+ri;y++)
                    {
                       if(y>=0&&y<ni)
                       {
                           tmp+=a[x][y];
                           c++;
                       }

                    }
                }
                
            }
            /*cout<<tmp<<" "<<c<<' '<<tmp/c<<endl;*/
            if((tmp/c)<=ti)
                r++;
        }
    }
    cout<<r;
    return 0;
}