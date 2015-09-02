#include <iostream>
#include <boost/pool/pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <vector>

using namespace std;

int main(){
    vector<int,boost::pool_allocator<int> > v;
    
    v.push_back(10);
    cout << v.size() << endl;
    return 0;
}
