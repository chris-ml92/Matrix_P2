// Authors
// Christian Bernabe Cabrera (843382)
// Francesco Busolin (851884)
// Gabriele Acerbi (877653)

#include<iostream>

#include"matrix.h"
#include "matrix_wrap.h"
#include"OperatorStar.h"


int main() {

matrix<int> A(2,2);
for (int i=0; i!=2; ++i)
	for(int j=0; j!=2; ++j)
	  A(i,j) = i+1;


for (int i=0; i!=2; ++i) {
	for(int j=0; j!=2; ++j)
		std::cout << A(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;


matrix<int> B=A.transpose();
for (int i=0; i!=2; ++i) {
	for(int j=0; j!=2; ++j)
		std::cout << B(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;


for (int i = 0; i != 2; ++i) {
	for (int j = 0; j != 2; ++j)
		std::cout << A(i, j) << ' ';
	std::cout << '\n';
}

std::cout << std::endl;
std::cout << std::endl;

for (int i = 0; i != 2; ++i) {
	for (int j = 0; j != 2; ++j)
		std::cout << A(i, j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;
std::cout << std::endl << "Matrix Sum\n";

matrix<int> H = A.transpose() + A.transpose();
for (int i = 0; i < H.get_height(); ++i) {
	for (int j = 0; j <H.get_width(); ++j)
		std::cout << H(i, j) << ' ';
	std::cout << '\n';
}

std::cout << std::endl;
std::cout << std::endl<<"Matrix multiplication begins\n\n";


matrix<int> X = A * A * B;
for (int i = 0; i < H.get_height(); ++i) {
	for (int j = 0; j < H.get_width(); ++j)
		std::cout << X(i, j) << ' ';
	std::cout << '\n';
}

}


