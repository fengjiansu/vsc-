/* 
    ��һ��Ŀ�����κͶ��С���Σ����Ͷ������£�
struct Rect {
int id��// ���ε�Ψһ���
int x�� // ���κ�����ʼλ��
int y�� // ����������ʼλ��
int w��// ���ο��
int h��// ���θ߶�
};

��֪��С���θ��Եĵĳ��Ϳ�w��h
Ҫ��Ѳ�ͬ�ߴ��С���Σ��ŵ�������У� Ҫ��С����֮�䲻���ص���
������ЩС�����ڴ�����е�x y 
ʵ�����º�����
std::vector<Rect>unionRect(const Rect& bigrect, const  std::vector<Rect>& smallrects);
����ֵΪ�ܹ���䵽������е�С���μ��ϡ� ����д����ÿ��С���ε�λ�ã���С��id��Ϣ

 */


#include <bits/stdc++.h>

using namespace std;

struct Rect {
    int id;     // ���ε�Ψһ���
    int x;        // ���κ�����ʼλ��
    int y;      // ����������ʼλ��
    int w;      // ���ο��
    int h;      // ���θ߶�
};

bool isFalse(const Rect& rect1,const Rect & rect2)
{
    pair<int, int> start1, start2,end1,end2;

    start1 = make_pair(rect1.x, rect1.y);
    start2 = make_pair(rect2.x, rect2.y);

    end1 = make_pair(rect1.x+rect1.w, rect1.y+rect1.h);
    end2 = make_pair(rect2.x+rect2.w, rect2.y+rect2.h);

    return !(start1 >= end2 || start2 >= end1);
}
std::vector<Rect>unionRect(const Rect& bigrect, const  std::vector<Rect>& smallrects)
{
    vector<Rect> result;
    bool isTrue = true;

    for(const Rect& smallrect: smallrects)
    {
        if(smallrect.w > bigrect.w || smallrect.h > bigrect.h)
        {
            continue;
        }

        if(isTrue)
        {
            Rect placeddRect;
            placeddRect.id = smallrect.id;
            placeddRect.w = smallrect.w;
            

        }

    }
}
int main()
{

    
    return 0;
}
