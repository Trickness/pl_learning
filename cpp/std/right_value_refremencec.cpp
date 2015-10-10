#include <iostream>

using namespace std;

class test_class{
    public:
        test_class(){};
        const int& len(){
            return this->length;
        }
        void change_len(int x){
            this->length = x;
        }
        int length;
};

int main(){
    int x = 1;
    int &y = x;
    y = 2;
    cout << x << endl;
    test_class c;
    c.change_len(2);
    const int &z = c.len();
    cout << z << endl;
    c.change_len(4);
    cout << z << endl;
}
