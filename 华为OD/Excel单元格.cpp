#include <bits/stdc++.h>
using namespace std;

int main()
{

    int r, col,res;
    std::string word,range;
    std::vector<std::pair<std::string,std::pair<int,int>>> formula;
    std::vector<std::vector<int>> matrix;
    std::map<char, int> dict;

    char c = 'A';
    for (int i = 0; i < 24; i++)
    {
        dict.insert(std::make_pair(c, i));
        c++;
    }

    std::cin >> r >> col;
    for (int i = 0; i < r; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < col; j++)
        {
            std::cin >> word;
            if (std::isdigit(word[0]))
            {
                row.push_back(stoi(word));
            }
            else
            {
                row.push_back(0);
                word.erase(0, 1);
                formula.push_back(std::make_pair(word,std::make_pair(i,j)));
            }
        }
        matrix.push_back(row);
    }
    std::cin >> range;

    /* for(auto &row:matrix)
    {
        for(auto & num:row)
        {
            cout << num;
        }
        cout << endl;
    } */
    for(auto & it:formula)
    {
        int a, b;
        auto str = it.first;
        auto index = it.second;
        if(str.find('+')!=str.npos)
        {
            //cout << stoi(str.substr(1, str.find('+') - 1)) <<" "<< dict[str[0]] << endl;
            a = matrix[stoi(str.substr( 1, str.find('+') - 1))-1][dict[str[0]]];
            str.erase(0, str.find('+') + 1);
            //cout << str<<endl;
            b = matrix[stoi(str.substr(1,str.end()-str.begin()))-1][dict[str[0]]];
            //cout << dict[str[0]] << " " << stoi(str.substr(1, str.end() - str.begin()));
            //cout << a + b;
            matrix[index.first][index.second]=a+b;
        }
        else if(str.find('-')!=str.npos)
        {
            a = matrix[stoi(str.substr(1, str.find('-') - 1))][dict[str[0]]];
            str.erase(0, str.find('-') + 1);
            b = matrix[stoi(str.substr(1,str.end()-str.begin()))][dict[str[0]]];
            matrix[index.first][index.second]=a-b;
        }
        else
        {
            matrix[index.first][index.second]= matrix[stoi(str.substr(1,str.end()-str.begin()))][dict[str[0]]];
        }
    }

    int pos = range.find(':');
    //cout << pos;
    std::pair<int, int> begin,end;
    begin.second = dict[range[0]];
    begin.first = stoi(range.substr( 1, pos - 1))-1;
    range.erase(0, pos + 1);
    end.first = stoi(range.substr(1,range.end()-range.begin()))-1;
    end.second= dict[range[0]];
    cout << begin.first <<" "<< begin.second << " "<<end.first <<  " "<<end.second<<endl;

    res = 0;
    for(int i=begin.first;i<=end.first;i++)
    {
        for (int j = begin.first;j<=end.second;j++)
        {
            res += matrix[i][j];
        }
    }
    cout << res;
    return 0;
}