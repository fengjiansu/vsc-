#include<bits/stdc++.h>
#include"./library/md5.h"
using namespace std;

/* 
 * 和风天气签名生成算法-C++版本
     * @param HashMap params 请求参数集，所有参数必须已转换为字符串类型
     * @param String secret 签名密钥（用户的认证key）
     * @return 签名
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