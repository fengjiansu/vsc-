#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    ptrdiff_t length;
    //vector<int> num;
    unordered_multiset<int> num;

    length = -1;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> m;
        num.insert(m);
        if(num.count(m)>1)
        {
            auto ret = num.equal_range(m);
            //cout << distance(ret.first, ret.second) + 1<<" ";
            length=max(length,distance(ret.first, ret.second)+1);
        }
        //cout << endl;
    }
    //for(auto & )
    cout << length;
    return 0;
}