#ifndef OPERATORSTAR_H
#define OPERATORSTAR_H
#include"matrix.h"
//#include"matrix_wrap.h"
#include<list>


template<typename T, unsigned H=1, unsigned W=1>
class mMult {

private:
	std::vector<matrix_wrap<T>> matrix_List;
public:

	mMult() = default;
	typedef mMult<T, H, W> this_Type;
	static constexpr unsigned Height = H;
	static constexpr unsigned Width = W;
	
	//friend mMult<T,matrix_ref<T,Left>> 
	
	template<class matrix_class>
	void empl_back(matrix_ref<T, matrix_class> m){
		matrix_List.emplace_back(m);
	}
	

template<typename T, class Left, class Right>
friend mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width>
operator* (const matrix_ref<T, Left>& left, const matrix_ref<T, Right>& right);

/*
*
* conversion Operator to Matrix
*
*/

operator matrix<T>() {
	

	
	return doMult(matrix_List);


}

// Matric Chain Multiplication Algorithm !

// multiply two matrices
matrix<T> matMult(matrix<T> a, matrix<T> b) {
	int r1 = a.get_height(); // TODO: change magic numbers
	int r2 = b.get_height();
	int c1 = a.get_width();
	int c2 = b.get_width();
	matrix<T> m(r1,c2);
	for (int i = 0; i < r1; ++i)
		for (int j = 0; j < c2; ++j)
			for (int k = 0; k < c1; ++k)
			{
				m(i, j) = m(i, j) + a(i, k) * b(k, j);
			}
	return m;
}
// given an optimal sequence resolve
matrix<T> mult(std::vector<matrix_wrap<T>> A, std::vector<std::vector<int>> s, int i, int j) {
	if (i == j) {
		matrix<int> r = A[i];
		return r;
	}
	int k = s[i][j];
	matrix<T> X = mult(A, s, i, k);
	matrix<T> Y = mult(A, s, k + 1, j);
	return matMult(X, Y);
}
// find dimensions of a list of matrices
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
// find parentesis using dynamic algorithm
matrix<T> doMult(std::vector<matrix_wrap<T>> list) {
	unsigned h = list.front().get_height();
	unsigned w = list.back().get_width();
	matrix<T> result(h,w);
	unsigned n = list.size();
	std::vector<std::vector<int>> m, s;
	std::vector<int> p;
	m.resize(n, std::vector<int>(n, 0));
	s.resize(n, std::vector<int>(n, 0));
	p = extractDims(list);
	for (int L = 2; L < n; L++) {
		for (int i = 1; i < n - L + 1; i++) {
			int j = i + L - 1;
			m[i][j] = std::numeric_limits<int>::max();
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1 + 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return mult(list, s, 0, n - 1);
}

// end matrix multiply


};

template<typename T, class Left, class Right>
mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width> operator* (const matrix_ref<T, Left>& left, const matrix_ref<T, Right>& right){
	mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width> chain;
	chain.empl_back(left);
	chain.empl_back(right);
	return chain;
}
	




#endif // !OPERATORSTAR_H
