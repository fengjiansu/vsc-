#include <iostream>
#include <unordered_map>

using namespace std;
int main() {
    unordered_map<string, string> phonebook;

    // �������
    phonebook["xiao li"] = "123-4567";
    phonebook["li hua"] = "234-5678";
    phonebook["zhang san"] = "345-6789";

    // ���ҵ绰����
    string name;
    cout << "������Ҫ���ҵ����֣�";
    cin >> name;
    
    if (phonebook.find(name) != phonebook.end()) {
        cout << name << "�ĵ绰������ " << phonebook[name] << endl;
    } else {
        cout << name << "����ͨѶ¼�С�" << endl;
    }

    return 0;
}
