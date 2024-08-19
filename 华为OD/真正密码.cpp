#include <bits/stdc++.h>
using namespace std;

vector<string> get_substr(const string &word)
{
    vector<string> res;
    for (int i = 0; i < word.size(); i++)
    {
        res.push_back(word.substr(0, i + 1));
    }
    return res;
}

string get_password(set<string> &dict)
{
    set<string> password;
    bool isPass;
    int length;
    length = 0;
    // max = 0;
    vector<string> substr;
    for (auto &word : dict)
    {

        if (word.size() >= length)
        {
            substr = get_substr(word);
            isPass = true;
            for (auto &str : substr)
            {
                if (!dict.count(str))
                {
                    isPass = false;
                }
            }
            if (isPass)
            {
                if (word.size() > length)
                {
                    password.clear();
                }
                password.insert(word);
                length = word.size();
            }
        }
    }
    //cout << password.size()<<" "<<length;
    return *(password.rbegin());
}
int main()
{
    set<string> dict;
    // set<string> test;
    string word;

    while (cin >> word)
    {
        dict.insert(word);
        if (cin.get() == '\n')
            break;
    }

    cout << get_password(dict);

    return 0;
}