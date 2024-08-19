#include <iostream>
#include <unordered_map>
using gg = long long;
using namespace std;

int main()
{
    gg a, b, c, d;
    cin >> a >> b >> c >> d;
    gg count = 0;
    if (a > 0 && b > 0 && c > 0 && d > 0)
    {
        cout << count;
      	return 0;
    }
    if (a < 0 && b < 0 && c < 0 && d < 0)
    {
        cout << count;
       return 0;
    }
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
        gg p = 1000;
        count = p * p * p * p;
        cout << count;
      	return 0;
    }
    unordered_map<gg, gg> sum_count;

    
    for (gg x1 = 1; x1 <= 1000; ++x1)
    {
        for (gg x2 = 1; x2 <= 1000; ++x2)
        {
            gg sum1 = a * x1 + b * x2;
            sum_count[sum1]++; // 访问不存在的键，自动初始化该键对应的值为0
        }
    }

    for (gg x3 = 1; x3 <= 1000; ++x3)
    {
        for (gg x4 = 1; x4 <= 1000; ++x4)
        {
            gg sum2 = c * x3 + d * x4;
            if (sum_count.find(-sum2) != sum_count.end())
            {
                count += sum_count[-sum2];
            }
        }
    }

    cout << count;

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count = 0;

    // 枚举所有 (x1, x2, x3, x4) 组合
    for (int x1 = 1; x1 <= 1000; ++x1) {
        for (int x2 = 1; x2 <= 1000; ++x2) {
            for (int x3 = 1; x3 <= 1000; ++x3) {
                for (int x4 = 1; x4 <= 1000; ++x4) {
                    if (a * x1 + b * x2 + c * x3 + d * x4 == 0) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}


