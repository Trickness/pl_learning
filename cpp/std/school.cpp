#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a, b, c;
    cout << "请输入三个数:" << endl;
    cin >> a >> b >> c;
    if(a + b > c && a + c > b && b + c > a){
        cout << "能构成三角形" << endl;
        if(a == b && b == c)
            cout << "它是等边三角形" << endl;
        else if(a == b || a == c || b == c)
            cout <<"它是等腰三角形" << endl;
        if(	pow(a,2) + pow(b,2) == pow(c,2) ||
			pow(a,2) + pow(c,2) == pow(b,2) ||
		   	pow(b,2) + pow(c,2) == pow(a,2))
            cout << "它是直角三角形" << endl;
    }else
        cout << "不能构成三角形" << endl;
    return 0;
}