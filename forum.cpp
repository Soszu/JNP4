/* Testy do zadania holding
 * wszystko co bylo na forum
 * 5.12.2013 o 15:36 */
// linie oznaczone FIXME maja wywolywac blad kompilacji
// jesli nie odpalamy w folderze private to nie trzeba zmienic
#include "holding.hh"

#include <typeinfo>
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

typedef stringstream sstr;

void testy_dziwne_zalozenia_na_dzien_dobry() {
    cout << "Testy dziwne zalozenie:\t";
    // zdaje sie, ze nikt nie powiedzial, ze tak to mamy parametryzowac,
    // ale zdaje sie, ze na forum to pojawia sie w testach jako
    // "niejawen" zalozenie
    assert(typeid(Company<1, 0, 0>) == typeid(Accountancy));
    assert(typeid(Company<0, 1, 0>) == typeid(Hunting_shop));
    assert(typeid(Company<0, 0, 1>) == typeid(Exchange_office));
    cout << "OK" << endl;
}

void testy_z_tresci() {
    cout << "Testy z tresci:\t";
    sstr out;
    typedef add_comp<Accountancy, Exchange_office>::type small_company;
    typedef add_comp<multiply_comp<Hunting_shop, 10>::type, multiply_comp<Exchange_office, 20>::type>::type money;
    typedef add_comp<multiply_comp<Hunting_shop, 30>::type, multiply_comp<Exchange_office, 10>::type>::type guns;

  Group<Accountancy> s1;
  Group<money> s2(20);
  Group<money> s3(20);
  Group<Exchange_office> s4;
  Group<guns> s5(20);

  assert((s2 + s3).get_size() == 40);
  assert((s2 += s2).get_size() == 40);
  assert(s2.get_size() == 40);
  assert((s2 - s3).get_size() == 20);
  assert((s3 - s2).get_size() == 0);

  s3.set_exo_val(25);

  out << s2;
  out << s3;
  out << s2 + s3;
  out << s2 - s3;
  out << s2 * 4;
  out << s2 / 2;

  assert((s2 + s3).get_value() == 139200);
  assert((s2 - s3).get_value() == 60000);
  assert((s2 * 4).get_value() == 97600);
  assert((s2 / 2).get_value() == 100000);

  assert(s2 > s3);
  assert(s1 != s4);
  assert(s1 == s1);

  assert(typeid(add_comp<Accountancy, Exchange_office>::type) == typeid(small_company));
  assert(typeid(remove_comp<small_company, Accountancy>::type) == typeid(Exchange_office));
  assert(typeid(split_comp<small_company, 2>::type) == typeid(Company<0, 0, 0>));
  assert(typeid(additive_rollup_comp<multiply_comp<small_company, 2>::type>::type) ==
         typeid(small_company));
  assert(typeid(additive_expand_comp<small_company>::type) ==
         typeid(add_comp<Hunting_shop, multiply_comp<small_company, 2>::type>::type));

  assert(typeid(Group<add_comp<Accountancy, Exchange_office>::type>::company_type) ==
         typeid(small_company));
  assert(typeid(additive_expand_group(s1).company) ==
         typeid(add_comp<multiply_comp<Accountancy, 2>::type,
                add_comp<Hunting_shop, Exchange_office>::type>::type));
  assert(typeid(additive_rollup_group(s1).company) == typeid(Company<0,0,0>));
  assert(typeid(multiplicative_expand_group(s1).company) ==
         typeid(multiply_comp<Accountancy, 10>::type));
  assert(typeid(multiplicative_rollup_group(s5).company) ==
         typeid(add_comp<multiply_comp<Hunting_shop, 3>::type, Exchange_office>::type));

  assert(solve_auction(s1, s2, s5) == false);

//Powyższy przykład wypisuje na standardowe wyjście:

    stringstream exp;
// Poprawiony output
/*
 *
Odp: Zadanie 4
Bartosz Rybicki w dniu Monday, 2 December 2013, 09:16 napisał(a)

Niestety w przykładzie zamieszczonym pod zadaniem znalazł się pewien błąd, poprawny output wygląda w sposób następujący:
*/
    exp << "Number of companies: 40; Value: 100000" << endl;
    exp << "Accountancies value: 0, Hunting shops value: 150, Exchange offices value: 50" << endl;
    exp << "Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;
    exp << "Number of companies: 20; Value: 40000" << endl;
    exp << "Accountancies value: 15, Hunting shops value: 150, Exchange offices value: 25" << endl;
    exp << "Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;
    exp << "Number of companies: 60; Value: 139200" << endl;
    exp << "Accountancies value: 0, Hunting shops value: 150, Exchange offices value: 41" << endl;
    exp << "Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;
    exp << "Number of companies: 20; Value: 60000" << endl;
    exp << "Accountancies value: 0, Hunting shops value: 150, Exchange offices value: 75" << endl;
    exp << "Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;
    exp << "Number of companies: 160; Value: 97600" << endl;
    exp << "Accountancies value: 0, Hunting shops value: 37, Exchange offices value: 12" << endl;
    exp << "Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;
    exp << "Number of companies: 20; Value: 100000" << endl;
    exp << "Accountancies value: 0, Hunting shops value: 300, Exchange offices value: 100" << endl;
    exp << "Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;

//  cout << exp.str() << endl << out.str() << endl;
    assert(exp.str() == out.str());


    cout << "OK" << endl;
}

void testy_z_forum() {
    cout << "Testy z forum:\t";

// Sunday, 1 December 2013, 18:04
    {
        Group<Accountancy> g1;
        Group<Hunting_shop> g2;
        Group<Exchange_office> g3;
//        g1 += g2; // FIXME Dodawanie grup roznych typow
    }

// Monday, 2 December 2013, 13:34
    {

     assert(typeid(Company<1, 0, 0>) == typeid(Accountancy));
    Group<Company<0,1,1>>a;
    Group<Company<0,2,1>>b;
    Group<Company<0,1,1>>c;
    Group<Company<0,2,2>>d;

    assert(a<b);
    assert(!(a==b));
    assert(a<=b);
    assert(a<=c);
    assert(a<=d);
    }

// Saturday, 30 November 2013, 10:01
    {
    stringstream out, exp;
     //1. Jeśli chodzi o multipliy_comp to powinny zachodzić następujące równości:

    typeid(multiply_comp<Hunting_shop,1>::type)==typeid(Company<0,1,0>);
    typeid(multiply_comp<Hunting_shop,0>::type)==typeid(Company<0,0,0>);
    //2. Jeśli chodzi o split_comp to powinny zachodzić następujące równości:
    typeid(split_comp<Hunting_shop,1>::type)==typeid(Company<0,1,0>);
    typeid(split_comp<Hunting_shop,0>::type)==typeid(Company<0,0,0>);
    //3. Następujący kod:
    typedef Company<0,2,2> one;
    typedef Company<1,1,1> two;

    typedef remove_comp<one,two>::type one_two;
    Group<one_two>rc(1);
    out<<rc;
    //Wypisuje na standardowe wyjście:
    exp << "Number of companies: 1; Value: 200" << endl;
    exp << "Accountancies value: 15, Hunting shops value: 150, Exchange offices value: 50" << endl;
    exp << "Accountancies: 0, Hunting shops: 1, Exchange offices: 1" << endl;
//    cout << exp.str() << endl << out.str() << endl;
    assert(exp.str() == out.str());
    //4. Mają zachodzić następujące nierówności:

    typeid(additive_rollup_comp<Company<2,1,1>>::type)==typeid(Company<1,0,0>);
    typeid(remove_comp<Company<2,1,1>,Company<1,1,1>>::type)==typeid(Company<1,0,0>);
    }

// Saturday, 30 November 2013, 05:41
    {
        Group<Accountancy> s1(20);
        Group<Accountancy> s2(10);
        s1.set_acc_val(10);
        s2.set_acc_val(100);
        auto s3 = (s1 - s2);
        assert(s3.get_acc_val() == 0);
    }
//  Saturday, 30 November 2013, 20:19
    {
        Group<Exchange_office> a;
        Group<Hunting_shop> b;
        assert((a < b) == false);
        assert((a > b) == false);
        assert((a == b) == false);
        assert((a != b) == true);
    }
// Saturday, 30 November 2013, 21:51
    {
        stringstream out, exp;
    typedef add_comp<multiply_comp<Hunting_shop, 10>::type, multiply_comp<Exchange_office, 20>::type>::type money;

    Group<money> s2(20);
    Group<money> s3(20);

    s2.set_acc_val(20);
    s3.set_acc_val(30);

    out << (s2 + s3).get_acc_val() << endl << (s2 + s3);
    exp << 0 << endl
 << "Number of companies: 40; Value: 100000" << endl
 << "Accountancies value: 0, Hunting shops value: 150, Exchange offices value: 50" << endl
        <<"Accountancies: 0, Hunting shops: 10, Exchange offices: 20" << endl;
//    cout << out.str() << " " << exp.str() << endl;
    assert(exp.str() == out.str());
}
// Monday, 2 December 2013, 12:45
{

    typedef add_comp<Accountancy, Exchange_office>::type small_company;
    typedef multiply_comp<small_company, 1000>::type big_company;

    Group<big_company> s0(100);
    s0.set_exo_val(UINT_MAX/100000);
    s0.set_acc_val(0);
    assert(s0.get_value() == 4294900000);//jeszcze nie overflow
    s0.set_acc_val(1);
    assert(s0.get_value() == 32704);//na students jest to overflow
}

// Wednesday, 4 December 2013, 18:28
{
    Group<Company<1, 0, 0> > a(20);
    Group<Company<1, 0, 0> > b(10);
    assert(!(a < b));
    assert(!(a <= b));
    assert(a > b);
    assert(a >= b);
    assert(!(a == b));
}

// Thursday, 5 December 2013
{
    Group<Company<1,0,0>>a(20);
    Group<Company<2,0,0>>b(10);

    assert(!(a<b));
    assert(a<=b);
    assert(!(a>b));
    assert(a>=b);
    assert(a==b);
}
//  Wednesday, 4 December 2013, 22:25
{
    Group<Exchange_office>a(20);
    assert((a * 0).get_exo_val() == 0);
    assert((a * 0).get_size() == 0);
    assert((a / 0).get_exo_val() == 0);
    assert((a / 0).get_size() == 0);
}

    cout << "OK" << endl;

}

int main() {
    testy_dziwne_zalozenia_na_dzien_dobry();
    testy_z_tresci();
    testy_z_forum();

    cout << "Wszystko OK" << endl;
    return 0;
}
