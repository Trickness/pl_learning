#include <iostream>
#include <typeinfo>

using namespace std;

template<class T>
void foo(T&& t){
}

template<class T>
void fwd(T&& t){
    foo(t);
}

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
        A(A&& a):m_ptr(a.m_ptr){
        }
        ~A(){
            cout << "Deleted" << endl;
            cout << m_ptr << endl;
            if(m_ptr)
                delete m_ptr;
        }
    private:
        int *m_ptr;
};

int main(){
    auto a = A();
    fwd(a);
}