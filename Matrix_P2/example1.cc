// Authors
// Christian Bernabe Cabrera (843382)
// Francesco Busolin (851884)
// Gabriele Acerbi (877653)

#include<iostream>

#include"matrix.h"
#include "matrix_wrap.h"
#include"OperatorStar.h"


int main() {

matrix<int,3,3> A;
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  A(i,j) = i + j ;


A.printMatrix();
std::cout << std::endl;


matrix<int,3,3> B = A;

matrix<int, 3, 3 > C ;
for (int i = 0; i != 3; ++i)
	for (int j = 0; j != 3; ++j)
		C(i, j) = 1;

std::cout << std::endl;

/*
for (int i = 0; i != 2; ++i) {
	for (int j = 0; j != 2; ++j)
		std::cout << A(i, j) << ' ';
	std::cout << '\n';
}*/

std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl << "Matrix Sum\n";

/*matrix<int> H = A.transpose() + A.transpose();
for (int i = 0; i < H.get_height(); ++i) {
	for (int j = 0; j <H.get_width(); ++j)
		std::cout << H(i, j) << ' ';
	std::cout << '\n';
}*/

std::cout << std::endl;
std::cout << std::endl<<"Matrix multiplication begins\n\n";


matrix<int,3,3> X = A ;
std::cout << X.getValue<1, 1>() << std::endl;
X.printMatrix();

}


