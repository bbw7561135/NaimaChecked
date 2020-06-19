#include <iostream>
using namespace std;
//1. 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

////不能返回局部变量的引用
//int& test01() {
//    int a = 10; //局部变量
//    return a;
//}

//返回静态变量引用
int& test02()
{
    static int a = 20;
    return a;
}

//引用使用的场景，通常用来修饰形参
void showValue(const int& v)
{
    //v += 10; //error operation
    cout << v << endl;
}


int main()
{
    int a = 10;
    int &b = a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    b=100;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    int aa=125;
    int &c=aa;
    cout << "c=" << c << endl;
    cout << "aa=" << aa << endl;
    c=b;//这是赋值操作，不是更改引用
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    cout << "aa=" << aa << endl;
    int k=2;
    int m=6;
    mySwap01(k, m);
    cout << "k:" << k << " m:" << m << endl;

    mySwap02(&k, &m);
    cout << "k:" << k << " m:" << m << endl;

    mySwap03(k, m);
    cout << "k:" << k << " m:" << m << endl;

    //如果函数做左值，那么必须返回引用
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;

    test02() = 1000;//meaningless and confusing

    cout << "ref2 = " << ref2 << endl;

//C++推荐用引用技术，因为语法方便，引用本质是指针常量
//但是所有的指针操作编译器都帮我们做了
    //int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
    //加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
    const int& ref1 = 10;

    //ref = 100;  //加入const后不可以修改变量
    cout << ref1 << endl;

    //函数中利用常量引用防止误操作修改实参
    int aaa = 10;
    showValue(aaa);


    return 0;
}


























