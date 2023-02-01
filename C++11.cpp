// C++11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int size()
{
    return 1;
}

struct Sales_date
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int i = 0;
constexpr int j = 0;

int main()
{
    /* long long类型 */
    if (0)
    {
        short a = 0;
        int b = 0;
        long c = 0;
        // long long是在C++11中新定义的
        long long d = 0;
        float e = 0;
        double f = 0;
        std::cout << "sizeof(short)=" << sizeof(a) << "byte" << std::endl;
        std::cout << "sizeof(int)=" << sizeof(b) << "byte" << std::endl;
        std::cout << "sizeof(long)=" << sizeof(c) << "byte" << std::endl;
        std::cout << "sizeof(long long)=" << sizeof(d) << "byte" << std::endl;
        std::cout << "sizeof(float)=" << sizeof(e) << "byte" << std::endl;
        std::cout << "sizeof(double)=" << sizeof(f) << "byte" << std::endl;
    }

    /* 列表初始化 */
    if (0)
    {
        /* 初始化不是赋值
        *  初始化:创建变量时赋予一个初始值
        *  赋值:把对象的当前值擦除,用一个新值替代
        */
        // 用花括号来初始化变量的形式称为列表初始化
        int a1 = 0;
        int a2 = { 0 };
        int a3{ 0 };
        int a4(0);

        long double ld = 3.1415926536;
        // int a{ ld }, b = { ld }; error:使用列表初始化且初始化值存在丢失信息的风险,则编译器报错
        int c(ld), d = ld; // 执行转换,丢失部分值

        std::cout << "c = " << c << ",d = " << d << std::endl;

        /* 用大括号包围的值列表赋值 */
        if (1)
        {
            // C++11新标准允许使用花括号括起来的初始值列表作为赋值语句的右侧运算对象
            int k = 0;
            //k = { 3.14 }; error:窄化转换
            vector<int> v;
            v = { 0, 1, 2, 3 };
        }
    }

    /* nullptr常量 */
    if (0)
    {
        /* C++11新标准引入nullptr,是一种特殊类型的字面值,它可被转换成任意其他的指针类型
        *  新标准下最好使用nullptr,同时尽量避免使用NULL
        */
        int* p1 = nullptr; // 等价于int* p1 = 0;
        int* p2 = 0;
        /* 把int变量赋值指针是错误操作
        *  int a = 0;
        *  int* p3 = a; error:不能把int变量直接赋值给指针
        */
    }

    /* constexpr变量 */
    if (0)
    {
        /* 常量表达式 是指不会改变并且在编译过程就能得到计算结果的表达式
        *  字面值 属于常量表达式,用常量表达式初始化的const对象也是常量表达式
        */
        // C++11新标准规定,允许将变量声明为constexpr类型以便由编译器来验证变量的值是否为一个常量表达式
        constexpr int a = 20;
        constexpr int b = a + 10;
        //constexpr int c = size(); error:只有当size是一个constexpr函数时才是一条正确的声明语句

        // 在constexpr声明中如果定义了一个指针,限定符constexpr仅对指针有效,与指针所指对象无关
        const int* p = nullptr; // p是一个指向整型常量的指针
        constexpr int* q = nullptr; // q是一个指向整数的常量指针
        // constexpr指针既可以指向常量也可以指向一个非常量
        constexpr int* p1 = &i; // p1是常量指针,指向整数i
        constexpr const int* p2 = &j; // p2是常量指针,指向整数常量j
    }

    /* 类型别名声明 */
    if (0)
    {
        // 类型别名 是一个名字,它是某种类型的同义词
        // 传统方法是使用关键字typedef
        typedef double wages; // wages是double的同义词
        typedef wages base, * p; // base是double的同义词,p是double*的同义词
        // C++11规定了一种新方法,使用 别名声明 来定义类型的别名
        using LD = long double; // LD是long double的同义词
        LD a = 0; // 等价于long double a = 0;
    }

    /* auto类型指示符 */
    if (0)
    {
        // C++11新标准引入auto类型说明符,让编译器通过初始值来推断变量的类型,显然auto定义的变量必须有初始值
        int a = 0, b = 1;
        auto c = a + b; // c的类型是int
        // auto也能在一条语句中声明多个变量,因为一条声明语句只能有一个基本数据类型,所以该语句中所有变量的初始基本数据类型必须一样
        auto i = 0, * p = &i; // i为整数,p为整型指针
        //auto j = 0, k = 0.01; error:j和k类型不一致
    }

    /* decltype类型指示符 */
    if (0)
    {
        // decltype:选择并返回操作数的数据类型,编译器分析表达式并得到它的类型,却不实际计算表达式的值
        double x = 12.34;
        decltype(size()) sum = x; // sum的类型就是函数size的返回类型
        std::cout << sum;
    }

    /* 类内初始化 */
    if (0)
    {
        /* C++11新标准规定,可以为数据成员提供一个类内初始值
        *  创建对象时,类内初始值将用于初始化数据成员,没有初始值的成员将被默认初始化
        */
        Sales_date a;
        // 定义Sales_date对象时,units_sold和revenue都将初始化为0,bookNo将初始化为空字符串
        std::cout << a.units_sold << "--" << a.revenue << "--" << a.bookNo << "--";
        // C++11新标准允许编译器通过auto或decltype来推断变量的类型
        std::string b = "1";
        auto c = b.size(); // c的类型是std::string::size_type
    }

    /* 范围for语句 */
    if (0)
    {
        // C++11新标准提供 范围for语句,这种语句遍历给定序列中的每个元素并对序列中的每个值执行某种操作
        string str("some string");
        for (auto c : str) // 对于str中的每个字符
        {
            cout << c << endl; // 输出当前字符
        }

        string s("Hello World!!!");
        decltype(s.size()) punct_cnt = 0; // punct_cnt的类型和s.size的返回类型一样,也就是string::size_type
        for (auto c : s) // 对于s中的每个字符
        {
            if (ispunct(c)) // 如果该字符是标点符号
            {
                ++punct_cnt; // 将标点符号的计数加1
            }
        }
        cout << "punct_cun=" << punct_cnt << endl;

        for (auto& c : s) // 对于s中的每个字符(注意c是引用)
        {
            c = toupper(c); // c是一个引用,因此赋值语句将改变s中字符的值
        }
        cout << s << endl;
    }

    /* 定义vector对象的vector(向量的向量) */
    /* vector对象的列表初始化 */
    if (0)
    {
        // 早期版本C++标准中如果vector的元素还是vector(或其他模板类型),则需要写为vector<vector<int> >
        vector<vector<int> > a; // 早期版本C++标准
        vector<vector<int>> b; // C++11新标准

        // C++11新标准提供了列表初始化的方法为vector对象的元素进行赋初值
        vector<string> c{ "a", "aa", "aaa" };
        vector<string> d = { "a", "aa", "aaa" };
        for (auto str : c)
        {
            cout << str << endl;
        }
    }

    /* 容器的cbegin和cend函数 */
    if (0)
    {
        // begin和end返回的具体类型由对象是否是常量决定,如果是常量:const_iterator,如果不是常量:iterator
        vector<int> i;
        const vector<int>j;
        auto it1 = i.begin(); // it1的类型是vector<int>::iterator
        auto it2 = j.begin(); // it2的类型是vector<int>::const_iterator
        // C++11新标准引入cbegin和cend函数,不论对象本身是否为常量,返回值都是const_iterator
        auto it3 = i.cbegin(); // it3的类型是vector<int>::const_iterator
    }

    /* 标准库的begin和end函数 */
    if (0)
    {
        // C++11新标准引入了begin和end函数,与容器中的两个同名成员功能类似,不过数组不是类类型,故此函数使用形式是将数组作为他们的参数
        int ia[] = { 0, 1, 2 };
        int* beg = begin(ia);
        int* last = end(ia);
        for (; beg != last; ++beg)
        {
            cout << *beg << endl;
        }
    }

    /* 使用auto和decltype简化声明 */
    if (0)
    {
        int ia[3][4] = {0}; // 大小为3的数组,每个元素是含有4个整数的数组
        int(*p)[4] = ia; // p指向含有4个整数的数组
        p = &ia[2]; // p指向ia的尾元素,等同于p = ia + 2;
        
        /* C++11新标准使得通过auto或decltype就能尽可能避免在数组前面加上一个指针类型
        *  虽然能推断出p的类型是指向含有4个整数的数组的指针,q的类型是指向整数的指针
        *  但是使用auto关键字后就不必烦心这些类型到底是什么了
        */
        for (auto p = begin(ia); p != end(ia); ++p)
        {
            for (auto q = begin(*p); q != end(*p); ++q)
            {
                cout << *q << ' ';
            }
            cout << endl;
        }
    }

    /* 除法的舍入规则 */
    if (0)
    {
        /* 在除法运算中,如果两个运算对象的符号相同中则商为正(如果不为0的话),否则商为负
        *  C++早期版本允许结果为负的商向上或向下取整
        *  C++11新标准规定商一律向0取整(即直接切除小数部分)
        */
    }

    /* 将sizeof用于类成员 */
    if (1)
    {

    }

    return 0;
}
