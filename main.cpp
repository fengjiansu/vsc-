#include <bits/stdc++.h>

using namespace std;
map<char,int> m;
string s;
string x="";//数字字符串
stack<int> num;//数字栈
stack<char> op;//运算符栈

int cal(int x,int y,char ch){//四则运算
    switch(ch){
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            return x/y;
    }
    return 0;
}
int main(){
    m['+']=m['-']=1;//优先级
    m['*']=m['/']=2;
    m['=']=0;
    cin >> s;
    s+='=';//添加个优先级为0的等号
    int len=s.size();
    for(int i=0;i<len;i++){//遍历
        if(isdigit(s[i])){
            x+=s[i];
        }else{
            if(x.size()){//对数字进行入数字栈
                int sum=0;
                for(int i=0;i<x.size();i++){
                    sum=sum*10+x[i]-'0';
                }
                num.push(sum);
            }
            x="";
            if(s[i]=='('||s[i]=='{'||s[i]=='['){//如果为左括号，入运算符栈
                op.push(s[i]);
            }else if(s[i]==')'){//如果是右括号，则利用匹配左括号循环运算
                while(!op.empty()&&op.top()!='('){
                    int y=num.top();
                    num.pop();
                    int x=num.top();
                    num.pop();
                    char ch=op.top();
                    op.pop();
                    num.push(cal(x,y,ch));
                }
                op.pop();
            }else if(s[i]=='}'){//同理
                while(!op.empty()&&op.top()!='{'){
                    int y=num.top();
                    num.pop();
                    int x=num.top();
                    num.pop();
                    char ch=op.top();
                    op.pop();
                    num.push(cal(x,y,ch));
                }
                op.pop();
            }else if(s[i]==']'){//同理
                while(!op.empty()&&op.top()!='['){
                    int y=num.top();
                    num.pop();
                    int x=num.top();
                    num.pop();
                    char ch=op.top();
                    op.pop();
                    num.push(cal(x,y,ch));
                }
                op.pop();
            }else{
                if(s[i]=='-'&&(s[i-1]=='('||s[i-1]=='['||s[i-1]=='{')){//如果是负数，前面加个0
                    num.push(0);
                }
                while(!op.empty()&&m[s[i]]<=m[op.top()]){//利用优先级进行循环计算
                    int y=num.top();
                    num.pop();
                    int x=num.top();
                    num.pop();
                    char ch=op.top();
                    op.pop();
                    num.push(cal(x,y,ch));
                }
                op.push(s[i]);
            }
        }
    }
    cout << num.top() << endl;//输出数字栈的最后一个数字
    return 0;
}