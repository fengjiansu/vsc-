#include<bits/stdc++.h>
using namespace std;
//得到一个5行3列的数组
//由vector实现的二维数组，可以通过resize()的形式改变行、列值
int main()
{
//得到一个5行3列的数组
//由vector实现的二维数组，可以通过resize()的形式改变行、列值
int i,j;
vector<vector<int>> array(5);
for (i = 0; i < array.size(); i++)
    array[i].resize(3);

for(i = 0; i < array.size(); i++)
{
    for (j = 0; j < array[0].size();j++)
    {
        array[i][j] = (i+1)*(j+1);
    }
}
if((1>0 )^ (-1>0))
{
    cout<<"no";
}

}