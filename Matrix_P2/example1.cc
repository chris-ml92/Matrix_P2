// Authors
// Christian Bernabe Cabrera (843382)
// Francesco Busolin (851884)
// Gabriele Acerbi (877653)

#include<iostream>

#include"matrix.h"
#include "matrix_wrap.h"
#include"OperatorStar.h"


int main() {

std::cout << std::endl << "/////STATIC SUM <3,3> + <3,3> + <3,3>/////" << std::endl << std::endl;

matrix<int,3,3> A;
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  A(i,j) = i + j ;

A.printMatrix();
std::cout << std::endl;

matrix<int,3,3> B;
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  B(i,j) = i + j ;

B.printMatrix();
std::cout << std::endl;

matrix<int,3,3> C;
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  C(i,j) = i + j ;

C.printMatrix();
std::cout << std::endl;

matrix<int,3,3> SS = A+B+C;

SS.printMatrix();
std::cout << std::endl;


std::cout << std::endl << "/////STATIC MULT <3,3> * <3,3> * <3,3>/////" << std::endl << std::endl;

A.printMatrix();
std::cout << std::endl;

B.printMatrix();
std::cout << std::endl;

C.printMatrix();
std::cout << std::endl;

matrix<int,3,3> MS = A*B*C;

MS.printMatrix();
std::cout << std::endl;


std::cout << std::endl << "/////DYN SUM (3,3) + (3,3) + (3,3)/////" << std::endl << std::endl;

matrix<int> D(3,3);
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  D(i,j) = i + j ;

D.printMatrix();
std::cout << std::endl;

matrix<int> E(3,3);
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  E(i,j) = i + j ;

E.printMatrix();
std::cout << std::endl;

matrix<int> F(3,3);
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  F(i,j) = i + j ;

F.printMatrix();
std::cout << std::endl;

matrix<int> SD = D+E+F;

SD.printMatrix();
std::cout << std::endl;


std::cout << std::endl << "/////DYN MULT (3,3) * (3,3) * (3,3)/////" << std::endl << std::endl;

D.printMatrix();
std::cout << std::endl;

E.printMatrix();
std::cout << std::endl;

F.printMatrix();
std::cout << std::endl;

matrix<int> MD = D*E*F;

MD.printMatrix();
std::cout << std::endl;


std::cout << std::endl << "/////NON SQUARE SUM <3,5> + <3,5> + <3,5>/////" << std::endl << std::endl;

matrix<int,3,5> G;
for (int i=0; i!=3; i++)
	for(int j=0; j!=5; j++)
	  G(i,j) = i + j ;

G.printMatrix();
std::cout << std::endl;

matrix<int,3,5> H;
for (int i=0; i!=3; i++)
	for(int j=0; j!=5; j++)
	  H(i,j) = i + j ;

H.printMatrix();
std::cout << std::endl;

matrix<int,3,5> I;
for (int i=0; i!=3; i++)
	for(int j=0; j!=5; j++)
	  I(i,j) = i + j ;

I.printMatrix();
std::cout << std::endl;

matrix<int> NSS = G+H+I;

NSS.printMatrix();
std::cout << std::endl;


/*std::cout << std::endl << "/////NON SQUARE MULT <3,5> * <5,4> * <4,5>/////" << std::endl << std::endl;

G.printMatrix();
std::cout << std::endl;

matrix<int,5,4> J;
for (int i=0; i!=5; i++)
	for(int j=0; j!=4; j++)
	  J(i,j) = i + j ;

J.printMatrix();
std::cout << std::endl;

matrix<int,4,5> K;
for (int i=0; i!=4; i++)
	for(int j=0; j!=5; j++)
	  K(i,j) = i + j ;

K.printMatrix();
std::cout << std::endl;

matrix<int> NSM = G*J*K;

NSM.printMatrix();
std::cout << std::endl;*/


/*std::cout << std::endl << "/////CHAIN OP (<3,3> + <3,3>) * (<3,3> + <3,3>)/////" << std::endl << std::endl;

A.printMatrix();
std::cout << std::endl;

B.printMatrix();
std::cout << std::endl;

C.printMatrix();
std::cout << std::endl;

matrix<int,3,3> L;
for (int i=0; i!=3; i++)
	for(int j=0; j!=3; j++)
	  L(i,j) = i + j ;

L.printMatrix();
std::cout << std::endl;

matrix<int,3,3> CH = A+B*C+L;

CH.printMatrix();
std::cout << std::endl;*/

return 0;

}
