#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int Add(int left, int right)
{
    return left + right;
}

// 通用加法函数
template<class T>
T Add(T left, T right)
{
    return left + right;
}

template<class T>
T* func(int n)
{
    return new T[n];
}

//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	double a = 1.1, b = 2.2;
//	swap(a, b);
//
//	cout << Add(x, y) << endl;
//
//	cout << Add<int>(x, y) << endl;
//
//	int* ptr = func<int>(10);
//
//	return 0;
//}

template<class T>
class Vector
{
public:
    Vector(size_t capacity = 10)
        : _pData(new T[capacity])
        , _size(0)
        , _capacity(capacity)
    {}

    // 使用析构函数演示：在类中声明，在类外定义。
    ~Vector();

    void PushBack(const T& data);
    void PopBack();
    // ...

    size_t Size() { return _size; }

    T& operator[](size_t pos)
    {
        //assert(pos < _size);
        return _pData[pos];
    }

private:
    T* _pData;
    size_t _size;
    size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
    delete[] _pData;
    _pData = nullptr;
}

// 类名 ： Vector
// 类型 ： Vector<T>

//int main()
//{
//    //Vector<int> v;
//
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.reserve(100);
//
//    list<int> lt;
//    lt.push_back(1);
//
//
//
//    return 0;
//}

void test_string1()
{
    string s1;
    string s2("hello");

    cin >> s1;
    cout << s1 << endl;
    cout << s2 << endl;

    //cin >> s2;
    //cout << s2 << endl;

    //char str[1600];
    //scanf

    // strcat
    string ret1 = s1 + s1;
    cout << ret1 << endl;

    string ret2 = s1 + "我来了";
    cout << ret2 << endl;
}

void test_string2()
{
    string s1("hello world");
    string s2 = "hello world";

    // 遍历string
    for (size_t i = 0; i < s1.size(); i++)
    {
        // 读
        cout << s1[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < s1.size(); i++)
    {
        // 写
        s1[i]++;
    }
    cout << s1 << endl;

    // 迭代器
    string::iterator it = s1.begin();
    //while (it < s1.end())  // 这里可以但是不建议
    while (it != s1.end())  // 推荐玩法，通用
    {
        // 读
        cout << *it << " ";
        ++it;
    }
    cout << endl;


    it = s1.begin();
    while (it != s1.end())
    {
        // 写
        *it = 'a';
        ++it;
    }
    cout << endl;
    cout << s1 << endl;

    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    list<int>::iterator lit = lt.begin();
    while (lit != lt.end())
    {
        cout << *lit << " ";
        ++lit;
    }
    cout << endl;
}

void test_string3()
{
    string s1("hello world");
    string::iterator it = s1.begin();
    //while (it < s1.end())  // 这里可以但是不建议
    while (it != s1.end())  // 推荐玩法，通用
    {
        // 读
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    //string::reverse_iterator rit = s1.rbegin();
    auto rit = s1.rbegin();
    while (rit != s1.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;

    // 原理：编译器编译器替换成迭代器
    // 读
    for (auto ch : s1)
    {
        cout << ch << " ";
    }
    cout << endl;

    // 写
    for (auto& ch : s1)
    {
        ch++;
    }
    cout << endl;

    cout << s1 << endl;
}

// 17:17继续
void func(const string& s)
{
    //string::const_iterator it = s.begin();
    auto it = s.begin();
    while (it != s.end())
    {
        // 不支持写
        // *it = 'a';

        // 读
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    //string::const_reverse_iterator rit = s.rbegin();
    auto rit = s.rbegin();
    while (rit != s.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void test_string4()
{
    string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyy");
    func(s1);

    string s2(s1);
    cout << s2 << endl;

    string s3(s1, 6, 5);
    cout << s3 << endl;

    string s4(s1, 6, 3);
    cout << s4 << endl;

    string s5(s1, 6);
    cout << s5 << endl;

    string s6(s1, 6, s1.size() - 6);
    cout << s6 << endl;

    string s7(10, 'a');
    cout << s7 << endl;

    string s8(++s7.begin(), --s7.end());
    cout << s8 << endl;

    s8 = s7;
    s8 = "xxx";
    s8 = 'y';
}

void test_string5()
{
    //string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyy");
    string s1("hello world");
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1.capacity() << endl;

    s1.clear();
    s1 += "张三";
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;
    //cout << s1.max_size() << endl;

    // mysql

    string filename;
    cin >> filename;
    // FILE* fout = fopen(filename.c_str(), "r");
}

// reserve  保留
// reverse  反转

void test_string6()
{
    string s;
    s.reserve(100);

    size_t old = s.capacity();
    cout << "初始" << s.capacity() << endl;

    for (size_t i = 0; i < 100; i++)
    {
        s.push_back('x');

        if (s.capacity() != old)
        {
            cout << "扩容:" << s.capacity() << endl;
            old = s.capacity();
        }
    }

    s.reserve(10);
    cout << s.capacity() << endl;
}

void test_string7()
{
    string s1("hello world");
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;

    //s1.resize(13);
    //s1.resize(13, 'x');
    s1.resize(20, 'x');
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;

    s1.resize(5);
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;

    string s2;
    s2.resize(10, '#');
    cout << s2 << endl;
    cout << s2.size() << endl;
    cout << s2.capacity() << endl;

    s2[0]++;
    s2.at(0)++;
    cout << s2 << endl;
}

void test_string8()
{
    string ss("world");

    string s;
    s.push_back('#');
    s.append("hello");
    s.append(ss);
    cout << s << endl;

    s += '#';
    s += "hello";
    s += ss;
    cout << s << endl;

    string ret1 = ss + '#';
    string ret2 = ss + "hello";
    cout << ret1 << endl;
    cout << ret2 << endl;
}

void test_string9()
{
    std::string str("xxxxxxx");
    std::string base = "The quick brown fox jumps over a lazy dog.";

    str.assign(base);
    std::cout << str << '\n';

    str.assign(base, 5, 10);
    std::cout << str << '\n';
}

void test_string10()
{
    // insert/erase/repalce能不用就尽量不用，因为他们都涉及挪动数据，效率不高
    // 接口设计复杂繁多，需要时查一下文档即可
    std::string str("hello world");
    str.insert(0, 1, 'x');
    str.insert(str.begin(), 'x');
    cout << str << endl;

    str.erase(5);
    cout << str << endl;

    std::string s1("hello world");
    s1.replace(5, 3, "%%20");
    cout << s1 << endl;

    // 空格替换为20%
    std::string s2("The quick brown fox jumps over a lazy dog.");
    string s3;
    for (auto ch : s2)
    {
        if (ch != ' ')
        {
            s3 += ch;
        }
        else
        {
            s3 += "20%";
        }
    }

    //s2 = s3;
    //s2.assign(s3);
    printf("s2：%p\n", s2.c_str());
    printf("s3：%p\n", s3.c_str());

    swap(s2, s3);
    //s2.swap(s3);

    printf("s2：%p\n", s2.c_str());
    printf("s3：%p\n", s3.c_str());

    cout << s2 << endl;
}

void test_string11()
{
    string s1("test.cpp.tar.zip");
    //size_t i = s1.find('.');
    size_t i = s1.rfind('.');

    string s2 = s1.substr(i);
    cout << s2 << endl;

    //string s3("https://legacy.cplusplus.com/reference/string/string/rfind/");
    string s3("ftp://www.baidu.com/?tn=65081411_1_oem_dg");
    // 协议
    // 域名
    // 资源名

    string sub1, sub2, sub3;
    size_t i1 = s3.find(':');
    if (i1 != string::npos)
        sub1 = s3.substr(0, i1);
    else
        cout << "没有找到i1" << endl;

    size_t i2 = s3.find('/', i1 + 3);
    if (i2 != string::npos)
        sub2 = s3.substr(i1 + 3, i2 - (i1 + 3));
    else
        cout << "没有找到i2" << endl;

    sub3 = s3.substr(i2 + 1);

    cout << sub1 << endl;
    cout << sub2 << endl;
    cout << sub3 << endl;
}

void test_string12()
{
    /*std::string str("Please, replace the vowels in this sentence by asterisks.");
    std::size_t found = str.find_first_not_of("abc");
    while (found != std::string::npos)
    {
        str[found] = '*';
        found = str.find_first_not_of("abcdefg", found + 1);
    }

    std::cout << str << '\n';*/

    std::string str("Please, replace the vowels in this sentence by asterisks.");
    std::size_t found = str.find_first_of("abcd");
    while (found != std::string::npos)
    {
        str[found] = '*';
        found = str.find_first_of("abcd", found + 1);
    }

    std::cout << str << '\n';

}

//int main()
//{
//    test_string12();
//
//    return 0;
//}

#include <iostream>
#include<string>
using namespace std;

int main()
{
    /*string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << endl;
    cout << s2 << endl;*/


    string str;
    //cin >> str;
    getline(cin, str, '!');
    cout << str;

    /*size_t i = str.rfind(' ');
    if (i != string::npos)
    {
        cout << str.size() - (i + 1) << endl;
    }
    else
    {
        cout << str.size() << endl;
    }*/
}