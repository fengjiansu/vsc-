#include <iostream>
#include <unordered_map>

using namespace std;
int main() {
    unordered_map<string, string> phonebook;

    // 添加数据
    phonebook["xiao li"] = "123-4567";
    phonebook["li hua"] = "234-5678";
    phonebook["zhang san"] = "345-6789";

    // 查找电话号码
    string name;
    cout << "请输入要查找的名字：";
    cin >> name;
    
    if (phonebook.find(name) != phonebook.end()) {
        cout << name << "的电话号码是 " << phonebook[name] << endl;
    } else {
        cout << name << "不在通讯录中。" << endl;
    }

    return 0;
}
