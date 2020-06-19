#include <iostream>
using namespace std;

//构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。
//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作
//构造函数语法：类名()

//构造函数，没有返回值也不写void
//函数名称与类名相同
//构造函数可以有参数，因此可以发生重载
//程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次


//析构函数语法： ~类名()

//析构函数，没有返回值也不写void
//函数名称与类名相同,在名称前加上符号 ~
//析构函数不可以有参数，因此不可以发生重载
//程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次


//1、构造函数分类
// 按照参数分类分为 有参和无参构造   无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造
//class Person
//{
//public:
//    //构造函数
//    Person()
//    {
//        cout << "Person的构造函数调用" << endl;
//    }
//    //析构函数
//    ~Person()
//    {
//        cout << "Person的析构函数调用" << endl;
//    }
//};

class Person {
public:
    //无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    //有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    //拷贝构造函数
    Person(const Person& p)
    {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    //析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }
public:
    int age;
};

void test01()
{
    Person p;
}
void test02() {

    //2.1  括号法，常用
    Person p1(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    //Person p2();

    //2.2 显式法
    Person p2 = Person(10); 
    Person p3 = Person(p2);
    //Person(10)单独写就是匿名对象  当前行结束之后，马上析构

    //2.3 隐式转换法
    Person p4 = 10; // Person p4 = Person(10); 
    Person p5 = p4; // Person p5 = Person(p4); 

    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    //Person p5(p4);
}
int main()
{
    test01();
    test02();
    return 0;
}



































