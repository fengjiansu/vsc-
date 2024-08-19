#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// �ж��Ƿ�Ϊ����
bool leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ���ñ仯�Ĳ��չ�ʽ����ĳ��ĳ�µ�1�������ڼ�
//����0-6����������Ӧ����-��������
int whatDay(int year, int month) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    return (1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}

// ��ӡĳ��ĳ�µ�����
void printMonth(int year, int month) {
    // ÿ�µ�����
    vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYear(year)) {
        daysInMonth[2] = 29;  // ����2����29��
    }

    // ��ӡ����ͷ
    cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;

    // �������1�������ڼ�
    int startDay = whatDay(year, month);

    // ��ӡ��������
    int currentDay = 1;
    for (int i = 0; i < startDay; ++i) {
        cout << "     ";  // ��ӡ�ո�
    }
    while (currentDay <= daysInMonth[month]) {
        //Ӱ����һ������������ֶο�� ������������ո�
        cout << setw(3) << currentDay << "  ";
        if ((startDay + currentDay) % 7 == 0) {
            cout << endl;  // ÿ�ܻ���
        }
        ++currentDay;
    }
    cout << endl;
}

int main() {
    int year, month;
    cout << "��������ݺ��·ݣ��� 2024 6����";
    cin >> year >> month;
    printMonth(year, month);
    return 0;
}
