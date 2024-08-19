#include<bits/stdc++.h>
using namespace std;

int main()
{
    int weight_max, people_max, weight,res;
    vector<int> bycle;
    cin >> weight_max >> people_max;
    for (int i = 0; i < people_max;i++)
    {
        cin >> weight;
        bycle.push_back(weight);
    }
    sort(bycle.begin(), bycle.end());

    int left, right;
    left = 0;
    right = bycle.size() - 1;

    res = 0;
    while((right - left+1) >=1)
    {
        if(bycle[left]+bycle[right]>weight_max)
        {
            right--;
            res++;
        }
        else if(bycle[left]+bycle[right]<=weight_max)
        {
            right--;
            left++;
            res++;
        }
    }
    cout << res;
    return 0;
}