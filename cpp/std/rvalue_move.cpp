#include <iostream>
using namespace std;

template<class T>
void mySwap(T& a, T& b){
    T temp(std::move(a));
    temp.print();
    a.print();
    b.print();
    a = std::move(b);
    b = std::move(temp);
    temp.print();
    a.print();
    b.print();
}

struct A{
    public:
        A():m_ptr(new int(0)){
            cout << "Construct : " << m_ptr << endl;
        }
        void print(){
            cout << "Value : " << m_ptr << endl;
        }
        // 深度拷贝
        //A(const A& a):m_ptr(new int(*a.m_ptr)){
        //    cout << "Copy Construct" << endl;
        //}
        // 浅度拷贝
        A(A&& a):m_ptr(a.m_ptr){
            a.m_ptr = nullptr;
        }
        A& operator=(A&& rhs){
            cout << "A::operate=" << endl;
            m_ptr = rhs.m_ptr;
            rhs.m_ptr = nullptr;
            return *this;
        }
        void addptr(){m_ptr ++;}
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
    A a = A();
    A b = A();
    mySwap(a,b);
    return 0;
}
