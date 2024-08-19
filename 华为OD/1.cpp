#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> num, int index, int m, vector<int> &group, vector<vector<int>> &res)
{
    if (group.size() == m)
    {
        res.push_back(group);
        return;
    }

    for (int i = index; i < num.size(); i++)
    {
        group.push_back(num[i]);
        dfs(num, i + 1, m, group, res);
        group.pop_back();
    }
}
void combine(vector<int> num, int m, vector<vector<int>> &res) // C_n^m
{
    vector<int> group;
    dfs(num, 0, m, group, res);
}
int main()
{
    string str, temp;
    int num = 0;
    int c1n, c2n = 0;
    vector<int> a;
    vector<vector<int>> res;
    vector<int> group_c1;
    vector<int> group_c2;

    getline(cin, str);
    cin >> num;
    for (auto &i : str)
    {
        if (isdigit(i))
        {
            a.push_back(i-'0');
        }
    }

    for (auto &i : a)
    {
        
        if (i >= 0 && i <= 3)
        {
            group_c1.push_back(i);
        }
        else
        {
            group_c2.push_back(i);
        }
    }

    c1n = group_c1.size();
    c2n = group_c2.size();


    if (num == 1)
    {
        if (c1n == 1 || c2n == 1)
        {
            if (c1n == 1)
            {
                res.push_back(group_c1);
            }
            if (c2n == 1)
            {
                res.push_back(group_c2);
            }
        }
        else if (c1n == 3 || c2n == 3)
        {
            if (c1n == 3)
            {
                combine(group_c1, 1, res);
            }
            if (c2n == 3)
            {
                combine(group_c2, 1, res);
            }
        }
        else if (c1n == 2 || c2n == 2)
        {
            if (c1n == 2)
            {
                combine(group_c1, 1, res);
            }
            if (c2n == 2)
            {
                combine(group_c2, 1, res);
            }
        }
        else if (c1n == 4 || c2n == 4)
        {
            if (c1n == 4)
            {
                combine(group_c1, 1, res);
            }
            if (c2n == 4)
            {
                combine(group_c2, 1, res);
            }
        }
    }
    else if (num == 2)
    {
        if (c1n == 2 || c2n == 2)
        {
            if (c1n == 2)
            {

                res.push_back(group_c1);
            }
            if (c2n == 2)
            {

                res.push_back(group_c2);
            }
        }
         else if(c1n == 4|| c2n ==4)
        {
            if (c1n == 4)
            {
                combine(group_c1, 2, res);
            }
            if (c2n == 4)
            {
                combine(group_c2, 2, res);
            }
        }
        else
        {
                if (c1n == 3)
            {
                combine(group_c1, 2, res);
            }
            if (c2n == 3)
            {
                combine(group_c2, 2, res);
            }
        }
    }
    else if (num == 4)
    {
        if (c1n == 4)
        {
            res.push_back(group_c1);
        }
        if (c2n == 4)
        {

            res.push_back(group_c2);
        }
    }
    else if (num == 8)
    {
        if (c1n + c2n == 8)
        {
            group_c1.insert(group_c1.end(), group_c2.begin(), group_c2.end());
            res.push_back(group_c1);
        }
    }

    cout << '[';
    for (int i = 0; i < res.size(); i++)
    {
        cout << '[';
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
            if (res[i].size() != 0 && j!=res[i].size()-1)
            {
                cout << ',';
            }
        }
        cout << ']';
        if (i < res.size() - 1)
        {
            cout << ',';
        }
    }
    cout << ']' << endl;
    return 0;
}