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
        best = {"我信守自己作出的承诺",
                "我觉得人们信守承诺相当重要",
                "我坚持按时完成任务",
                "我做事广泛听取别人的意见",
                "做事前我会征询大家的意见",
                "我愿意花时间去帮助他人",
                "我做事不喜欢半途而废",
                "我必须了解底层原理才能更有效地学习",
                "我倾向于根据客观事实做决定",
                "我必须找到解决问题的办法",
                "我需要了解论点背后的逻辑",
                "我喜欢创新",
                "做事时我喜欢有新方法，新点子",
                "我能想出很多主意",
                "我喜欢提出很多主意",
                "我喜欢提出独到的见解"};

        justSoSo = {
                "我善于和别人建立融洽关系",
                "我喜欢有压力的环境下工作",
                "我喜欢忙碌的生活",
                "我需要有明确的远景计划",
                "我喜欢思考未来",
                "我给自己设定了长远目标",
                "我经常展望未来",
                "我对未来比较乐观",
                "我相信未来的事情会是好的",
                "我做事很有远见",
                "做事的时候我需要有章可循",
                "我做事井井有条",
                "我非常注重细节",
                "我善于同事处理多项任务",
                "我循规蹈矩地去做事情",
                "我喜欢对数据进行统计与分析",
                "我喜欢讨论抽象性的问题",
                "我善于处理数字资料",
                "我不容易被别人激怒",
                "我信任他人",
                "我在与陌生朋友交流时会轻松自在",
                "我大部分时间是快乐的",
                "我有强烈的好奇心",
                "我喜欢有竞争的工作",
                "我是一个竞争心很强的人"
        };

        bad = {"我掌控着自己的未来",
                "我在重大事情发生前会紧张",
                "我想有人陪在我身边",
                "我坚持自己的做事方式",
                "我善于结交朋友",
                "我喜欢结识陌生人",
                "我善于谈判",
                "我善于推销",
                "我是个很健谈的人",
                "我关注别人的做事目的与做事动机",
                "我善于理解人们背后的动机",
                "我善于体会他人的感受",
                "我要超越别人",
                "我有较大的野心",
                "我想成为团队中的领导",
                "我更愿意领导别人",
                "我喜欢挑战别人的想法",
                "我享受独自工作"};
    }



 static std::set<std::string> keyWordLevel1;
    static std::set<std::string> keyWordLevel2;
    static std::set<std::string> keyWordLevel3;
    static std::set<std::string> keyWordLevel4;
    static std::set<std::string> keyWordLevel5;

void init2() {
         keyWordLevel1 = {"成功", "守时", "守信", "自信", "章程", "创新", "客观", "抗压", "实践", "坚持", "有效", "学习", "干劲", "保密", "听取", "适应", "改正", "事情主次"};
         keyWordLevel2 = {"利益", "书面", "解释", "反馈", "原理", "逻辑", "数字", "鼓励", "解决", "听取", "满足", "人际", "好奇", "计划", "好印象", "重要决策", "解释", "倾听", "乐观", "信任", "未来", "交际", "独到意见", "激励他人"};
         keyWordLevel3 = {"认识生人", "掌控", "低风险", "多线程", "重大决策", "解决争端", "新朋友"};
         keyWordLevel4 = {"商业", "谈判", "协调", "演讲", "领导", "杠精", "完美主意", "爱说话", "高速决策", "言论动机", "认识陌生人"};
         keyWordLevel5 = {"焦虑", "争辩", "焦点", "激进", "推销", "雄心"};
    }

void init1H(std::vector<std::string>& keyWords)
{
         std::vector<std::string> l1, l2, l3;
         m1(best, l1, keyWords);
         m1(justSoSo, l2, keyWords);
         m1(bad, l3, keyWords);
         std::cout << "喜欢加班-吃苦耐劳 中庸-不要表现自己的特性 稳定 团队合作很重要 性格不能过激" << std::endl;
         std::cout << "最合适 [";
         for(auto &s:l1)
         {
             std::cout << s << " ";
         }
         std::cout << "]"<< std::endl;
         std::cout << "适中的 [";
         for(auto s:l2)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "不合适的 [";
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
        std::cout << "技术员工喜欢的tag是守信，抗压，团队合作，不突出，不爱辩论。这些无脑选强烈同意" << std::endl;
        std::cout << "强烈同意 [";
        for (auto s : ll1)
        {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "基本同意 [";
         for(auto s:ll2)
         {
             std::cout << s << " ";
         }
        std::cout <<"] "<< std::endl;
         std::cout << "中立 [";
         for(auto &s:ll3)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "基本不同意 [";
         for(auto &s:ll4)
         {
             std::cout << s << " ";
         }
         std::cout <<"] "<< std::endl;
         std::cout << "强烈不同意 [";
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
    std::cout << "你好"; */
    //std::cout << ;
    return 0;
}

