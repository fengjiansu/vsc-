#include<bits/stdc++.h>


void m1(std::set<std::string> &sets,std::vector<std::string> &l1,std::vector<std::string>& ary)
{
    for(auto &s:sets)
    {
        for(auto &p:ary)
        {
            if(s.find(p)!=std::string::npos)
            {
                l1.push_back(s);
            }
        }
    }
}

static std::set<std::string> best;
    static std::set<std::string> justSoSo;
    static std::set<std::string> bad;

void init1() {
        best = {"�������Լ������ĳ�ŵ",
                "�Ҿ����������س�ŵ�൱��Ҫ",
                "�Ҽ�ְ�ʱ�������",
                "�����¹㷺��ȡ���˵����",
                "����ǰ�һ���ѯ��ҵ����",
                "��Ը�⻨ʱ��ȥ��������",
                "�����²�ϲ����;����",
                "�ұ����˽�ײ�ԭ����ܸ���Ч��ѧϰ",
                "�������ڸ��ݿ͹���ʵ������",
                "�ұ����ҵ��������İ취",
                "����Ҫ�˽��۵㱳����߼�",
                "��ϲ������",
                "����ʱ��ϲ�����·������µ���",
                "��������ܶ�����",
                "��ϲ������ܶ�����",
                "��ϲ����������ļ���"};

        justSoSo = {
                "�����ںͱ��˽�����Ǣ��ϵ",
                "��ϲ����ѹ���Ļ����¹���",
                "��ϲ��æµ������",
                "����Ҫ����ȷ��Զ���ƻ�",
                "��ϲ��˼��δ��",
                "�Ҹ��Լ��趨�˳�ԶĿ��",
                "�Ҿ���չ��δ��",
                "�Ҷ�δ���Ƚ��ֹ�",
                "������δ����������Ǻõ�",
                "�����º���Զ��",
                "���µ�ʱ������Ҫ���¿�ѭ",
                "�����¾�������",
                "�ҷǳ�ע��ϸ��",
                "������ͬ�´����������",
                "��ѭ�浸�ص�ȥ������",
                "��ϲ�������ݽ���ͳ�������",
                "��ϲ�����۳����Ե�����",
                "�����ڴ�����������",
                "�Ҳ����ױ����˼�ŭ",
                "����������",
                "������İ�����ѽ���ʱ����������",
                "�Ҵ󲿷�ʱ���ǿ��ֵ�",
                "����ǿ�ҵĺ�����",
                "��ϲ���о����Ĺ���",
                "����һ�������ĺ�ǿ����"
        };

        bad = {"���ƿ����Լ���δ��",
                "�����ش����鷢��ǰ�����",
                "�����������������",
                "�Ҽ���Լ������·�ʽ",
                "�����ڽύ����",
                "��ϲ����ʶİ����",
                "������̸��",
                "����������",
                "���Ǹ��ܽ�̸����",
                "�ҹ�ע���˵�����Ŀ�������¶���",
                "������������Ǳ���Ķ���",
                "������������˵ĸ���",
                "��Ҫ��Խ����",
                "���нϴ��Ұ��",
                "�����Ϊ�Ŷ��е��쵼",
                "�Ҹ�Ը���쵼����",
                "��ϲ����ս���˵��뷨",
                "�����ܶ��Թ���"};
    }



 static std::set<std::string> keyWordLevel1;
    static std::set<std::string> keyWordLevel2;
    static std::set<std::string> keyWordLevel3;
    static std::set<std::string> keyWordLevel4;
    static std::set<std::string> keyWordLevel5;

void init2() {
         keyWordLevel1 = {"�ɹ�", "��ʱ", "����", "����", "�³�", "����", "�͹�", "��ѹ", "ʵ��", "���", "��Ч", "ѧϰ", "�ɾ�", "����", "��ȡ", "��Ӧ", "����", "��������"};
         keyWordLevel2 = {"����", "����", "����", "����", "ԭ��", "�߼�", "����", "����", "���", "��ȡ", "����", "�˼�", "����", "�ƻ�", "��ӡ��", "��Ҫ����", "����", "����", "�ֹ�", "����", "δ��", "����", "�������", "��������"};
         keyWordLevel3 = {"��ʶ����", "�ƿ�", "�ͷ���", "���߳�", "�ش����", "�������", "������"};
         keyWordLevel4 = {"��ҵ", "̸��", "Э��", "�ݽ�", "�쵼", "�ܾ�", "��������", "��˵��", "���پ���", "���۶���", "��ʶİ����"};
         keyWordLevel5 = {"����", "����", "����", "����", "����", "����"};
    }

void init1H(std::vector<std::string>& keyWords)
{
         std::vector<std::string> l1, l2, l3;
         m1(best, l1, keyWords);
         m1(justSoSo, l2, keyWords);
         m1(bad, l3, keyWords);
         std::cout << "ϲ���Ӱ�-�Կ����� ��ӹ-��Ҫ�����Լ������� �ȶ� �ŶӺ�������Ҫ �Ը��ܹ���" << std::endl;
         std::cout << "����� [";
         for(auto &s:l1)
         {
             std::cout << s << " ";
         }
         std::cout << "]"<< std::endl;
         std::cout << "���е� [";
         for(auto s:l2)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "�����ʵ� [";
         for(auto s:l3)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << std::endl;
}

void init2H(std::vector<std::string>& keyWords)
{
         std::vector<std::string> ll1, ll2, ll3,ll4,ll5;
         m1(keyWordLevel1, ll1, keyWords);
         m1(keyWordLevel2, ll2, keyWords);
         m1(keyWordLevel3, ll3, keyWords);
        m1(keyWordLevel4, ll4, keyWords);
        m1(keyWordLevel5, ll5, keyWords);
        std::cout << std::endl;
        std::cout << "����Ա��ϲ����tag�����ţ���ѹ���ŶӺ�������ͻ�����������ۡ���Щ����ѡǿ��ͬ��" << std::endl;
        std::cout << "ǿ��ͬ�� [";
        for (auto s : ll1)
        {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "����ͬ�� [";
         for(auto s:ll2)
         {
             std::cout << s << " ";
         }
        std::cout <<"] "<< std::endl;
         std::cout << "���� [";
         for(auto &s:ll3)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "������ͬ�� [";
         for(auto &s:ll4)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "ǿ�Ҳ�ͬ�� [";
         for(auto &s:ll5)
         {
             std::cout << s << " ";
         }
          std::cout <<"] "<< std::endl;
}


void handle(std::string & word1,std::string &word2,std::string &word3)
{
    std::vector<std::string> keyWords;
    keyWords.push_back(word1);
    keyWords.push_back(word2);
    keyWords.push_back(word3);
    init1H(keyWords);
    init2H(keyWords);
}




int main()
{
    std::string line,keyWord1,keyWord2,keyWord3;
    init1();
    init2();
    while (true){

        std::cin >> keyWord1;
        std::cin >> keyWord2;
        std::cin>> keyWord3;
        //std::cout << keyWord1 << keyWord2 << keyWord3;
        handle(keyWord1, keyWord2, keyWord3);
        }  
    /* std::cout << str.size() << std::endl;
    std::cout << str<<std::endl;
    std::cout << "���"; */
    //std::cout << ;
    return 0;
}

