#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    int next;
    ListNode(int v =0,int next = -1):val(v),next(next){}
};
int main()
{
    int addr,nodeNum,val,head_addr,next;
    vector<pair<int,ListNode*>> addr_list;
    cin >> head_addr >> nodeNum;
    for (int i = 0; i < nodeNum;i++)
    {
        cin >> addr >> val >> next;
        ListNode *node = new ListNode(val, next);
        addr_list.push_back(make_pair(addr, node));
    }
    addr = head_addr;
    for (int i = 0; i < nodeNum;i++)
    {
        for (int j = i; j < nodeNum;j++)
        {
            if (addr_list[j].first == addr)
            {
                swap(addr_list[i], addr_list[j]);
            }
        }
        addr = (addr_list[i].second)->next;
        if(addr == -1&& i != nodeNum -1)
        {
            addr_list.erase(addr_list.begin()+i + 1, addr_list.end()- i - 1);
            break;
        }
    }

    int index = addr_list.size() / 2;
    cout << (addr_list[index].second)->val;
    return 0;
}