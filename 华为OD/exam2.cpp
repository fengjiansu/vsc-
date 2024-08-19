#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    ptrdiff_t length;
    string str;
    vector<string> num ;
    vector<string> sea;
    multiset<string> dict;
    cin >> n;
    length = -1;
    for (int i = 0; i < n;i++)
    {
        getline(cin, str);
        num.push_back(str);
        dict.insert(str);
        if(dict.count(str)>1)
        {
            sea.push_back(str);
        }
    }
    for(auto str:sea)
    {
        length = max(length,num.)
    }
    cout << length +1<< endl;
    return 0;
}