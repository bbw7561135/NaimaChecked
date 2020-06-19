#include<iostream>
#include<cmath>
using namespace std;

double dist(double x, double y)
{
    return sqrt(x*x+y*y);
}


void init_array(double v[], int n)
{
    for(int i=0; i<n; i++)
        v[i] = i*i*1.0;
}

void print_array(double v[], int n)
{
    for(int i=0; i<n; i++)
        cout << v[i] << endl;
}


double sum_array(double v[], int n)
{
    double result = 0.0;
    for(int i=0; i<n; i++)
        result = result + v[i];
    return result;
}


int main()
{
//    cout << "Hello World !" << endl;
//    const string question="Who are you?";
//    const string greeting="Hi ";
//    const string bye="Bye!";
//    string name;
//    cout << "Type quit or press Ctrl+D to exit" << endl;
//    cout << question << endl;
//    while(cin>>name)
//    {
//        if(name=="quit")
//            break;
//        cout << greeting << name << "!" << endl;
//    }
//    cout << bye << endl;
//    cout << dist(4.0,3.0) << endl;
//    string line;
//    double sum = 0.0;
//    getline(cin,line,'#');//# is the stop flag
//    sum=sum+stof(line);
//    cout << "sum=" << sum << endl;

//    const int n = 10;
//    double v[n];
//    init_array(v,n);
//    print_array(v,n);
//    cout << "sum is " << sum_array(v,n) << endl;










    return 0;
}
























