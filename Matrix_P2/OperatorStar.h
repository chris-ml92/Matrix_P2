// Authors
// Christian Bernabe Cabrera (843382)
// Francesco Busolin (851884)
// Gabriele Acerbi (877653)

#ifndef OPERATORSTAR_H
#define OPERATORSTAR_H
#include"matrix.h"


template<typename T, unsigned H=1, unsigned W=1>
class mMult {

private:
	std::vector<matrix_wrap<T>> matrix_List;
public:

	mMult() = default;
	typedef mMult<T, H, W> this_Type;
	static constexpr unsigned Height = H;
	static constexpr unsigned Width = W;

	unsigned get_width() {
		return Width;
	}
	unsigned get_height() {
		return Height;
	}
	
	template<class matrix_class>
	void empl_back(matrix_ref<T, matrix_class> m){
		matrix_List.emplace_back(m);
	}
	
template<typename U, class Left, class Right>
friend mMult<U, matrix_ref<U, Left>::Height, matrix_ref<U, Right>::Width>
operator* (const matrix_ref<U, Left>& left, const matrix_ref<U, Right>& right);


/*-------------------------------------------------------
		<conversion Operator to Matrix>
---------------------------------------------------------*/
operator matrix<T>() {

	return resolveChain(matrix_List);
}

operator matrix<T,H,W>() {
	 return resolveChain(matrix_List);
}

/*-------------------------------------------------------
		<MATRIX CHAIN MULTIPLICATION ALGORITHM>
---------------------------------------------------------*/

/*-------------------------------------------------------
		<Multiplication of two matrices>
---------------------------------------------------------*/

matrix<T> singleMultiplication(matrix<T>& a, matrix<T>& b) {
	int r1 = a.get_height(); 
	int r2 = b.get_height();
	int c1 = a.get_width();
	int c2 = b.get_width();
	
	///////////////////////////////////////////////////////
	assert(c1==r2);
	///////////////////////////////////////////////////////
	
	matrix<T> m(r1,c2); 
	for (int i = 0; i < r1; ++i)
		for (int j = 0; j < c2; ++j)
			for (int k = 0; k < c1; ++k)
			{
				m(i, j) = m(i, j) + a(i, k) * b(k, j);
			}
	return m;
}


/*-------------------------------------------------------
		<given an optimal sequence resolve>
---------------------------------------------------------*/
matrix<T> multiplySubSequence(std::vector<matrix_wrap<T>> A, std::vector<std::vector<int>> s, int i, int j) {
	if (i == j) {
		return A[i];
	}
	int k = s[i][j];
	matrix<T> X = multiplySubSequence(A, s, i, k);
	matrix<T> Y = multiplySubSequence(A, s, k + 1, j);
	return singleMultiplication(X, Y);
}
/*-------------------------------------------------------
		<find dimensions of a list of matrices>
---------------------------------------------------------*/
std::vector<int> extractDims(std::vector<matrix_wrap<T>> list) {
	int n = list.size();
	std::vector<int> res;
	res.resize(n + 1, 0);
	res[0] = list[0].get_height();
	for (int i = 1; i < n; i++) {
		res[i] = list[i].get_height();
	}
	res[n] = list[n - 1].get_width();
	return res;
}

/*-------------------------------------------------------
		<find parentesis using dynamic algorithm>
---------------------------------------------------------*/
matrix<T> resolveChain(std::vector<matrix_wrap<T>> list) {
	unsigned h = list.front().get_height();
	unsigned w = list.back().get_width();
	matrix<T> result(h,w);
	unsigned n = list.size();
	std::vector<std::vector<int>> m, s;
	std::vector<int> p;
	m.resize(n, std::vector<int>(n, 0));
	s.resize(n, std::vector<int>(n, 0));
	p = extractDims(list);
	for (unsigned L = 2; L < n; L++) {
		for (unsigned i = 1; i < n - L + 1; i++) {
			unsigned j = i + L - 1;
			m[i][j] = std::numeric_limits<int>::max();
			for (unsigned k = i; k <= j - 1; k++) {
				unsigned q = m[i][k] + m[k + 1][j] + p[i - 1 + 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return multiplySubSequence(list, s, 0, n - 1);
}



};

template<typename T, class Left, class Right>
mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width> operator* (const matrix_ref<T, Left>& left, const matrix_ref<T, Right>& right){
	
	////////////////////////////////////////////////////////////////////////
	static_assert(matrix_ref<T, Left>::Width == matrix_ref<T, Right>::Height, "wrong sizes");
	///////////////////////////////////////////////////////////////////////
	
	mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width> chain;
	chain.empl_back(left);
	chain.empl_back(right);
	return chain;
}

template<typename T, unsigned H, unsigned W, class Right>
mMult<T, H, matrix_ref<T, Right>::Width> operator* (const mMult<T, H,W>&& left, const matrix_ref<T, Right>& right) {

	//////////////////////////////////////////////////////////////////////
	static_assert(W == matrix_ref<T, Right>::Height, "wrong sizes");
	/////////////////////////////////////////////////////////////////////

	mMult<T, H, matrix_ref<T, Right>::Width>  chain(std::move(left));
	chain.empl_back(right);
	return chain;
}
	




#endif // !OPERATORSTAR_H
