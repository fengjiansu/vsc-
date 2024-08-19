#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int,int>&a,pair<int,int>&b)const
    {
        return a.second > b.second;
    }
};

void sort_map_byValue(map<int,int>& dict,vector<pair<int,int>> & res)
{
    for(auto &it:dict)
    {
        res.push_back(it);
    }
    sort(res.begin(), res.end(), cmp());
}
int main()
{
    vector<int> car;
    map<int, int> colour_num;
    vector<pair<int, int>> res;
    int colour,length,max;
    while(cin>>colour)
    {
        car.push_back(colour);
        if(colour_num.count(colour))
        {
            colour_num[colour]++;
        }
        else
        {
            colour_num[colour] = 1;
        }
         if(cin.get() == '\n')
            break;
    }
    cin >> length;

    int left = 0;
    int right = length + left - 1;
    max = 0;

    while(right<car.size())
    {
        for (int i = right+1; i <car.size();i++)
        {
            colour_num[car[i]]--; 
        }
        sort_map_byValue(colour_num, res);
        if(res[0].second>max)
        {
            max = res[0].second;
        }

        for (int i = right+1; i <car.size();i++)
        {
            colour_num[car[i]]++; 
        }
        colour_num[car[left]]--;
        left++;
        right = length + left - 1;
    }
    cout << max << endl;
    return 0;
}
