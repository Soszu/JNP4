#include <typeinfo>
#include <cassert>
#include <iostream>
#include <vector>

#include "holding.hh"

using namespace std;

int main() {
    
    Group<Company<1, 1, 1> > s1, s2(2);
    Group<Company<1, 2, 3> > s3, s4(2);
    Group<Company<100, 3, 2> > s5, s6(2);
    Group<Company<1, 0, 0> > s7, s8(2);
    Group<Company<100, 2, 3> > s9;
    
    assert(s1 < s2);
    assert(s3 < s4);
    assert(s5 < s6);
    
    assert(s1 <= s2);
    assert(s3 <= s4);
    assert(s5 <= s6);
    
    assert(s1 != s2);
    assert(s3 != s4);
    assert(s5 != s6);
    
    assert(s1 < s3);
    assert(s1 < s4);
    assert(s1 < s5);
    
    assert(!(s3 < s5));
    assert(!(s5 < s3));
    assert(!(s3 <= s5));
    assert(!(s5 <= s3));
    
    assert(!(s4 < s6));
    assert(!(s6 < s4));
    assert(!(s4 <= s6));
    assert(!(s6 <= s4));
    
    assert(s3 < s6);
    assert(s5 < s4);
    
    assert((s1*2) == s2);
    assert(!((s1*2) != s2));
    
    assert(s9 == s3);   
    assert(s7 < s8);
    assert(s7 <= s8);
    assert(!(s7 >= s8));
    assert(!(s7 > s8));
    assert(s7 != s8);
}
