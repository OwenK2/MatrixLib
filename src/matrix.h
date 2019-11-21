/**
 * @file matrix.h
 *
 * @brief This is the main header file for MatrixLib
 *
 * @author Owen Kuhn
 *
 */
#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#include <vector>
#include <cmath>
using namespace std;

namespace MatrixLib {

class Matrix {
private:
	vector<vector<double>> matrix;
	int rows = 0;
	int cols = 0;
	static int decimalsToShow;
	static int getNumberLength(double n);


	class Matrix_Row {
		friend Matrix;
		public:
			Matrix_Row(vector<double>& _row)  : row(_row) {};
			double& operator[](int col) {return row[col];}
		private:
			vector<double>& row;
	};
	struct NonConformant : public exception {
		const char* what() const throw() {
	  	return "Nonconformant Arguments";
	  }
	};
	struct OutOfBounds : public exception {
		const char* what() const throw() {
	  	return "Out of Bounds";
	  }
	};

public:
	Matrix();
	Matrix(int size);
	Matrix(int r, int c);
	Matrix(int size, bool rand);
	Matrix(int r, int c, bool rand);
	Matrix(double* _matrix, int r, int c);
	Matrix(initializer_list<double> _matrix);
	Matrix(initializer_list<initializer_list<double>> _matrix);
	Matrix(vector<double> _matrix);
	Matrix(vector<vector<double>> _matrix);
	Matrix(const Matrix &m);
	~Matrix();

	double get(int r, int c);
	void set(int r, int c, double val);
	void setAll(double val);
	void zeros();
	void ones();
	void floor();
	void ceil();
	void round();
	void rand();
	void rand(int max);
	void rand(int min, int max);
	void rand(int min, int max, bool useInt);
	void randInt(int max);
	void randInt(int min, int max);
	void identity();
	void transpose();
	double** getMatrix();		// TODO: figure out how to use result
	double* getRow(int r);
	double* getCol(int c);
	void getSize(int* r, int* c);
	int getRows();
	int getCols();
	void print();

	static Matrix& floorAll(Matrix& m);
	static Matrix& ceilAll(Matrix& m);
	static Matrix& roundAll(Matrix& m);
	static Matrix& random(int size);
	static Matrix& random(int r, int c);
	static Matrix& random(Matrix& m);
	static Matrix& identity(int size);
	static Matrix& identity(int r, int c);
	static Matrix& identity(Matrix& m);
	static Matrix& transpose(Matrix& m);
	static void setDecimalPrintLength(int p);

	
	Matrix_Row operator[](int row) {return Matrix_Row(matrix[row]);}
	bool operator==(Matrix& m);
	Matrix& operator==(double n);
	Matrix& operator>(double n);
	Matrix& operator<(double n);
	Matrix& operator>=(double n);
	Matrix& operator<=(double n);
	Matrix& operator+(Matrix& m);
	Matrix& operator+(double n);
	void operator+=(Matrix& m);
	void operator+=(double n);
	Matrix& operator++();
	Matrix& operator++(int u);
	Matrix& operator-(Matrix& m);
	Matrix& operator-(double n);
	void operator-=(Matrix& m);
	void operator-=(double n);
	Matrix& operator--();
	Matrix& operator--(int u);
	Matrix& operator *(Matrix& m);
	Matrix& operator *(double n);
	void operator *=(Matrix& m);
	void operator *=(double n);
	Matrix& operator /(Matrix& m);  //TODO
	Matrix& operator /(double n);  //TODO
	void operator /=(Matrix& m);  //TODO
	void operator /=(double n);  //TODO
	// TODO: .*, .^, ./ ...	
};

}

#endif