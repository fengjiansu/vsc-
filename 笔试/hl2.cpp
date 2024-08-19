#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void deleteChar(string &s, char a)
{
    auto pos = s.find(a);
    if (pos != string::npos)
    {
        s.erase(pos, 1);
        cout << s << endl;
    }
    else
    {
        cout << "Not exist" << endl;
    }
}

void insertChar(string &s, char a1, char a2)
{
    auto pos = s.find_last_of(a1);
    if (pos != string::npos)
    {
        s.insert(pos, 1, a2);
        cout << s << endl;
    }
    else
    {
        cout << "Not exist" << endl;
    }
}

void replaceChar(string &s, char a1, char a2)
{
    size_t pos = 0;
    if ((pos = s.find(a1, pos)) == string::npos)
    {
        cout << "Not exist" << endl;
        return;
    }
    while ((pos = s.find(a1, pos)) != string::npos)
    {
        s[pos] = a2;
        pos++;
    }
    cout << s << endl;
}

int main()
{
    string original, command;
    getline(cin, original, '.');
    getline(cin, command);

    if (command.empty())
    {
        cout << original << endl;
        return 0;
    }

    char action = command[0];
    char a1 = command[2];
    char a2 = command[4];

    switch (action)
    {
    case 'D':
        deleteChar(original, a1);
        break;
    case 'I':
        insertChar(original, a1, a2);
        break;
    case 'R':
        replaceChar(original, a1, a2);
        break;
    default:
        break;
    }

}
