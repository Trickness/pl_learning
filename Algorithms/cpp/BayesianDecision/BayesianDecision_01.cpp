#include <iostream>
#include <cstdio>
using namespace std;

struct income_risk{
    int income;
    bool risk;
};
// BUG?
int main(){
    // simply the incomes <-> risk relationship
    freopen("data.txt","r",stdin);
    int N = 0;
    int tmp;
    cin >> N;
    income_risk* data = new income_risk[N];
    for (int i = 0; i < N; ++i){
        cin >> data[i].income ;
        cin >> tmp;
        if(tmp == 1)    data[i].risk = true;
        else            data[i].risk = false;
    }
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        // P(C = 1)
        float rate_c_1 = [](int N, income_risk* data)->float{
            float result = 0;
            for(int i = 0; i < N; ++i){
                if(data[i].risk){
                    ++ result;
                }
            }
            return result/N;
        }(N,data);
        // P(x_1|C)
        float rate_x_c_1 = [](int N, income_risk* data, int x)->float{
            float result = 0;
            float total = 0;
            for(int i = 0; i < N; ++i)
                if(data[i].risk){
                    if(data[i].income > x)
                        ++ result;
                    ++total;
                }
            return result/total;
        }(N,data,tmp);
        // P(x_1)
        float rate_x = [](int N, income_risk* data, int x,float rate_c_1)->float{
            float x_c_1 = 0;
            float x_c_0 = 0;
            for(int i = 0; i < N; ++i){
                if(data[i].income > x){
                    if(data[i].risk)
                        ++ x_c_1;
                    else
                        ++ x_c_0;
                }
            }
            return (x_c_1/N)*rate_c_1 + (x_c_0/N)*(1-rate_c_1);
        }(N,data,tmp,rate_c_1);
        cout << rate_x << endl;
    }
    return 0;
}