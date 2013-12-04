#include <iostream>

typedef unsigned int Quantity;


template <Quantity C1 = 0, Quantity C2 = 0, Quantity C3 = 0> 
struct Company {
    static const Quantity acc_ = C1;
    static const Quantity hun_ = C2;
    static const Quantity exc_ = C3;
};

typedef Company<1, 0, 0> Accountancy;
typedef Company<0, 1, 0> Hunting_shop;
typedef Company<0, 0, 1> Exchange_office;

template< class C1, class C2 > struct add_comp {
	typedef Company < C1::acc_ + C2::acc_, C1::hun_ + C2::hun_, C1::exc_ + C2::exc_ > type;
};

template< class C1, class C2 > struct remove_comp {
	typedef Company < C1::acc_ <
	C2::acc_ ? 0 : C1::acc_ - C2::acc_,
	C1::hun_ < C2::hun_ ? 0 : C1::hun_ - C2::hun_,
	C1::exc_ < C2::exc_ ? 0 : C1::exc_ - C2::exc_ > type;
};

template<class C, unsigned int n> struct multiply_comp {
	typedef Company < C::acc_ * n, C::hun_ * n, C::exc_ * n > type;
};

template<class C, unsigned int n> struct split_comp {
	typedef Company < n == 0 ? 0 : C::acc_ / n, n == 0 ? 0 : C::hun_ / n, n == 0 ? 0 : C::exc_ / n > type;
};

template<class C> struct additive_expand_comp {
	typedef Company < C::acc_ + 1, C::hun_ + 1, C::exc_ + 1 > type;
};

template<class C> struct additive_rollup_comp {
	typedef Company < C::acc_ == 0 ? 0 : C::acc_ - 1, C::hun_ == 0 ? 0 : C::hun_ - 1, C::exc_ == 0 ? 0 : C::exc_ - 1 > type;
};

template<class Company> class Group;
template <class Company > std::ostream& operator<<(std::ostream &out, const Group < Company > &company);

// co do tych funkcji to nie jestem pewien, jak maja dzialac, ale chyba "funkcyjnie", czyli tworza nowa grupe z nowym typem i wartosciami z s1
template<class C> Group<typename additive_expand_comp<C>::type> const additive_expand_group(Group<C> const &s1);
template<class C> Group<typename multiply_comp<C, 10>::type> const multiplicative_expand_group(Group<C> const &s1);
template<class C> Group<typename additive_rollup_comp<C>::type> const additive_rollup_group(Group<C> const &s1);
template<class C> Group<typename split_comp<C, 10>::type> const multiplicative_rollup_group(Group<C> const &s1);
template<class C1, class C2, class C3> bool solve_auction(Group<C1> const &g1, Group<C2> const &g2, Group<C3> const &g3);


template<class Company> class Group
{
private:
	Quantity size; // liczba firm
	
	Quantity acc_val;
	Quantity hs_val;
	Quantity exo_val;
public:
	friend std::ostream& operator<< <> (std::ostream &out, const Group < Company > &company);
	/*
	 szczerze nie wiem jak to zafriendowac, to sypie bledami kompilacji, masz jakis pomysl?
	 Group<typename additive_expand_comp<Company>::type> <> const additive_expand_group(Group<Company> const &s1);*/
	
	static Company company;
	typedef Company company_type;

	Group();
	Group(Group < Company > const &C);
	unsigned int get_size() const;
	
	void set_acc_val(unsigned int i);
	void set_hs_val(unsigned int i);
	void set_exo_val(unsigned int i);
	
	unsigned int get_value() const;
	
	// zerknij do tresci jak maja sie zmieniac wartosci przedsiebiorstw po wykonaniu operatorow
	Group < Company > operator+(Group < Company > company) const;
	Group < Company > operator-(Group < Company > company) const;
	Group < Company > operator+=(Group < Company > company);
	Group < Company > operator-=(Group < Company > company);
	
	bool operator==(Group < Company > company) const;
	bool operator!=(Group < Company > company) const;
	bool operator<(Group < Company > company) const;
	bool operator>(Group < Company > company) const;
	bool operator<=(Group < Company > company) const;
	bool operator>=(Group < Company > company) const;
};

int main()
{
}
