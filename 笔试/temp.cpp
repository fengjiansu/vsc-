/* 
    有一个目标大矩形和多个小矩形，矩型定义如下：
struct Rect {
int id；// 矩形的唯一编号
int x； // 矩形横向起始位置
int y； // 矩形纵向起始位置
int w；// 矩形宽度
int h；// 矩形高度
};

已知大小矩形各自的的长和宽w，h
要求把不同尺寸的小矩形，放到大矩形中， 要求小矩形之间不能重叠，
计算这些小矩形在大矩形中的x y 
实现如下函数：
std::vector<Rect>unionRect(const Rect& bigrect, const  std::vector<Rect>& smallrects);
返回值为能够填充到大矩形中的小矩形集合。 请填写其中每个小矩形的位置，大小，id信息

 */


#include <bits/stdc++.h>

using namespace std;

struct Rect {
    int id;     // 矩形的唯一编号
    int x;        // 矩形横向起始位置
    int y;      // 矩形纵向起始位置
    int w;      // 矩形宽度
    int h;      // 矩形高度
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
