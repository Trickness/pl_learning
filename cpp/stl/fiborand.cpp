#include <iostream>
#include <algorithm>    //  Need random_shuffle()
#include <vector>       //  Need vector
#include <functional>   //  Need unary_function
#include <iterator>     //  Need ostream_iterator

using namespace std;

// Data to randomize
int iArray[10] = {1,2,3,4,5,6,7,8,9,10};
vector<int> v(iArray, iArray + 10);

// Function prototype
void Display(vector<int> &vr, const char *s){
    cout << endl << s << endl;
    copy(vr.begin(),vr.end(),ostream_iterator<int>(cout, " "));
    cout << endl;

}

//  The fiboRand template function-object class
template <typename T>
class FiboRand : public unary_function<T,T>{
    public:
        FiboRand(){
            sequence[17] = 1;
            sequence[16] = 2;
            for (int n = 5; n > 0; --n)
                sequence[n] = sequence[n + 1] + sequence[n + 2];
            i = 17;
            j = 5;
        }
        T operator()(const T& arg){
            T k = sequence[i] + sequence[j];
            sequence[i] = k;
            -- i;
            -- j;
            if (i == 0) i = 17;
            if (j == 0) j = 17;
            return k % arg;
        }
    private:
        int i,j;
        T sequence[18];
};

int main(){
    srandom(time(NULL));
    FiboRand<int> fibogen;  // Construct generator object
    cout << "Fibonacci random number generator" << endl;
    cout << "Using random_shuffle and a function object" << endl;
    Display(v,"Before shuffle: ");
    random_shuffle(v.begin(),v.end(),fibogen);
    Display(v,"After shuffle:");
    return 0;
}
