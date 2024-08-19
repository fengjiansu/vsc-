#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// 判断是否为闰年
bool leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 采用变化的蔡勒公式计算某年某月的1号是星期几
//返回0-6的整数，对应星期-到星期日
int whatDay(int year, int month) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    return (1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
}

// 打印某年某月的日历
void printMonth(int year, int month) {
    // 每月的天数
    vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leapYear(year)) {
        daysInMonth[2] = 29;  // 闰年2月有29天
    }

    // 打印日历头
    cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;

    // 计算该月1号是星期几
    int startDay = whatDay(year, month);

    // 打印日历内容
    int currentDay = 1;
    for (int i = 0; i < startDay; ++i) {
        cout << "     ";  // 打印空格
    }
    while (currentDay <= daysInMonth[month]) {
        //影响下一个输出操作的字段宽度 不足在左侧填充空格
        cout << setw(3) << currentDay << "  ";
        if ((startDay + currentDay) % 7 == 0) {
            cout << endl;  // 每周换行
        }
        ++currentDay;
    }
    cout << endl;
}

int main() {
    int year, month;
    cout << "请输入年份和月份（如 2024 6）：";
    cin >> year >> month;
    printMonth(year, month);
    return 0;
}
