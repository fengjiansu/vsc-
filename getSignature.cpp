#include<bits/stdc++.h>
#include"./library/md5.h"
using namespace std;

/* 
 * �ͷ�����ǩ�������㷨-C++�汾
     * @param HashMap params ��������������в���������ת��Ϊ�ַ�������
     * @param String secret ǩ����Կ���û�����֤key��
     * @return ǩ��
     * @throws IOException
 */

string key = {"f65eb9c0c81b4fffa097b9cf50932806"};
Public = "HE2304212210281780"
city = "119,123"
params = {
    "location" : city,
    "key": key,

}
string & getSignature(map<string,string> params, string key)
{
    string str;
    for(auto &param:params)
    {
        if(!param.second.empty()&&!param.first.empty()&&param.first!="sign"&&param.first!="key")
        {
            str.append(param.first + "=" + param.second + "&");
        }
        if(str.size()>0)
        {
            str = str.substr(0, str.length() - 1) + key;
        }
        char *output;
        unsigned char *val = str.c_str();
        EncryptMD5str(output,val,str.size());
        str = output;
    }
}

int main()
{

    return 0;
}