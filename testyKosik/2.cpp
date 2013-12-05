#include <typeinfo>
#include <cassert>
#include <iostream>
#include <vector>

#include "holding.hh"

int main() {
    
  Group<Company<1, 1, 1> > s1;
  Group<Company<1, 2, 3> > s2(20);
  Group<Company<1, 2, 3> > s3(20);
  Group<Company<3, 3, 3> > s4;
  Group<Company<3, 5, 8> > s5(20);

    assert(s1.get_size() == 1);
    assert(s2.get_size() == 20);
    assert(s4.get_size() == 1);
    assert(s5.get_size() == 20);
    
    assert(s1.get_acc_val() == 15);
    assert(s1.get_hs_val() == 150);
    assert(s1.get_exo_val() == 50);
    assert(s2.get_acc_val() ==15);
    assert(s2.get_hs_val() == 150);
    assert(s2.get_exo_val() == 50);
    
    assert(s1.get_value() == 215);
    assert(s2.get_value() == 9300);
    
    s1.set_acc_val(1);
    s1.set_hs_val(2);
    s1.set_exo_val(3);
    s2.set_acc_val(1);
    s2.set_hs_val(2);
    s2.set_exo_val(3);
    
    assert(s1.get_acc_val() == 1);
    assert(s1.get_hs_val() == 2);
    assert(s1.get_exo_val() == 3);
    assert(s2.get_acc_val() == 1);
    assert(s2.get_hs_val() == 2);
    assert(s2.get_exo_val() == 3);
    
    assert(s1.get_value() == 6);
    assert(s2.get_value() == 280);
    
    Group<Company<9, 8, 5> > dupa;
    Group<Company<9, 8, 5> >::company_type taka_sama_dupa;
    
    assert(typeid(dupa.company) == typeid(Company<9, 8, 5>));
    assert(typeid(dupa.company) == typeid(taka_sama_dupa));
    
    Group<Company<1, 2, 3> > x(s2);
    assert(s2.get_value() == x.get_value());
    
    assert(s2.get_acc_val() == x.get_acc_val());
    assert(s2.get_hs_val() == x.get_hs_val());
    assert(s2.get_exo_val() == x.get_exo_val());
    
  /*assert((s2 + s3).get_size() == 40);
  assert((s2 += s2).get_size() == 40);
  assert(s2.get_size() == 40);
  assert((s2 - s3).get_size() == 20);
  assert((s3 - s2).get_size() == 0);

  s3.set_exo_val(25);


  assert((s2 + s3).get_value() == 139200);
  assert((s2 - s3).get_value() == 60000);
  assert((s2 * 4).get_value() == 97600);
  assert((s2 / 2).get_value() == 100000);*/


}
