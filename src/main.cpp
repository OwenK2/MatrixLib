#include "matrix.h"
using namespace std;
using namespace MatrixLib;


int main(int argc, char** argv) {
	Matrix m1 = {0,1,1,2,3};
	printf("First Value: %.2f\n", m1[0][0]);
	m1[0][0] = 5;
	m1[2][0] = 5;
	printf("First Value: %.2f\n", m1[0][0]);
	printf("-----------------\n");
	m1.print();
	printf("-----------------\n");
	printf("\e[33mTranposed Matrix\e[0m\n");
	m1.transpose();
	m1.print();
	printf("\e[36m%dx%d\e[0m\n", m1.getRows(),m1.getCols());

	return 0;
}