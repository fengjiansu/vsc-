#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x = 0;
    int y = 0;
    int val = 0;
    node() {}
    node(int &a, int &b, int &v) : x(a), y(b), val(v) {}
};

void bfs_robot(vector<vector<node>> &matrix,int & i ,int & j, int &res)
{
    queue<node> path;
    node p, q;
    path.push(matrix[i][j]);
    vector<vector<bool>>visited(matrix.size(),vector<bool>(matrix[0].size(),false));
    visited[i][j] = true;
    while (!path.empty())
    {
        p = path.front();
        path.pop();
        if ((p.x - 1) >= 0)
        {
            if (abs(p.val - matrix[p.x - 1][p.y].val) <= 1 && visited[p.x-1][p.y] == false)
            {
                visited[p.x-1][p.y] = true;
                path.push(matrix[p.x - 1][p.y]);
                res++;
                //cout << "p.x-1 " << p.x -1<< "p.y " << p.y  << endl;
            }
        }
        if ((p.x + 1) < matrix.size())
        {
            if (abs(p.val - matrix[p.x + 1][p.y].val) <= 1 &&  visited[p.x+1][p.y] == false)
            {
                visited[p.x+1][p.y] = true;
                path.push(matrix[p.x + 1][p.y]);
                res++;
                //cout <<abs(p.val - matrix[p.x + 1][p.y].val) << " p.x+1 " << p.x+1 << " p.y " << p.y  << endl;
                //cout << p.val <<" x+1de val: "<< matrix[p.x + 1][p.y].val << endl;
            }
        }
        if (p.y - 1 >= 0)
        {
            if (abs(p.val - matrix[p.x][p.y - 1].val) <= 1 &&visited[p.x][p.y-1] == false)
            {
                visited[p.x][p.y-1] = true;
                path.push(matrix[p.x][p.y - 1]);
                res++;
                //cout << "p.x " << p.x << "p.y-1 " << p.y - 1 << endl;
            }
        }
        if (p.y + 1 < matrix[i].size())
        {
            if (abs(p.val - matrix[p.x][p.y + 1].val) <= 1 && visited[p.x][p.y+1] == false)
            {
                visited[p.x][p.y+1] = true;
                path.push(matrix[p.x][p.y + 1]);
                res++;
                //cout << "p.x " << p.x << "p.y+1 " << p.y + 1 << endl;
            }
        }
    }
}

int main()
{
    int m, n, val, res,count;
    cin >> m >> n;
    vector<vector<node>> matrix;
    for (int i = 0; i < m; i++)
    {
        vector<node> row;
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            node p(i, j, val);
            row.push_back(p);
        }
        matrix.push_back(row);
    }
    //cout << matrix[1][0].val<<endl;
    res = 1;
    
    for (int i = 0; i < m;i++)
    {
        
        for (int j = 0; j < n;j++)
        {
            count = 1;
            bfs_robot(matrix,i,j ,count);
            res = max(count, res);
            //cout << "count: "  << endl;
        }  
        //cout << "count: " << count << "res: " << res << endl;
    }    
    cout << res;
    return 0;
}