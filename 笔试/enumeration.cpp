#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int count = 0;

    // 枚举所有 (x1, x2, x3, x4) 组合
    for (int x1 = 1; x1 <= 1000; ++1)
    {
        for (int x2 = 1; x2 <= 1000; ++x2)
        {
            for (int x3 = 1; x3 <= 1000; ++x3)
            {
                for (int x4 = 1; x4 <= 1000; ++x4)
                {
                    if (a * x1 + b * x2 + c * x3 + d * x4 == 0)
                    {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}