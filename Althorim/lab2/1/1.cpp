#include <iostream>
#include <algorithm>
using namespace std;
template <class Type>
inline void Swap(Type &a, Type &b)
{
    Type temp = a;
    a = b;
    b = temp;
}
template <class Type>
Type Partition(Type a[], int p, int r, Type x)
{
    int i = p, j = r + 1;
    //��С��x��Ԫ�ؽ�����������򣬴��ڵ��ұ�
    while (true)
    {
        while (a[++i] < x && i < r)
            ;
        while (a[--j] > x)
            ;
        if (i >= j)
            break;
        Swap(a[i], a[j]);
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}
template <class Type>
Type Select(Type a[], int p, int r, int k)
{
    if (r - p < 75)
    {
        sort(a + p, a + r);
        return a[p + k - 1];
    }
        for (int i = 0; i <= (r - p - 4) / 5; i++)
        {
            //��a[p+5*i]��a[p+5*i+4]�ĵ���СԪ����a[p+i]����λ��
            Type x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
            //����λ������λ����r-p-4��n-5
            int index = Partition(a, p, r, x), j = index - p - 1;
            if (k <= j)
                return Select(a, p, index, k);
            else
                return Select(a, index + 1, r, k - j);
        }
}
int main()
{
    int a[10] = {5, 3, 4, 1, 2, 6, 9, 7, 8, 10};
    int r = 0;
    r = Select(a, 0, 10, 7);
    printf("%d", r);
    return 0;
}