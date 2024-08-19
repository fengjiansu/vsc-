#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int x,y,th1,th2,th3;
    char t;
    int result;
    vector<vector<int>> r(n);
    vector<vector<int>> a(n);
    vector<bool> flag(m);
    for(int i=0;i<m;i++)
    {
        flag[i]=true;
    }
for (int i = 0; i < a.size(); i++)
    a[i].resize(3);
    vector<vector<int>> b(m);
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>t;
        a[i][0]=x;
        a[i][1]=y;
        a[i][2]=t;
    }
  for(int i=0;i<m;i++)
    {
        cin>>th1>>th2>>th3;
        b[i].push_back(th1);
        b[i].push_back(th2);
        b[i].push_back(th3);
    }
for(int j=0;j<m;j++)
{
    for(int i=0;i<n;i++)
    {
        if(a[i][2]=='A')
        {
            if((b[j][0]+a[i][0]*b[j][1]+a[i][1]*b[j][2]>0)^(b[j][0]+a[i][0]*b[j][1]+a[i][1]*b[j][2]>0))
            
        }
        else if(a[i][2]=='B')
        {
           
        }
    }
   
    for(int i=0;i<r[0].size()-1;i++)
    {
        result=r[0][i];
        result=r[0][i+1]^result;
        if(result==1)
        {
            flag[m]=false;
        }
    }
   
   
   
}
    for(int i=0;i<m;i++)
    {
        if(flag[i]==true)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
}