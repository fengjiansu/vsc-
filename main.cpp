#include <bits/stdc++.h>

using namespace std;
map<char,int> m;
string s;
string x="";//�����ַ���
stack<int> num;//����ջ
stack<char> op;//�����ջ

int cal(int x,int y,char ch){//��������
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
    m['+']=m['-']=1;//���ȼ�
    m['*']=m['/']=2;
    m['=']=0;
    cin >> s;
    s+='=';//��Ӹ����ȼ�Ϊ0�ĵȺ�
    int len=s.size();
    for(int i=0;i<len;i++){//����
        if(isdigit(s[i])){
            x+=s[i];
        }else{
            if(x.size()){//�����ֽ���������ջ
                int sum=0;
                for(int i=0;i<x.size();i++){
                    sum=sum*10+x[i]-'0';
                }
                num.push(sum);
            }
            x="";
            if(s[i]=='('||s[i]=='{'||s[i]=='['){//���Ϊ�����ţ��������ջ
                op.push(s[i]);
            }else if(s[i]==')'){//����������ţ�������ƥ��������ѭ������
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
            }else if(s[i]=='}'){//ͬ��
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
            }else if(s[i]==']'){//ͬ��
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
                if(s[i]=='-'&&(s[i-1]=='('||s[i-1]=='['||s[i-1]=='{')){//����Ǹ�����ǰ��Ӹ�0
                    num.push(0);
                }
                while(!op.empty()&&m[s[i]]<=m[op.top()]){//�������ȼ�����ѭ������
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
    cout << num.top() << endl;//�������ջ�����һ������
    return 0;
}