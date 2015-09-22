#include <iostream>
#include <boost/xpressive/xpressive_dynamic.hpp>

int main(){
    using namespace boost::xpressive;

    cregex reg = cregex::compile("a.c");
    assert(regex_match("abc",reg));
    assert(regex_match("a+c",reg));
    assert(!regex_match("ac",reg));
    assert(!regex_match("abd",reg));

    return 0;
}
