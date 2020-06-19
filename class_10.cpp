#include <iostream>
using namespace std;

//c++编译器至少给一个类添加4个函数

//默认构造函数(无参，函数体为空)
//默认析构函数(无参，函数体为空)
//默认拷贝构造函数，对属性进行值拷贝
//赋值运算符 operator=, 对属性进行值拷贝

//如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题

class Person
{
public:

    Person(int age)
    {
        //将年龄数据开辟到堆区
        m_Age = new int(age); //set initial value as age
    }

    //重载赋值运算符 
    Person& operator=(Person &p)
    {
        if (m_Age!= NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        //编译器提供的代码是浅拷贝
        //m_Age = p.m_Age;

        //提供深拷贝 解决浅拷贝的问题
        m_Age = new int(*p.m_Age);//set *p.m_Age as init value

        //返回自身
        return *this;
    }


    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }

    //年龄的指针
    int *m_Age;

};


void test01()
{
    Person p1(18);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1; //赋值操作

    cout << "p1的年龄为：" << *p1.m_Age << endl;

    cout << "p2的年龄为：" << *p2.m_Age << endl;

    cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main()
{

    test01();

    //int a = 10;
    //int b = 20;
    //int c = 30;

    //c = b = a;
    //cout << "a = " << a << endl;
    //cout << "b = " << b << endl;
    //cout << "c = " << c << endl;

    return 0;
}



//重载关系运算符，可以让两个自定义类型对象进行对比操作

//class Person
//{
//public:
//    Person(string name, int age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    };

//    bool operator==(Person & p)
//    {
//        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }

//    bool operator!=(Person & p)
//    {
//        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//        {
//            return false;
//        }
//        else
//        {
//            return true;
//        }
//    }

//    string m_Name;
//    int m_Age;
//};

//void test01()
//{
//    Person a("孙悟空", 18);
//    Person b("孙悟空", 18);

//    if (a == b)
//    {
//        cout << "a和b相等" << endl;
//    }
//    else
//    {
//        cout << "a和b不相等" << endl;
//    }

//    if (a != b)
//    {
//        cout << "a和b不相等" << endl;
//    }
//    else
//    {
//        cout << "a和b相等" << endl;
//    }
//}


//int main()
//{
//    test01();
//    return 0;
//}


// 函数调用运算符重载
//函数调用运算符 () 也可以重载
//由于重载后使用的方式非常像函数的调用，因此称为仿函数
//仿函数没有固定写法，非常灵活


//class MyPrint
//{
//public:
//    void operator()(string text)
//    {
//        cout << text << endl;
//    }

//};
//void test01()
//{
//    //重载的（）操作符 也称为仿函数
//    MyPrint myFunc;
//    myFunc("hello world");
//}


//class MyAdd
//{
//public:
//    int operator()(int v1, int v2)
//    {
//        return v1 + v2;
//    }
//};

//void test02()
//{
//    MyAdd add;
//    int ret = add(10, 10);
//    cout << "ret = " << ret << endl;

//    //匿名对象调用  
//    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
//}

//int main()
//{

//    test01();
//    test02();
//    return 0;
//}






































































