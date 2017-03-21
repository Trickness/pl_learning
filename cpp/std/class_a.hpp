#include <iostream>
using namespace std;

struct A{
    private:
        int *m_ptr;
        char name;
    public:
        A():m_ptr(nullptr),name('t'){
            cout << name << " -- Construct : Temporary Object" << endl;
        }
        A(char name):m_ptr(new int(0)),name(name){
            cout << name << " -- Construct : " << m_ptr << endl;
        }
        void print(){
            cout << name << " -- Value     : " << m_ptr << endl;
        }
        A(A&& a):m_ptr(a.m_ptr),name(a.name){
            a.m_ptr = nullptr;
        }
        A& operator=(A&& rhs){
            cout << name << " -- A::operate=" << endl;
            m_ptr = rhs.m_ptr;
            name = rhs.name;
            rhs.m_ptr = nullptr;
            return *this;
        }
        ~A(){
            cout << name << " -- Deleted   : " << m_ptr << endl;
            if(m_ptr)
                delete m_ptr;
        }
};
