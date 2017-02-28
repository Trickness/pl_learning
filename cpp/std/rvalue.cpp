/*
 * g++ -o test rvalue.cpp -std=gnu++14 -fno-elide-constructors
 * */
#include <iostream>
using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;
struct A{
    public:
        A():m_ptr(new int(0)){
            cout << "Construct" << endl;
        }
        // 深度拷贝
        //A(const A& a):m_ptr(new int(*a.m_ptr)){
        //    cout << "Copy Construct" << endl;
        //}
        // 浅度拷贝
        A(const A& a):m_ptr(a.m_ptr){
        }
        ~A(){
            delete m_ptr;
        }
    private:
        int *m_ptr;
};

A GetA(){
    return A();
}

int main(){
    A a = GetA();
    return 0;
}
