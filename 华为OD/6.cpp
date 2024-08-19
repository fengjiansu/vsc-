#include<bits/stdc++.h>
using namespace std;

void dfs_red(const int & vertexnum,vector<vector<int>> edges_matrix,int index,bool & dye,vector<bool>& red,vector<vector<bool>> &res)
{
    if( dye)
    {
        res.push_back(red);
        return;
    }
    for (int i = index; i < vertexnum;i++)
    {
        for (int j = 0; j < vertexnum;j++)
        {
            if(edges_matrix[i][j]==1||edges_matrix[j][i] == 1)
            {
                if(red[j] == true)
                {
                    dye = false;
                }
            }
        }
        if(dye)
        {
            red[i] = true;
        }
        dfs_red(vertexnum,edges_matrix,index+1,dye,red, res);
        red[i] = false;
        
    }
}
void dfs_graph_red(const int & vertexnum,vector<vector<int>> edges_matrix,vector<vector<bool>> &res)
{
    vector<bool> red(vertexnum,false);
    bool dye = true;//做了一次染色
    dfs_red(vertexnum,edges_matrix,0,dye,red, res);
}
vector<vector<int>> get_edges_matrix(vector<pair<int,int>> &edges,int vertexnum)
{
    vector<vector<int>> edges_matrix(vertexnum,vector<int>(vertexnum,0));
    for(auto & edge:edges)
    {
        edges_matrix[(edge.first-1)][(edge.second-1)] = 1;
        edges_matrix[(edge.second-1)][(edge.first-1)] = 1;
    }
    return edges_matrix;
}
int main()
{
    int vertexnum, edgenum;
    int a, b;
    vector<pair<int,int>> edges;
    vector<vector<bool>> res;
    bool isRed = true;
    cin >> vertexnum >> edgenum;
    vector<vector<int>> edges_matrix;
    for (int i = 0; i < edgenum;i++)
    {
        cin >> a>>b;
        edges.push_back(make_pair(a, b));
    }
    edges_matrix = get_edges_matrix(edges, vertexnum);
    dfs_graph_red(vertexnum, edges_matrix, res);
    cout << res.size()<<endl;
    for (int i = 0; i < res.size();i++)
    {
        for (int j = 0; j < res[i].size();j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    } 

        return 0;
}