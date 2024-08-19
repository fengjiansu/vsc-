class String
{
    public:
    String(const char* cstr = 0);

    String(const String& str);//拷贝构造函数
    String& operator=(const String& str);//拷贝赋值函数

    ~String();

    char *get_c_str() const {return m_data};

private:
    char *m_data;

};

inline
String::String(const char* cstr = 0)
{
    if(cstr)
    {
        m_data = new char[strlen(cstr) + 1];//动态分配C风格的字符串空间
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::~String()
{
    delete[] m_data;
}
inline
String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];//创建足够空间
    strcpy(m_data, str.m_data);
}

inline
String& String::operator=(const String &str)
{
    //检测自我赋值
    if(this == &str)
    {
        return *this;
    }

    delete[] m_data; //赋值之前先清空
    m_data =  new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}
