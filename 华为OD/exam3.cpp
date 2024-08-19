#include <bits/stdc++.h>
using namespace std;


int fun(int i, int j, vector<vector<int>> &matrix)
{
    int res, l, t;
    int l_anth, t_anth,l_r,t_r;

    res = 0;
    if (i == 0 && j == 0)
    {
        return res;
    }
    if (i > 0)
    {
        l_r = 1;
        l_anth = matrix[i - 1][j];
        for(l = i - 2; l >= 0; l--)
        {
            if (l_anth >= matrix[i][j])
            {
                break;
                
            }
            if (matrix[l][j] > l_anth)
            {
                l_r++;
                l_anth = matrix[l][j];
            }
        }
    }

    if (j > 0)
    {
        t_r =  1;
        t_anth = matrix[i][j - 1];
        for(t = j - 2; t >= 0; t--)
        {
            if (t_anth >= matrix[i][t])
            {
                break;
            }
            if (matrix[i][t] > t_anth)
            {
                t_r++;
                t_anth = matrix[i][t];
            }
        }
    }

    return l_r+t_r;
}

int main()
{
    int tow, col, a, num;
    vector<vector<int>> matrix;
    vector<int> res;
    cin >> tow >> col;

    for(int i = 0; i < tow; i++)
    {
        vector<int> tow;
        for(int j = 0; j < col; j++)
        {
            cin >> a;
            tow.push_back(a);
        }
        matrix.push_back(tow);
    }

    for(int i = 0; i < tow; i++)
    {
        for(int j = 0; j < col; j++)
        {
            num = fun(i, j, matrix);
            // cout << "i " << i << " j " << j << endl;
            res.push_back(num);
        }
    }
    // num = fun(0, 1, matrix);

    // cout << tow << " " << col << endl;
    for(auto &it
        : res)
    {
        cout << it << " ";
    }

    return 0;
}