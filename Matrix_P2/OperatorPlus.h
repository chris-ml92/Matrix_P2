#ifndef OPERATORPLUS_H
#define OPERATORPLUS_H
#include <type_traits>
#include "matrix.h"

/*template<typename A, typename B>*/
/*Some traits classes provide typedefs only, so they are indeed multi-value metafunctions. As an example,
consider again std::iterator_traits.
Type traits are a collection of metafunctions that provide information about qualifiers of a given type
and/or alter such qualifiers. Information can be deduced by a static mechanism inside traits, can be explicitly
supplied with a full/partial specialization of the traits class, or can be supplied by the compiler itself. */
/*struct allDefToghether {

/*Similarly to sizeof, decltype resolves to the type of the C++ expression given in brackets (without
evaluating it at runtime), and you can put it wherever a type is required:
int a;
double b;
decltype(a+b) x = 0; // x is double*/
	/*typedef decltype(A() + B()) sumTypes;

};*/

template<typename T, class Left, class Right>
class mSum {
private:
	const Left& leftRef;
	const Right& rightRef;
public:

	mSum(const Left& L, const Right& R) : leftRef(L), rightRef(R) {}
	typedef mSum<T, Left, Right> thisType;
	T operator() (unsigned x, unsigned y) {
		 return leftRef(x, y) + rightRef(x, y);
	}

	const T operator() (unsigned x, unsigned y) const {
		return leftRef(x, y) + rightRef(x, y);
	}

	template<typename r>
	mSum<T, thisType, r> operator+(const r& y) {
		return mSum<T, thisType, r>(*this, y);
	}


};





#endif // !OPERATORPLUS_H
