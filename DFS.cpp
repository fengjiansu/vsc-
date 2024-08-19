#include <bits/stdc++.h>
using namespace std;

void dfs_permute_swap(vector<int> num, int index, int m, vector<int> &group, vector<vector<int>> &res)
{
    if (group.size()==m)
    {
        res.push_back(group);
        return;
    }

    for (int i = index; i < num.size(); i++)
    {
        group.push_back(num[i]);
        swap(num[index], num[i]);
        dfs_permute_swap(num, index+1, m, group, res);
        swap(num[index], num[i]);
        group.pop_back();
    }
}
void permute_swap(vector<int> num,int m,vector<vector<int>> &res) // P_n^m
{
   vector<int> group;
   
   dfs_permute_swap(num, 0, m, group, res);
   sort(res.begin(),res.end()); //顺序保存

}
void dfs_permute_visited(vector<int> num, int index, int m, vector<bool>& visited ,vector<int> &group, vector<vector<int>> &res)
{
    if (group.size()==m)
    {
        res.push_back(group);
        return;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if(!visited[i])
        {
           visited[i] = true;
           group.push_back(num[i]);
           dfs_permute_visited(num, index + 1, m,visited, group, res);
           group.pop_back();
           visited[i] = false;
        }
        
    }
}
//按照字典序保存所有情况
void permute_visited(vector<int> num,int m,vector<vector<int>> &res) // P_n^m
{
   vector<int> group;
   vector<bool> visited(num.size(), false);                                                                                                                                                                                                                                                                                                          
   dfs_permute_visited(num, 0, m,visited, group, res);

}

void dfs_combine(vector<int> num, int index, int m, vector<int> &group, vector<vector<int>> &res)
{
    if (group.size() == m)
    {
        res.push_back(group);
        return;
    }

    for (int i = index; i < num.size(); i++)
    {
        group.push_back(num[i]);
        dfs_combine(num, i+1, m, group, res);
        group.pop_back();
    }
}
void combine(vector<int> num, int m, vector<vector<int>> &res) // C_n^m
{
    vector<int> group;
    dfs_combine(num, 0, m, group, res);
}

vector<pair<int,int>> temp_path;
vector<pair<int,int>> best_path;
void dfs_maze(vector<vector <int>>& maze,int i,int j)
{
   pair<int,int> p(i, j);

   if(i < 0 || i>= maze.size() || j < 0 || j>= maze[0].size() || maze[i][j] == 1)
   {
      return;
   }

   maze[i][j] = 1; //状态转移
   temp_path.push_back(p);
   if( i == maze.size()-1 && j == maze[0].size()-1)
   {
      best_path = temp_path;
   }
   dfs_maze(maze, i-1,j);
   dfs_maze(maze,i+1,j);
   dfs_maze(maze, i,j-1);
   dfs_maze(maze, i, j+1);
   maze[i][j] = 0;
   temp_path.pop_back();
}  
int main() {
    int n,m;
   vector<int> num = {1,2,3,4,5};
   vector<vector<int>> res;
   permute_swap(num, 5, res);
   for(auto it: res)
   {
      for(auto i:it)
      {
         cout << i << " ";
      }
      cout << endl;
   }
   return 0;



}
// 64 位输出请用 printf("%lld")