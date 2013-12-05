#include <typeinfo>
#include <cassert>
#include <iostream>
#include <vector>

#include "holding.hh"

using namespace std;

int main() {
    
    Group<Company<1, 1, 1> > s1;
    Group<Company<1, 2, 3> > s2(20);
    Group<Company<1, 2, 3> > s3(10);
    Group<Company<1, 2, 3> > s4(50);
    
    s4.set_acc_val(5);
    s4.set_hs_val(7);
    s4.set_exo_val(6);

    Group<Company<1, 2, 3> > t1 = s2 + s3;
    Group<Company<1, 2, 3> > t2 = s3 + s2;
    Group<Company<1, 2, 3> > t3 = s2 - s3;
    Group<Company<1, 2, 3> > t4 = s3 - s2;
    
    Group<Company<1, 2, 3> > t5 = s2 + s4;
    Group<Company<1, 2, 3> > t6 = s4 + s2;
    Group<Company<1, 2, 3> > t7 = s2 - s4;
    Group<Company<1, 2, 3> > t8 = s4 - s2;
    
    Group<Company<1, 2, 3> > t11(0);
    Group<Company<1, 2, 3> > t12(0);
    Group<Company<1, 2, 3> > t13(0);
    Group<Company<1, 2, 3> > t14(0);
    Group<Company<1, 2, 3> > t15(0);
    Group<Company<1, 2, 3> > t16(0);
    Group<Company<1, 2, 3> > t17(0);
    Group<Company<1, 2, 3> > t18(0);
    
    Group<Company<1, 2, 3> > t21(50);
    Group<Company<1, 2, 3> > t22(50);
    Group<Company<1, 2, 3> > t23(50);
    Group<Company<1, 2, 3> > t24(50);
    Group<Company<1, 2, 3> > t25(50);
    Group<Company<1, 2, 3> > t26(50);
    Group<Company<1, 2, 3> > t27(50);
    Group<Company<1, 2, 3> > t28(50);
    
    t11 += t1;
    t12 += t2;
    t13 += t3;
    t14 += t4;
    t15 += t5;
    t16 += t6;
    t17 += t7;
    t18 += t8;
    
    s2.set_acc_val(5);
    s2.set_hs_val(7);
    s2.set_exo_val(6);
    
    t21 -= t1;
    t22 -= t2;
    t23 -= t3;
    t24 -= t4;
    t25 -= t5;
    t26 -= t6;
    t27 -= t7;
    t28 -= t8;
    
    assert(t1.get_value() == 13950);
    assert(t2.get_value() == 13950);
    assert(t3.get_value() == 4650);
    assert(t4.get_value() == 0);
    assert(t5.get_value() == 10850);
    assert(t6.get_value() == 10850);
    assert(t7.get_value() == 0);
    assert(t8.get_value() == 0);
    
    assert(t11.get_value() == 13950);
    assert(t12.get_value() == 13950);
    assert(t13.get_value() == 4650);
    assert(t14.get_value() == 0);
    assert(t15.get_value() == 10850);
    assert(t16.get_value() == 10850);
    assert(t17.get_value() == 0);
    assert(t18.get_value() == 0);
    
    assert(t21.get_value() == 9300);
    assert(t22.get_value() == 9300);
    assert(t23.get_value() == 18600);
    assert(t24.get_value() == 23250);
    assert(t25.get_value() == 0);
    assert(t26.get_value() == 0);
    assert(t27.get_value() == 23250);
    assert(t28.get_value() == 23240);
    
    Group<Company<1, 1, 1> > t31;
    Group<Company<1, 2, 3> > t32(20);
    Group<Company<1, 2, 3> > t33(50);
    
    Group<Company<1, 1, 1> > t34(0);
    Group<Company<1, 2, 3> > t35(0);
    Group<Company<1, 2, 3> > t36(0);
    
    Group<Company<1, 1, 1> > t37(t31);
    Group<Company<1, 2, 3> > t38(t32);
    Group<Company<1, 2, 3> > t39(t33);
    
    t33.set_acc_val(5);
    t33.set_hs_val(7);
    t33 .set_exo_val(6);
    
    t34 = t31 * 8;
    t35 = t32 * 8;
    t36 = t33 * 8;
    t37 *= 8;
    t38 *= 8;
    t39 *= 8;
    
    assert(t31.get_value() == 215);
    assert(t32.get_value() == 9300);
    assert(t33.get_value() == 1850);
    assert(t34.get_value() == 200);
    assert(t35.get_value() == 8800);
    assert(t36.get_value() == 0);
    assert(t37.get_value() == 200);
    assert(t38.get_value() == 8800);
    assert(t39.get_value() == 22000);
    
    t37 *= -1;
    t38 *= -1;
    t39 *= -1;
    
    assert(t37.get_value() == 0);
    assert(t38.get_value() == 0);
    assert(t39.get_value() == 0);
    
    t34 = t31 * 0;
    t35 = t32 * 0;
    t36 = t33 * 0;
    assert(t34.get_value() == 0);
    assert(t35.get_value() == 0);
    assert(t36.get_value() == 0);
    
    
    Group<Company<1, 1, 1> > t41;
    Group<Company<1, 2, 3> > t42(20);
    Group<Company<1, 2, 3> > t43(50);
    
    Group<Company<1, 1, 1> > t44(0);
    Group<Company<1, 2, 3> > t45(0);
    Group<Company<1, 2, 3> > t46(0);
    
    Group<Company<1, 1, 1> > t47(t41);
    Group<Company<1, 2, 3> > t48(t42);
    Group<Company<1, 2, 3> > t49(t43);
    
    t43.set_acc_val(5);
    t43.set_hs_val(7);
    t43 .set_exo_val(6);
    
    t44 = t41 / 8;
    t45 = t42 / 8;
    t46 = t43 / 8;
    t47 /= 8;
    t48 /= 8;
    t49 /= 8;
    
    assert(t41.get_value() == 215);
    assert(t42.get_value() == 9300);
    assert(t43.get_value() == 1850);
    assert(t44.get_value() == 0);
    assert(t45.get_value() == 7440);
    assert(t46.get_value() == 1776);
    assert(t47.get_value() == 0);
    assert(t48.get_value() == 7440);
    assert(t49.get_value() == 22320);
    
    t47 /= -1;
    t48 /= -1;
    t49 /= -1;
    
    assert(t47.get_value() == 0);
    assert(t48.get_value() == 0);
    assert(t49.get_value() == 0);
    
    t44 = t41 / 0;
    t45 = t42 / 0;
    t46 = t43 / 0;
    assert(t44.get_value() == 0);
    assert(t45.get_value() == 0);
    assert(t46.get_value() == 0);
}
