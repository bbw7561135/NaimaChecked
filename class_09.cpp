#include <iostream>
using namespace std;

//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//class Person
//{
//public:
//    Person() {};
//    Person(int a, int b)
//    {
//        this->m_A = a;
//        this->m_B = b;
//    }
//    //成员函数实现 + 号运算符重载
//    Person operator+(const Person& p) //can not change p
//    {
//        Person temp;
//        temp.m_A = this->m_A + p.m_A;
//        temp.m_B = this->m_B + p.m_B;
//        return temp;
//    }


//public:
//    int m_A;
//    int m_B;
//};



////全局函数实现 + 号运算符重载
////Person operator+(const Person& p1, const Person& p2)
////{
////  Person temp(0, 0);
////  temp.m_A = p1.m_A + p2.m_A;
////  temp.m_B = p1.m_B + p2.m_B;
////   return temp;
////}


////运算符重载 可以发生函数重载 
//Person operator+(const Person& p2, int val)  
//{
//    Person temp;
//    temp.m_A = p2.m_A + val;
//    temp.m_B = p2.m_B + val;
//    return temp;
//}
////pay attention to the place for clarification//全局函数




//void test()
//{

//    Person p1(10, 10);
//    Person p2(20, 20);

//    //成员函数方式
//    Person p3 = p2 + p1;  //相当于 p2.operaor+(p1)
//    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;


//    Person p4 = p3 + 10; //相当于 operator+(p3,10)
//    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;

//}


//int main() 
//{

//    test();
//    return 0;
//}


//总结1：对于内置的数据类型的表达式的的运算符是不可能改变的

//总结2：不要滥用运算符重载



////左移运算符重载
////作用：可以输出自定义数据类型

//class Person
//{
//    friend ostream& operator<<(ostream& out, Person& p);

//public:

//    Person(int a, int b)
//    {
//        this->m_A = a;
//        this->m_B = b;
//    }

//    //成员函数 实现不了  p << cout 不是我们想要的效果
//    //void operator<<(Person& p){
//    //}

//private:
//    int m_A;
//    int m_B;
//};


////全局函数实现左移重载
////ostream对象只能有一个
//ostream& operator<<(ostream& out, Person& p)
//{
//    out << "a:" << p.m_A << " b:" << p.m_B;
//    return out;
//}


//void test()
//{
//    Person p1(10, 20);
//    cout << p1 << "hello world" << endl; //链式编程
//}


//int main()
//{
//    test();
//    return 0;
//}

////重载左移运算符配合友元可以实现输出自定义数据类型


class MyInteger
{
    friend ostream& operator<<(ostream& out, MyInteger myint);

public:
    MyInteger()
    {
        m_Num = 0;
    }
    //前置++
    MyInteger& operator++() {
        //先++
        m_Num++;
        //再返回
        return *this;
    }

    //后置++
    MyInteger operator++(int)//int here is necessary
    {
        //先返回
        MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};

//前置递增返回引用，后置递增返回值

ostream& operator<<(ostream& out, MyInteger myint)
{
    out << myint.m_Num;
    return out;
}


//前置++ 先++ 再返回
void test01()
{
    MyInteger myInt;
    cout << ++myInt << endl;
    cout << myInt << endl;
}

//后置++ 先返回 再++
void test02()
{
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main()
{

    test01();
    test02();
    return 0;
}


































































































