#include<bits/stdc++.h>
using namespace std;

long long dp[20][2][2];
long long dp_ll(int cur,int pre,int pre_pre ,bool limit,vector<int>& num_digit)
{
    if(cur==-1)
        return 1;
    if(dp[cur][pre][pre_pre]!= -1 && (!limit))
        return dp[cur][pre][pre_pre];
    long long count = 0;
    int cur_max = limit ? num_digit[cur] : 1;
    for (int i = 0 ; i <= cur_max; i++)
    {
        if(pre_pre ==1&&pre == 0&&i==1) continue;
        count += dp_ll(cur - 1, i, pre, limit && i == num_digit[cur],num_digit);
       
        
    }
    if(!limit)
        dp[cur][pre][pre_pre] = count;
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
    /* for(auto & it :num_digit)
    {
        cout << it << " ";
    } */
    memset(dp, -1, sizeof(dp));
    return dp_ll(num_digit.size()-1, -1, -1,true,num_digit);
}
int main()
{
    long long l, r;
    cin >> l >> r;
    //cout<<solve(r);
    cout <<solve(r)<<" "<<solve(l-1)<<" "<< solve(r) - solve(l - 1)<<endl;
    return 0;
}