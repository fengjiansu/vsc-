#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //字典里的单词即为物品，完全背包，物品可多次使用
    //dp[j]代表容量为j的背包能否被装满
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.length()+1,false);
        dp[0] = true;
        for(int j=0;j<s.length()+1;j++)
        {
            for(int i=0;i<wordDict.size();i++)
            {
                if(j>=wordDict[i].size())
                dp[j] = dp[j]||(dp[j-wordDict[i].size()]&&s.substr(j-wordDict[i].size(),wordDict[i].size())==wordDict[i])||(!dp[j-wordDict[i].size()]&&s.substr(0,j)==wordDict[i]);
            }
        }
        return dp[s.length()];
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1};
    int target = 1;
    string str = {"applepenapple"};
    vector<string> dict = {"apple", "pen"};
    cout << s.wordBreak(str,dict) << endl;
}