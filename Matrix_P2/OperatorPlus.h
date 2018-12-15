// Authors
// Christian Bernabe Cabrera (843382)
// Francesco Busolin (851884)
// Gabriele Acerbi (877653)

#ifndef OPERATORPLUS_H
#define OPERATORPLUS_H
#include <type_traits>
#include "matrix.h"

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

	Left getLeft() const {
		return leftRef;
	}

	Right getRight() const {
		return rightRef;
	}

	template<typename r>
	mSum<T, thisType, r> operator+(const r& y) {
		return mSum<T, thisType, r>(*this, y);
	}

	unsigned get_height() const { return rightRef.get_height(); }
	unsigned get_width() const {  return rightRef.get_width(); }
};





#endif // !OPERATORPLUS_H
