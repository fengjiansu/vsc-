#include<bits/stdc++.h>
using namespace std;
using gg = long long;
int main()
{
 ios::sync_with_stdio(false);
    cin.tie(0);
 gg m=0;
gg k=0;
cin>>m;
long y[m],r[m],t[m],p[m];
for(gg i=0;i<m;i++)
{
 cin>>y[i]>>r[i];
  t[i]=y[i];
p[i]=0;
}
for(gg i=0;i<m;i++)
{
  for(gg j=0;j<m;j++)
{
    if(y[j]>=t[i]&&r[j]==1)
    p[i]+=1;
    if(y[j]<t[i]&&r[j]==0)
     p[i]+=1;
}
}

for(gg i=0;i<m-1;i++)
{
 if(p[i]<p[i+1])
   {
      k=i+1;
   }
  else if(p[i]==p[i+1]&&y[i]<y[i+1])
  {
    k=i+1;
  }
}
cout<<y[k];
return 0;
}