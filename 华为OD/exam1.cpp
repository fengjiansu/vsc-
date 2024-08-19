#include<bits/stdc++.h>
using namespace std;

int main()
{

    int a, k;
    double x,sum,cha;
    double l, r;
    vector<int> num;

    sum = 0;
    while(cin>>a)
    {
        if(a<0)
        {
            a = 0;
        }
        if(a>255)
        {
            a = 255;
        }
        sum += a;
        num.push_back(a);
        if(cin.get()=='\n')
        {
            break;
        }
    }

    sort(num.begin(), num.end());

    x = sum / num.size();


    cha = fabs(x - 128);
    l = 128 - cha;
    r = 128 + cha;
    cout << l << " " << r <<" "<<cha<< endl;
    k = 0;
    if(x>128)
    {
        while(r>128)
        {
            r--;
            //cout << r << endl;
            if(fabs(r-128)<=cha)
            {
                //cout << r << " " << endl;
                cha = fabs(r-128);
                k = r - x;
            }
        }    
    }
    else if(x<128)
    {
        while(l<128)
        {
            l++;
            if(fabs(l-128)<=cha)
            {
                k = l-x;
            }
        }
    }
    else
    {
        k = 0;
    }

    cout << k << endl;
    return 0;

}