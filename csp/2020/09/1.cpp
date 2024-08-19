#include<bits/stdc++.h>
using namespace std;
using gg = long long;
constexpr gg INF = 2e18;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    array<int,3> a;
int max=0;
    vector<double> d;
    double t;
    map<int,array<int,2>> r;
    cin>>n>>r[0][0]>>r[0][1];
  for(int i=0;i<n;i++)
{
     cin>>r[i+1][0]>>r[i+1][1];
    d.push_back(sqrt(pow(r[0][0]-r[i+1][0],2)+pow(r[0][1]-r[i+1][1],2)));   

}

for(int j=0;j<3;j++)
{
    int i=min_element(d.begin(),d.end())-d.begin();
a.at(j)=i;
d[i]=INF;
}
for(auto& i :a)
{
    cout<<i+1<<endl;
}
return 0;
}