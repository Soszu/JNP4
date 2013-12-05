#include <typeinfo>
#include <cassert>
#include <iostream>
#include <vector>

#include "holding.hh"

typedef add_comp<Accountancy, add_comp<Exchange_office, Hunting_shop>::type>::type test1;
typedef multiply_comp<test1, 3>::type test2;
typedef remove_comp<test2, add_comp<multiply_comp<Accountancy, 2>::type, Hunting_shop>::type>::type test3;
typedef remove_comp<test2, add_comp<multiply_comp<Accountancy, 5>::type, add_comp<Hunting_shop,multiply_comp<Exchange_office, 5>::type>::type>::type>::type test4;
typedef multiply_comp<test1, 0>::type test5;
typedef multiply_comp<test1, -2>::type test6;
typedef additive_expand_comp<test3>::type test7;
typedef additive_rollup_comp<test3>::type test8;
typedef additive_rollup_comp<test5>::type test9;


int main() {

    using namespace std;
    assert(typeid(Accountancy) != typeid(Exchange_office));
    assert(typeid(Hunting_shop) != typeid(Exchange_office));
    assert(typeid(Accountancy) != typeid(Hunting_shop));
    
    assert(typeid(test1) == typeid(Company<1,1,1>));
    assert(typeid(test2) == typeid(Company<3,3,3>));
    assert(typeid(test3) == typeid(Company<1,2,3>));
    assert(typeid(test4) == typeid(Company<0,2,0>));
    assert(typeid(test5) == typeid(Company<0,0,0>));
    assert(typeid(test6) == typeid(Company<4294967294,4294967294,4294967294>));
    assert(typeid(test7) == typeid(Company<2,3,4>));
    assert(typeid(test8) == typeid(Company<0,1,2>));
    assert(typeid(test9) == typeid(Company<0,0,0>));

}
