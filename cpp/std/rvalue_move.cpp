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
    private:
        int *m_ptr;
        char name;
    public:
        A(char name):m_ptr(new int(0)),name(name){
            cout << name << " -- Construct : " << m_ptr << endl;
        }
        void print(){
            cout << name << " -- Value : " << m_ptr << endl;
        }
        A(A&& a):m_ptr(a.m_ptr){
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
            cout << name << " -- Deleted" << endl;
            cout << m_ptr << endl;
            if(m_ptr)
                delete m_ptr;
        }
};

int main(){
    A a = A('a');
    A b = A('b');
    mySwap(a,b);
}
