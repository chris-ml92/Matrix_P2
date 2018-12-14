#include<iostream>

#include"matrix.h"


#include "matrix_wrap.h"
#include "OperatorStar.h"
#include <limits>

int main() {

matrix<int> A(2,2);
for (int i=0; i!=2; ++i)
	for(int j=0; j!=2; ++j)
	  A(i,j) = i+1;

//std::cout << A(1,2) << std::endl;

for (int i=0; i!=2; ++i) {
	for(int j=0; j!=2; ++j)
		std::cout << A(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;


auto B=A.transpose();
std::cout << B(1,1) << ' ' << *(B.begin()+1) << std::endl;
for (int i=0; i!=2; ++i) {
	for(int j=0; j!=2; ++j)
		std::cout << B(i,j) << ' ';
	std::cout << '\n';
}
std::cout << std::endl;

//A = A.transpose() + A + A;
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
std::cout << std::endl;

matrix<int> H = A.transpose()+A.transpose();
for (int i = 0; i < H.get_height(); ++i) {
	for (int j = 0; j <H.get_width(); ++j)
		std::cout << H(i, j) << ' ';
	std::cout << '\n';
}
}


