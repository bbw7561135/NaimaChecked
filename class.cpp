#include <iostream>
using namespace std;


//圆周率
const double PI = 3.14;

//1、封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物

//封装一个圆类，求圆的周长
//class代表设计一个类，后面跟着的是类名
class Circle
{
public:  //访问权限  公共的权限
//属性
    int m_r;//半径

    //行为
    //获取到圆的周长
    double calculateZC()
    {
        //2 * pi  * r
        //获取圆的周长
        return  2 * PI * m_r;
    }
}; //like struct should have ; when ends

//学生类
class Student
{
public:
    void setName(string name)
    {
        m_name = name;
    }

    void setID(int id)
    {
        m_id = id;
    }

    void showStudent()
    {
        cout << "name:" << m_name << " ID:" << m_id << endl;
    }

public:
    string m_name;
    int m_id;
};


//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问
//在C++中 struct和class唯一的区别就在于 默认的访问权限不同
//struct 默认权限为公共
//class 默认权限为私有
class Person
{
    //姓名  公共权限
public:
    string m_Name;

    //汽车  保护权限
protected:
    string m_Car;

    //银行卡密码  私有权限
private:
    int m_Password;

public:
    void func()
    {
        m_Name = "Amao";
        m_Car = "Audi";
        m_Password = 123456;
    }
};

class Personal
{
public:
    //姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }

    //设置年龄
    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            cout << "你个老妖精!" << endl;
            return;
        }
        m_Age = age;
    }
    //获取年龄 
    int getAge()
    {
        return m_Age;
    }


    //情人设置为只写
    void setLover(string lover)
    {
        m_Lover = lover;
    }

private:
    string m_Name; //可读可写  姓名
    int m_Age; //只读  年龄
    string m_Lover; //只写  情人
};

int main()
{
    //通过圆类，创建圆的对象
    // c1就是一个具体的圆
    Circle c1;
    c1.m_r = 10; //给圆对象的半径 进行赋值操作
    //2 * pi * 10 = = 62.8
    cout << "圆的周长为： " << c1.calculateZC() << endl;

    Student stu;
    stu.setName("Messi");
    stu.setID(10);
    stu.showStudent();


    Person p;
    p.func();
    cout << p.m_Name << endl;
    p.m_Name = "Adong";
    cout << p.m_Name << endl;
    //p.m_Car = "奔驰";  //保护权限类外访问不到
    //p.m_Password = 123; //私有权限类外访问不到


    Personal pp;
    //姓名设置
    pp.setName("Amao");
    cout << "姓名： " << pp.getName() << endl;

    //年龄设置
    pp.setAge(31);
    cout << "年龄： " << pp.getAge() << endl;

    //情人设置
    pp.setLover("Binbin");
    //cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取
    return 0;
}



























