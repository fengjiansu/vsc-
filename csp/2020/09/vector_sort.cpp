#include<bits/stdc++.h>
using namespace std;
//按照二维数组第一列的大小对每个一维数组升序排序，
//如何第一列相同时，按照第二列大小对每行的数组降序排序
bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else return a[1]>b[1];
}
int main()
{
    vector<vector<int> >a(6);
    int x;
    for(int i=0;i<6;i++){
        for(int j=0;j<2;j++){
            cin>>x;
            a[i].push_back(x);
        }
    }
    cout<<endl;
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<6;i++){
        for(int j=0;j<2;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}