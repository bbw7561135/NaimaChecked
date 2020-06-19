#include <iostream>
#include <string>
#define MAX 2
using namespace std;


void show_menu()
{
    cout << "******************************" << endl;
    cout << "*******1.add persons**********" << endl;
    cout << "*******2.show persons*********" << endl;
    cout << "*******3.delete persons*******" << endl;
    cout << "*******4.search persons*******" << endl;
    cout << "*******5.modify persons*******" << endl;
    cout << "*******6.clear persons********" << endl;
    cout << "*******0.exit*****************" << endl;
}

struct Person
{
    string m_name;
    int m_sex;//1man 2woman
    int m_age;
    string m_phone;
    string m_addr;
};

struct Addressbooks
{
    struct Person person_array[MAX];
    int m_size;
};

void add_person(Addressbooks *abs)
{
    if(abs->m_size == MAX)
    {
        cout << "filled, can not add persons" << endl;
        return;
    }
    else
    {
        string name;
        cout << "enter name: " << endl;
        cin >> name;
        abs->person_array[abs->m_size].m_name = name;

        cout << "sex: 1.Man 2.Woman" << endl;
        int sex=0;
        while(true)
         {
            cin >> sex;
            if(sex==1||sex==2)
             {
                abs->person_array[abs->m_size].m_sex = sex;
                break;
             }
             cout << "enter 1 or 2" << endl;
         }

        cout << "age" << endl;
        int age = 0;
        cin >> age;
        abs->person_array[abs->m_size].m_age = age;

        cout << "phone number" << endl;
        string phone = "";
        cin >> phone;
        abs->person_array[abs->m_size].m_phone = phone;

        cout << "address" << endl;
        string address;
        cin >> address;
        abs->person_array[abs->m_size].m_addr = address;

        abs->m_size++;
        cout << "successfully add a person." << endl;
        //system("clear");
    }
}


void show_person(Addressbooks *abs)
{
    if(abs->m_size==0)
    {
        cout << "no person" << endl;
    }
    else
    {
        for(int i=0;i<abs->m_size;i++)
        {
            cout << "name: " << abs->person_array[i].m_name << endl;
            cout << "sex: " << abs->person_array[i].m_sex << endl;
            cout << "age: " << abs->person_array[i].m_age << endl;
            cout << "phone: " << abs->person_array[i].m_phone << endl;
            cout << "address: " << abs->person_array[i].m_addr << endl;
        }
    }
}


int is_exist(Addressbooks *abs, string name)
{
    for(int i=0;i<abs->m_size;i++)
    {
        if(abs->person_array[i].m_name==name)
        {
            return i;
        }
    }
    return -1;
}

void delete_person(Addressbooks *abs)
{
    cout << "person want to be deleted" << endl;
    string name;
    cin >> name;

    int ret=is_exist(abs,name); //abs here is point
    if(ret != -1)
    {
        for(int i=ret;i<abs->m_size-1;i++)
        {
            abs->person_array[i]=abs->person_array[i+1];
        }
        abs->m_size--;
        cout<<"delete successfully."<<endl;
    }
    else
    {
        cout << "no such person" << endl;
    }
}

void find_person(Addressbooks *abs)
{
    cout << "person to look for" << endl;
    string name;
    cin >> name;

    int ret = is_exist(abs,name);
    if(ret !=-1)
    {
        cout << "name: " << abs->person_array[ret].m_name << endl;
        cout << "sex: " << abs->person_array[ret].m_sex << endl;
        cout << "age: " << abs->person_array[ret].m_age << endl;
        cout << "phone: " << abs->person_array[ret].m_phone << endl;
        cout << "address: " << abs->person_array[ret].m_addr << endl;
    }
    else
    {
        cout << "no such person." << endl;
    }
}




void modify_person(Addressbooks *abs)
{
    cout << "person to modify" << endl;
    string name;
    cin >> name;
    int ret = is_exist(abs,name);

    if(ret !=-1)
    {
        string name;
        cout << "enter name: " << endl;
        cin >> name;
        abs->person_array[ret].m_name = name;

        cout << "sex: 1.Man 2.Woman" << endl;
        int sex=0;
        while(true)
         {
            cin >> sex;
            if(sex==1||sex==2)
             {
                abs->person_array[ret].m_sex = sex;
                break;
             }
             cout << "enter 1 or 2" << endl;
         }

        cout << "age" << endl;
        int age = 0;
        cin >> age;
        abs->person_array[ret].m_age = age;

        cout << "phone number" << endl;
        string phone = "";
        cin >> phone;
        abs->person_array[ret].m_phone = phone;

        cout << "address" << endl;
        string address;
        cin >> address;
        abs->person_array[ret].m_addr = address;

        cout << "successfully modify a person." << endl;
    }
    else
    {
        cout << "no such person" << endl;
    }
}


void clear_person(Addressbooks *abs)
{
    abs->m_size = 0;
    cout << "all clear" << endl;
}

int main()
{
    int select = 0;
    Addressbooks abs;
    abs.m_size = 0;

    while(true)
    {
        show_menu();
        cin >> select;
        switch(select)
        {
        case 1: //add
                add_person(&abs);
                break;
        case 2: //show
                show_person(&abs);
                break;
        case 3: //delete
                delete_person(&abs);
                break;
        case 4: //search
                find_person(&abs);
                break;
        case 5: //modify
                modify_person(&abs);
                break;
        case 6: //clear
                clear_person(&abs);
                break;
        case 0: //exit
                cout << "Bye !" << endl;
                return 0;
                break;
        default:
                break;
        }

    }

    return 0;
}

































