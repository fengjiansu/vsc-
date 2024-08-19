#include<bits/stdc++.h>
using namespace std;

long long dp[20][2];
long long dp_ll(int cur,int pre,int res,bool lead,bool limit,vector<int>& num_digit)
{
    if(cur==-1)
        return -1;
    if(dp[cur][pre][res]!= -1 && (!limit)&&(!lead))
        return dp[cur][pre];
    long long count = 0;
    int cur_max = limit ? num_digit[cur] : 9; //最高位限制
    for (int i = 0 ; i <= cur_max; i++)
    {

        if((!i)&&lead)
            count += dp_ll(cur, pre, res, i == res && limit);
        else if(i&&lead)
            count += dp_ll(, lead && i == 0, limit &&i = num_digit[cur]);
    }
    if(!limit&&!lead)
        dp[cur][pre][res] = count;
    return count;
}
long long solve(long long num)
{
    vector<int> num_digit;
    while(num)
    {
        num_digit.push_back(num % 2);
        num /= 2;
    }
    memset(dp, -1, sizeof(dp));
    return dp_ll(num_digit.size(), 0, 0, true, true,num_digit);
}
int main()
{
    long long l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1)<<endl;
    return 0;
}