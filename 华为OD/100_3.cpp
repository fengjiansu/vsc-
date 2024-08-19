#include<bits/stdc++.h>
using namespace std;

void sort_word(string & word)
{
    vector<char> chars;
    for(auto & c: word)
    {
        chars.push_back(c);
    }
    sort(chars.begin(), chars.end());
    for (int i = 0; i < word.size();i++)
    {
        word[i] = chars[i];
    }
}
template <typename T1, typename T2>
struct cmp{
    bool operator()(const pair<T1, T2> &x, const pair<T1, T2> &y) const
    {
        if(x.second > y.second)
        {
            return true;
        }
        else if(x.second < y.second)
        {
            return false;
        }
        else if(x.first.size()<y.first.size())
        {
            return true;
        }
        else if(x.first.size()==y.first.size())
        {
            for (int i = 0; i < x.first.size();i++)
            {
                if(x.first[i]<y.first[i])
                {
                    return true;
                    break;
                }
            }
        }
        else
        {
            return false;
        }

        return false;
    }
};

void sort_map_byValue(map<string,int> & dict,vector<pair<string, int>>& res)
{
    
    for (auto & it :dict)
    {
        res.push_back(it);
    }
    sort(res.begin(), res.end(), cmp<string,int>());
    
}
int main()
{
    string line, word;
    map<string,int> dict;
    vector<pair<string, int>> res;
    stringstream ss;

    getline(cin, line);
    ss.str(line);
    while(ss>>word)
    {
        sort_word(word);
        dict[word]++;
    }
    
    sort_map_byValue(dict,res);

    for (auto  it :res)
    {
        for(int i = 0;i<it.second;i++)
        {
            cout << it.first << " ";
        }
    } 
    

    return 0;
}