#include <typeinfo>
#include <cassert>
#include <iostream>
#include <vector>

#include "holding.hh"

using namespace std;

int main() {
    
    Group<Company<1, 1, 1> > s1;
    Group<Company<1, 2, 3> > s2(20);    
    
    assert(s1.get_value() == 215);
    assert(s2.get_value() == 9300);

    
    auto s3 = additive_expand_group(s1);
    auto s4 = additive_expand_group(s2);
    
    assert(s3.get_value() == 430);
    assert(s4.get_value() == 13600);

    
    auto s5 = additive_rollup_group(s3);
    auto s6 = additive_rollup_group(s4);
    
    assert(s5.get_value() == 215);
    assert(s6.get_value() == 9300);
    assert(typeid(s5) == typeid(s1));
    assert(typeid(s6) == typeid(s2));
    
    
    auto s7 = multiplicative_expand_group(s1);
    auto s8 = multiplicative_expand_group(s2);
    
    assert(s7.get_value() == 2150);
    assert(s8.get_value() == 93000);
    auto s9 = multiplicative_rollup_group(s7);
    auto s10 = multiplicative_rollup_group(s8);
    
    assert(typeid(s9) == typeid(s1));
    assert(typeid(s10) == typeid(s2));
    
    assert(s9.get_value() == 215);
    assert(s10.get_value() == 9300);

}
