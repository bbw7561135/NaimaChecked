#include <iostream>
using namespace std;


//默认情况下，c++编译器至少给一个类添加3个函数

//1．默认构造函数(无参，函数体为空)

//2．默认析构函数(无参，函数体为空)

//3．默认拷贝构造函数，对属性进行值拷贝

//构造函数调用规则如下：

//如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造

//如果用户定义拷贝构造函数，c++不会再提供其他构造函数

class Person
{
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
    Person p1(18);
    //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    //浅拷贝只复制指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存
    //但深拷贝在堆区重新申请空间(new) 会另外创造一个一模一样的对象，新对象跟原对象不共享内存，修改新对象不会改到原对象
    Person p2(p1);

    cout << "p2的年龄为： " << p2.age << endl;
}

void test02()
{
    Person p1; //此时如果用户自己没有提供默认构造，会出错
    Person p2(10); //用户提供的有参
    Person p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

    //如果用户提供拷贝构造，编译器不会提供其他构造函数
    Person p4; //此时如果用户自己没有提供默认构造，会出错
    Person p5(10); //此时如果用户自己没有提供有参，会出错
    Person p6(p5); //用户自己提供拷贝构造
}


int main()
{
    test01();
    return 0;
}


//如果属性有在堆区开辟的(new)，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

//class Person {
//public:
//	//无参（默认）构造函数
//	Person() {
//		cout << "无参构造函数!" << endl;
//	}
//	//有参构造函数
//	Person(int age ,int height) {
//		
//		cout << "有参构造函数!" << endl;

//		m_age = age;
//		m_height = new int(height);
//		
//	}
//	//拷贝构造函数  
//	Person(const Person& p) {
//		cout << "拷贝构造函数!" << endl;
//		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
//		m_age = p.m_age;
//		m_height = new int(*p.m_height);//浅拷贝带来的重复释放堆区问题
//		
//	}

//	//析构函数
//	~Person() {
//		cout << "析构函数!" << endl;
//		if (m_height != NULL)
//		{
//			delete m_height;//浅拷贝带来的重复释放堆区问题
//		}
//	}
//public:
//	int m_age;
//	int* m_height;
//};


//class Person {
//public:

//	////传统方式初始化
//	//Person(int a, int b, int c) {
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}

//	//初始化列表方式初始化
//	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {}
//	void PrintPerson() {
//		cout << "mA:" << m_A << endl;
//		cout << "mB:" << m_B << endl;
//		cout << "mC:" << m_C << endl;
//	}
//private:
//	int m_A;
//	int m_B;
//	int m_C;
//};

//int main() {

//	Person p(1, 2, 3);
//	p.PrintPerson();


//	return 0;
//}





























