/*
 *JNP, zadanie 4
 *Rafał Soszyński i Krzysztof Stopczański
 *rs335786+ks335802
 */

#include <iostream>

typedef unsigned int Quantity;


template <Quantity C1 = 0, Quantity C2 = 0, Quantity C3 = 0>
struct Company {
	static constexpr Quantity acc_ = C1;
	static constexpr Quantity hs_ = C2;
	static constexpr Quantity exo_ = C3;
};

typedef Company<1, 0, 0> Accountancy;
typedef Company<0, 1, 0> Hunting_shop;
typedef Company<0, 0, 1> Exchange_office;

template< class C1, class C2 >
struct add_comp {
	typedef Company < C1::acc_ + C2::acc_,
		          C1::hs_ + C2::hs_,
		          C1::exo_ + C2::exo_ > type;
};

template< class C1, class C2 >
struct remove_comp {
	typedef Company < C1::acc_ < C2::acc_ ? 0 : C1::acc_ - C2::acc_,
		          C1::hs_ < C2::hs_ ? 0 : C1::hs_ - C2::hs_,
		          C1::exo_ < C2::exo_ ? 0 : C1::exo_ - C2::exo_ > type;
};

template<class C, unsigned int n>
struct multiply_comp {
	typedef Company < C::acc_ * n,
		          C::hs_ * n,
		          C::exo_ * n > type;
};

template<class C, unsigned int n>
struct split_comp {
	typedef Company < n == 0 ? 0 : C::acc_ / n,
		          n == 0 ? 0 : C::hs_ / n,
		          n == 0 ? 0 : C::exo_ / n > type;
};

template<class C>
struct additive_expand_comp {
	typedef Company < C::acc_ + 1,
		          C::hs_ + 1,
		          C::exo_ + 1 > type;
};

template<class C>
struct additive_rollup_comp {
	typedef Company < C::acc_ == 0 ? 0 : C::acc_ - 1,
		          C::hs_ == 0 ? 0 : C::hs_ - 1,
		          C::exo_ == 0 ? 0 : C::exo_ - 1 > type;
};

template<class Company>
class Group;

template <class C >
std::ostream& operator<<(std::ostream &out, const Group <C> &group) {
	out << "Number of companies: " << group.get_size() << "; "
	    << "Value: " << group.get_value() <<"\n"
	    << "Accountancies value: " << group.get_acc_val() << ", "
	    << "Hunting shops value: " << group.get_hs_val() << ", "
	    << "Exchange offices value: " <<group.get_exo_val() << "\n"
	    << "Accountancies: " << C::acc_ << ", "
	    << "Hunting shops: " << C::hs_ << ", "
	    << "Exchange offices: " << C::exo_ <<"\n";
	return out;
}

template<class C>
Group<typename additive_expand_comp<C>::type> const additive_expand_group(Group<C> const &s1) {
	Group<typename additive_expand_comp<C>::type> result(s1.get_size());
	result.set_acc_val(s1.get_acc_val());
	result.set_hs_val(s1.get_hs_val());
	result.set_exo_val(s1.get_exo_val());
	return result;
}

template<class C>
Group<typename multiply_comp<C, 10>::type> const multiplicative_expand_group(Group<C> const &s1) {
	Group<typename multiply_comp<C, 10>::type> result(s1.get_size());
	result.set_acc_val(s1.get_acc_val());
	result.set_hs_val(s1.get_hs_val());
	result.set_exo_val(s1.get_exo_val());
	return result;
}

template<class C>
Group<typename additive_rollup_comp<C>::type> const additive_rollup_group(Group<C> const &s1) {
	Group<typename additive_rollup_comp<C>::type> result(s1.get_size());
	result.set_acc_val(s1.get_acc_val());
	result.set_hs_val(s1.get_hs_val());
	result.set_exo_val(s1.get_exo_val());
	return result;
}

template<class C>
Group<typename split_comp<C, 10>::type> const multiplicative_rollup_group(Group<C> const &s1) {
	Group<typename split_comp<C, 10>::type> result(s1.get_size());
	result.set_acc_val(s1.get_acc_val());
	result.set_hs_val(s1.get_hs_val());
	result.set_exo_val(s1.get_exo_val());
	return result;
}

template<class C1, class C2, class C3>
bool solve_auction(Group<C1> const &g1, Group<C2> const &g2, Group<C3> const &g3)
{
	return (g1 > g2 && g1 > g3)
	        || (g2 > g1 && g2 > g3)
	        || (g3 > g1 && g3 > g2);
}


template<class C> class Group
{
private:
	Quantity size;

	Quantity acc_val;
	Quantity hs_val;
	Quantity exo_val;

	Quantity weightedMeanAdd(Quantity lhs_value, Quantity lhs_qty, Quantity rhs_value, Quantity rhs_qty) {
		Quantity nominator = lhs_qty * lhs_value + rhs_qty * rhs_value;
		Quantity denominator = lhs_qty + rhs_qty;
		return (denominator == 0 ? 0 : nominator / denominator);
	}
	Quantity weightedMeanSub(Quantity lhs_value, Quantity lhs_qty, Quantity rhs_value, Quantity rhs_qty) {
		Quantity nominator = 0;
		if (lhs_qty * lhs_value > rhs_qty * rhs_value)
			nominator = lhs_qty * lhs_value - rhs_qty * rhs_value;

	Quantity denominator = 0;
		if (lhs_qty > rhs_qty)
			denominator = lhs_qty - rhs_qty;
	return (denominator == 0 ? 0 : nominator / denominator);
	}
public:
	friend std::ostream& operator<< <> (std::ostream &out, const Group <C> &group);

	typedef C company_type;
	static constexpr company_type company = C();

	Group() : size(1), acc_val(15), hs_val(150), exo_val(50) {}
	Group(Quantity k) : Group{} {size = k;}
	Group(Group <C> const &G) : size(G.size), acc_val(G.acc_val), hs_val(G.hs_val), exo_val(G.exo_val) {}

	unsigned int get_size() const {
		return size;
	}

	void set_acc_val(unsigned int i) {
		acc_val = i;
	}
	void set_hs_val(unsigned int i) {
		hs_val = i;
	}
	void set_exo_val(unsigned int i) {
		exo_val = i;
	}

	unsigned int get_acc_val() const {
		return acc_val;
	}
	unsigned int get_hs_val() const {
		return hs_val;
	}
	unsigned int get_exo_val() const {
		return exo_val;
	}

	unsigned int get_value() const {
		return size *(C::acc_ * acc_val + C::hs_ * hs_val + C::exo_ * exo_val);
	}

	Group <C> operator+(Group <C> group) const {
		Group <C> result(*this);
		return (result+= group);
	}
	Group <C> operator-(Group <C> group) const {
		Group <C> result(*this);
		return (result-= group);
	}
	Group <C> & operator+=(Group <C> group) {
		acc_val = weightedMeanAdd(acc_val, C::acc_ * size, group.get_acc_val(), C::acc_ * group.get_size());
		hs_val = weightedMeanAdd(hs_val, C::hs_ * size, group.get_hs_val(), C::hs_ * group.get_size());
		exo_val = weightedMeanAdd(exo_val, C::exo_ * size, group.get_exo_val(), C::exo_ * group.get_size());
		size+= group.get_size();
		return *this;
	}
	Group <C> & operator-=(Group <C> group) {
		acc_val = weightedMeanSub(acc_val, C::acc_ * size, group.get_acc_val(), C::acc_ * group.get_size());
		hs_val = weightedMeanSub(hs_val, C::hs_ * size, group.get_hs_val(), C::hs_ * group.get_size());
		exo_val = weightedMeanSub(exo_val, C::exo_ * size, group.get_exo_val(), C::exo_ * group.get_size());
		size = size > group.get_size() ? size - group.get_size() : 0;
		return *this;
	}

	Group <C> & operator*=(unsigned int n) {
		size*= n;
		for (auto i : {&acc_val, &hs_val, &exo_val})
			n == 0 ? (*i) = 0 : (*i)/= n;
		return *this;
	}
	Group <C> & operator/=(unsigned int n) {
		n == 0 ? size = 0 : size/= n;
		for (auto i : {&acc_val, &hs_val, &exo_val})
			(*i)*= n;
		return *this;
	}
	Group <C> operator*(unsigned int n) const {
		Group <C> result(*this);
		return (result*= n);
	}
	Group <C> operator/(unsigned int n) const {
		Group <C> result(*this);
		return (result/= n);
	}

	template<class C_other>
	bool operator==(Group <C_other> group) const {
		return (C::hs_ * size == C_other::hs_ * group.get_size()
			&& C::exo_ * size == C_other::exo_ * group.get_size());
	}
	template<class C_other>
	bool operator!=(Group <C_other> group) const {
		return !(*this == group);
	}
	template<class C_other>
	bool operator<(Group <C_other> group) const {
		return (C::hs_ * size < C_other::hs_ * group.get_size()
		        && C::exo_ * size < C_other::exo_ * group.get_size());
	}
	template<class C_other>
	bool operator>(Group <C_other> group) const {
		return (C::hs_ * size > C_other::hs_ * group.get_size()
		        && C::exo_ * size > C_other::exo_ * group.get_size());
	}
	template<class C_other>
	bool operator<=(Group <C_other> group) const{
		return (*this < group || *this == group);
	}
	template<class C_other>
	bool operator>=(Group <C_other> group) const{
		return (*this > group || *this == group);
	}
};
