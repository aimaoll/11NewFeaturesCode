// C++11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int size()
{
    return 1;
}

int i = 0;
constexpr int j = 0;

int main()
{
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
    }

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

    if (1)
    {
        // C++11新标准引入auto类型说明符,让编译器通过初始值来推断变量的类型,显然auto定义的变量必须有初始值
        int a = 0, b = 1;
        auto c = a + b; // c的类型是int
        // auto也能在一条

    }

    return 0;
}
