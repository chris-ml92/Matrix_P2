#include<iostream>

#include"matrix.h"
#include "OperatorStar.h"
#include <limits>
 // Matric Chain Multiplication Algorithm !

 // multiply two matrices
matrix<int, 5, 5> matMult(matrix<int, 5, 5> a, matrix<int, 5, 5> b) {
	int r1 = 5; // TODO: change magic numbers
	int r2 = 5;
	int c1 = 5;
	int c2 = 5;
	matrix<int, 5, 5> m;
	for (int i = 0; i < r1; ++i)
		for (int j = 0; j < c2; ++j)
			for (int k = 0; k < c1; ++k)
			{
				m(i,j) = m(i,j) + a(i,k) * b(k,j);
			}
	return m;
}
// given an optimal sequence resolve
matrix<int, 5, 5> mult(std::vector<matrix<int, 5, 5>> A, std::vector<std::vector<int>> s,int i, int j) {
	if (i == j) return A[i];
	int k = s[i][j];
	matrix<int,5,5> X = mult(A,s,i, k);
	matrix<int,5,5> Y = mult(A, s, k + 1, j);
	return matMult(X, Y);
}
// find dimensions of a list of matrices
std::vector<int> extractDims(std::vector<matrix<int, 5, 5>> list) {
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
matrix<int, 5, 5> doMult(std::vector<matrix<int, 5, 5>> list) {
	matrix<int, 5, 5> result;
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
	return mult(list,s,0,n-1);
}

// end matrix multiply

int main() {

matrix<int,5,5> A;
for (int i=0; i!=5; ++i)
	for(int j=0; j!=5; ++j)
	  A(i,j) = i*10+j;

//std::cout << A(1,2) << std::endl;

for (int i=0; i!=5; ++i) {
	for(int j=0; j!=5; ++j)
		std::cout << A(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;


auto B=A.transpose();
std::cout << B(1,2) << ' ' << *(B.begin()+1) << std::endl;
for (int i=0; i!=5; ++i) {
	for(int j=0; j!=5; ++j)
		std::cout << B(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;

A = A.transpose() + A + A;
for (int i = 0; i != 5; ++i) {
	for (int j = 0; j != 5; ++j)
		std::cout << A(i, j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;

std::vector<matrix<int, 5, 5>> mts{A,A,A};
auto mults = doMult(mts);
//auto H = A * A;
/*
auto C=B.window({1,4,1,4});
std::cout << C(1,2) << ' ' << *(C.col_begin(2)) << ' ' << *++(C.col_begin(2)) << std::endl;
for (int i=0; i!=3; ++i) {
	for(int j=0; j!=3; ++j)
		std::cout << C(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;

for (auto iter=C.col_begin(1); iter != C.col_end(1); ++iter)
	std::cout << *iter << ' ';
std::cout << "\n\n";

auto D=C.diagonal();
std::cout << D(1) << '=' << D.get_height() << 'x' << D.get_width() <<  std::endl;

for (auto iter=D.begin(); iter != D.end(); ++iter)
	std::cout << *iter << ' ';
std::cout << "\n\n";

auto E=D.diagonal_matrix();
std::cout << E(1,2) << ' ' << E(2,2) << std::endl;

for (auto iter=E.row_begin(1); iter != E.row_end(1); ++iter)
	std::cout << *iter << ' ';
std::cout << "\n\n============================\n\n";


matrix<int> BC=B;

B(1,2)=0;

for (int i=0; i!=5; ++i) {
	for(int j=0; j!=4; ++j)
		std::cout << B(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;

for (int i=0; i!=5; ++i) {
	for(int j=0; j!=4; ++j)
		std::cout << BC(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;

for (int i=0; i!=4; ++i) {
	for(int j=0; j!=5; ++j)
		std::cout << A(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;
return 0;*/
}


