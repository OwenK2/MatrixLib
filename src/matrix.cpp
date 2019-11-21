#include "matrix.h"

using namespace MatrixLib;

int Matrix::decimalsToShow = 2;

Matrix::Matrix() {}
Matrix::Matrix(int size) : Matrix(size,size) {}
Matrix::Matrix(int r, int c) {
	rows = r;
	cols = c;
	matrix.clear();
	for(int i = 0; i < r; ++i) {
		vector<double> row;	
	  for(int j = 0;j < c;++j) {
	  	row.push_back(0);
	  }
	  matrix.push_back(row);
	}
}
Matrix::Matrix(int size, bool random) : Matrix(size,size,random) {}
Matrix::Matrix(int r, int c, bool random) {
	if(random) {
		std::srand(time(NULL));
		rows = r;
		cols = c;
		matrix.clear();
		for(int i = 0; i < r; ++i) {
			vector<double> row;	
		  for(int j = 0;j < c;++j) {
		  	row.push_back((std::rand() % 1000) / 1000.0);
		  }
		  matrix.push_back(row);
		}
	}
	else {
		Matrix(r,c);
	}
}
Matrix::Matrix(double* _matrix, int r, int c) {
	rows = r;
	cols = c;
	matrix.clear();
	for(int i = 0; i < r; ++i) {
		vector<double> row;
	  for(int j = 0;j < c;++j) {
	  	row.push_back(_matrix[i*c + j]);
	  }
	  matrix.push_back(row);
	}
}
Matrix::Matrix(initializer_list<double> _matrix) {
	rows = distance(_matrix.begin(),_matrix.end());
	cols = 1;
	for(auto colIterator = _matrix.begin(); colIterator != _matrix.end();++colIterator) {
		vector<double> row;
		row.push_back(*colIterator);
		matrix.push_back(row);
	}
}
Matrix::Matrix(initializer_list<initializer_list<double>> _matrix) {
	try {
		rows = distance(_matrix.begin(),_matrix.end());
		for(auto rowIterator = _matrix.begin(); rowIterator != _matrix.end(); ++rowIterator) {
			vector<double> row;
			if(rowIterator == _matrix.begin()) {
				cols = distance((*rowIterator).begin(),(*rowIterator).end());
			}
			else if(cols != distance((*rowIterator).begin(),(*rowIterator).end())) {
				throw NonConformant();
			}
			for(auto colIterator = (*rowIterator).begin(); colIterator != (*rowIterator).end();++colIterator) {
				row.push_back(*colIterator);
			}
			matrix.push_back(row);
		}
	}
	catch(NonConformant& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot create matrix of \e[1m%dx%d\e[0m\e[33m one of the rows has a non-conformant number of columns\e[0m\n", e.what(), rows, cols);
		Matrix newMatrix(rows,cols);
		*this = newMatrix;
	}
}
Matrix::Matrix(vector<double> _matrix) {
	rows = distance(_matrix.begin(),_matrix.end());
	cols = 1;
	for(auto colIterator = _matrix.begin(); colIterator != _matrix.end();++colIterator) {
		vector<double> row;
		row.push_back(*colIterator);
		matrix.push_back(row);
	}
}
Matrix::Matrix(vector<vector<double>> _matrix) {
	try {
		rows = distance(_matrix.begin(),_matrix.end());
		for(auto rowIterator = _matrix.begin(); rowIterator != _matrix.end(); ++rowIterator) {
			vector<double> row;
			if(rowIterator == _matrix.begin()) {
				cols = distance((*rowIterator).begin(),(*rowIterator).end());
			}
			else if(cols != distance((*rowIterator).begin(),(*rowIterator).end())) {
				throw NonConformant();
			}
			for(auto colIterator = (*rowIterator).begin(); colIterator != (*rowIterator).end();++colIterator) {
				row.push_back(*colIterator);
			}
			matrix.push_back(row);
		}
	}
	catch(NonConformant& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot create matrix of \e[1m%dx%d\e[0m\e[33m one of the rows has a non-conformant number of columns\e[0m\n", e.what(), rows, cols);
		Matrix newMatrix(rows,cols);
		*this = newMatrix;
	}
}
Matrix::Matrix(const Matrix &m) {
	matrix = m.matrix;
	cols = m.cols;
	rows = m.rows;
}
Matrix::~Matrix() {}



// Public Functions (API)
double Matrix::get(int r, int c) {
	try {
		if(r > rows || c > cols || r < 0 || c < 0) {
			throw OutOfBounds();
		}
		return matrix[r][c];
	}
	catch(OutOfBounds& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot access element \e[1m(%d,%d)\e[0m\e[33m in a \e[1m%dx%d\e[0m\e[33m matrix\e[0m\n", e.what(), r, c, rows, cols);
	}
	return 0;
}
void Matrix::set(int r, int c, double val) {
	try {
		if(r > rows || c > cols || r < 0 || c < 0) {
			throw OutOfBounds();
		}
		matrix[r][c] = val;
	}
	catch(OutOfBounds& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot access element \e[1m(%d,%d)\e[0m\e[33m in a \e[1m%dx%d\e[0m\e[33m matrix\e[0m\n", e.what(), r, c, rows, cols);
	}
}
void Matrix::setAll(double val) {
	for(int i = 0;i < rows; ++i) {
		for(int j = 0;j < cols; ++j) {
			matrix[i][j] = val;
		}
	}
}
void Matrix::zeros() {
	setAll(0);
}
void Matrix::ones() {
	setAll(1);
}
void Matrix::floor() {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j] = std::floor(matrix[i][j]);
		}
	}
}
void Matrix::ceil() {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j] = std::ceil(matrix[i][j]);
		}
	}
}
void Matrix::round() {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j] = std::round(matrix[i][j]);
		}
	}
}
void Matrix::rand() {
	rand(0,1, false);
}
void Matrix::rand(int max) {
	rand(0, max, false);
}
void Matrix::rand(int min, int max) {
	rand(min, max, false);
}
void Matrix::randInt(int max) {
	rand(0, max, true);
}
void Matrix::randInt(int min, int max) {
	rand(min, max, true);
}
void Matrix::rand(int min, int max, bool useInt) {
	std::srand(time(NULL));
	for(int i = 0; i < rows; ++i) {
	  for(int j = 0;j < cols;++j) {
		  	double n = (std::rand() % 10000) / 10000.0 * (max - min) + min;
		  	if(useInt) {n = std::floor(n);}
		  	matrix[i][j] = n;
	  }
	}
}
void Matrix::identity() {
	for(int i = 0; i < rows; ++i) {
	  for(int j = 0;j < cols;++j) {
	  	matrix[i][j] = i == j ? 1 : 0;
	  }
	}
}
void Matrix::transpose() {
	Matrix copy(*this);
	matrix.clear();
	int tmp = cols;
	cols = rows;
	rows = tmp;
	for(int i = 0; i < rows; ++i) {
		vector<double> row;
	  for(int j = 0;j < cols;++j) {
	  	row.push_back(copy.matrix[j][i]);
	  }
	  matrix.push_back(row);
	}
}
double** Matrix::getMatrix() {
  double** m = 0;
  m = new double*[rows];
	for(int i = 0;i < rows; ++i) {
		for(int j = 0;j < cols; ++j) {
			m[i][j] = matrix[i][j];
		}
	}
	return m;
}
double* Matrix::getRow(int r) {
	double* vec = new double[rows];
	try {
		if(r > rows || r < 0) {
			throw OutOfBounds();
		}
		for(int i = 0;i < cols;++i) {
			vec[i] = matrix[r][i];
		}
	}
	catch(OutOfBounds& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot access row \e[1m%d\e[0m\e[33m in a \e[1m%dx%d\e[0m\e[33m matrix\e[0m\n", e.what(), r, rows, cols);
	}
	return vec;
}
double* Matrix::getCol(int c) {
	double* vec = new double[rows];
	try {
		if(c > rows || c < 0) {
			throw OutOfBounds();
		}
		for(int i = 0;i < rows; ++i) {
			vec[i] = matrix[i][c];
		}
	}
	catch(OutOfBounds& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot access row \e[1m%d\e[0m\e[33m in a \e[1m%dx%d\e[0m\e[33m matrix\e[0m\n", e.what(), c, rows, cols);
	}
	return vec;
}
void Matrix::getSize(int* r, int* c) {
	*r = rows;
	*c = cols;
}
int Matrix::getRows() {
	return rows;
}
int Matrix::getCols() {
	return cols;
}

void Matrix::print() {
	bool decimals = false;
	int colLengths[cols];
	for(int i = 0;i < cols;++i) {colLengths[i] = 0;}
	for(int i = 0;i < rows; ++i) {
		for(int j = 0;j < cols; ++j) {
			double epsilon = matrix[i][j] - std::floor(matrix[i][j]);
			epsilon *= epsilon < 0 ? -1 : 1;
			if(epsilon >  0.0001) {
				decimals = true;
			}
			int len = getNumberLength(matrix[i][j]);
			if(len > colLengths[j]) {
				colLengths[j] = len;
			}
		}
	}
	for(int i = 0;i < rows; ++i) {
		for(int j = 0;j < cols; ++j) {
			if(j != 0) {printf("  ");}
			if(decimals) {
				printf("%.*f", decimalsToShow, matrix[i][j]);
			}
			else {
				printf("%d", (int)matrix[i][j]);
			}
			int filler = colLengths[j] - getNumberLength(matrix[i][j]);
			if(j != cols-1) {
				for(int k = 0;k < filler;++k) printf(" ");
			}
		}
		printf("\n");
	}
}
void Matrix::setDecimalPrintLength(int p) {
	try {
		if(p < 0) {throw OutOfBounds();}
		decimalsToShow = p;
	}
	catch(OutOfBounds& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot set decimal print length to  \e[1m%d\e[0m\n", e.what(), p);
	}
}

//Static Functions (API)
Matrix& Matrix::floorAll(Matrix& m) {
	Matrix* newMatrix = new Matrix(m);
	for(int i = 0;i < newMatrix->rows;++i) {
		for(int j = 0;j < newMatrix->cols;++j) {
			newMatrix->matrix[i][j] = std::floor(newMatrix->matrix[i][j]);
		}
	}
	return *newMatrix;
}
Matrix& Matrix::ceilAll(Matrix& m) {
	Matrix* newMatrix = new Matrix(m);
	for(int i = 0;i < newMatrix->rows;++i) {
		for(int j = 0;j < newMatrix->cols;++j) {
			newMatrix->matrix[i][j] = std::ceil(newMatrix->matrix[i][j]);
		}
	}
	return *newMatrix;
}
Matrix& Matrix::roundAll(Matrix& m) {
	Matrix* newMatrix = new Matrix(m);
	for(int i = 0;i < newMatrix->rows;++i) {
		for(int j = 0;j < newMatrix->cols;++j) {
			newMatrix->matrix[i][j] = std::round(newMatrix->matrix[i][j]);
		}
	}
	return *newMatrix;
}
Matrix& Matrix::random(int size) {
	Matrix* m = new Matrix(size, true);
	return *m;
}
Matrix& Matrix::random(int r, int c) {
	Matrix* m = new Matrix(r, c, true);
	return *m;
}
Matrix& Matrix::random(Matrix& m) {
	Matrix* newMatrix = new Matrix(m);
	newMatrix->rand(0, 1, false);
	return *newMatrix;
}
Matrix& Matrix::identity(int size) {
	Matrix* m = new Matrix(size);
	m->identity();
	return *m;
}
Matrix& Matrix::identity(int r, int c) {
	Matrix* m = new Matrix(r, c);
	m->identity();
	return *m;
}
Matrix& Matrix::identity(Matrix& m) {
	Matrix* newMatrix = new Matrix(m);
	newMatrix->identity();
	return *newMatrix;
}
Matrix& Matrix::transpose(Matrix& m) {
	Matrix* newMatrix = new Matrix(m);
	newMatrix->transpose();
	return *newMatrix;
}


// Operator Functions
bool Matrix::operator==(Matrix& m) {
	if(cols != m.cols || rows != m.rows) {return false;}
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			if(matrix[i][j] != m.matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}
Matrix& Matrix::operator==(double n) {
	Matrix* newMatrix = new Matrix(rows,cols);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			newMatrix->matrix[i][j] = matrix[i][j] == n ? 1 : 0;
		}
	}
	return *newMatrix;
}
Matrix& Matrix::operator>(double n) {
	Matrix* newMatrix = new Matrix(rows,cols);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			newMatrix->matrix[i][j] = matrix[i][j] > n ? 1 : 0;
		}
	}
	return *newMatrix;
}
Matrix& Matrix::operator<(double n) {
	Matrix* newMatrix = new Matrix(rows,cols);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			newMatrix->matrix[i][j] = matrix[i][j] < n ? 1 : 0;
		}
	}
	return *newMatrix;
}
Matrix& Matrix::operator>=(double n) {
	Matrix* newMatrix = new Matrix(rows,cols);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			newMatrix->matrix[i][j] = matrix[i][j] >= n ? 1 : 0;
		}
	}
	return *newMatrix;
}
Matrix& Matrix::operator<=(double n) {
	Matrix* newMatrix = new Matrix(rows,cols);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			newMatrix->matrix[i][j] = matrix[i][j] <= n ? 1 : 0;
		}
	}
	return *newMatrix;
}
Matrix& Matrix::operator+(Matrix& m) {
	Matrix* newMatrix = new Matrix(*this);
	*newMatrix += m;
	return *newMatrix;
}
Matrix& Matrix::operator+(double n) {
	Matrix* newMatrix = new Matrix(*this);
	*newMatrix += n;
	return *newMatrix;
}
void Matrix::operator+=(Matrix& m) {
	try {
		if(cols != m.cols || rows != m.rows) {
			throw NonConformant();
		}
		for(int i = 0;i < rows;++i) {
			for(int j = 0;j < cols;++j) {
				matrix[i][j] += m.matrix[i][j];
			}
		}
	}
	catch(NonConformant& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot add matrix of \e[1m%dx%d\e[0m\e[33m by \e[1m%dx%d\e[0m\n", e.what(), rows, cols, m.rows, m.cols);
	}
}
void Matrix::operator+=(double n) {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j] += n;
		}
	}
}
Matrix& Matrix::operator++() {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j]++;
		}
	}
	return *this;
}
Matrix& Matrix::operator++(int u) {
	Matrix* copy = new Matrix(*this);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j]++;
		}
	}
	return *copy;
}
Matrix& Matrix::operator-(Matrix& m) {
	Matrix* newMatrix = new Matrix(*this);
	*newMatrix -= m;
	return *newMatrix;
}
Matrix& Matrix::operator-(double n) {
	Matrix* newMatrix = new Matrix(*this);
	*newMatrix -= n;
	return *newMatrix;
}
void Matrix::operator-=(Matrix& m) {
	try {
		if(cols != m.cols || rows != m.rows) {
			throw NonConformant();
		}
		for(int i = 0;i < rows;++i) {
			for(int j = 0;j < cols;++j) {
				matrix[i][j] -= m.matrix[i][j];
			}
		}
	}
	catch(NonConformant& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot subtract matrix of \e[1m%dx%d\e[0m\e[33m by \e[1m%dx%d\e[0m\n", e.what(), rows, cols, m.rows, m.cols);
	}
}
void Matrix::operator-=(double n) {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j] -= n;
		}
	}
}
Matrix& Matrix::operator--() {
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j]--;
		}
	}
	return *this;
}
Matrix& Matrix::operator--(int u) {
	Matrix* copy = new Matrix(*this);
	for(int i = 0;i < rows;++i) {
		for(int j = 0;j < cols;++j) {
			matrix[i][j]--;
		}
	}
	return *copy;
}
Matrix& Matrix::operator*(Matrix& m) {
	Matrix* newMatrix = new Matrix(*this);
	*newMatrix *= m;
	return *newMatrix;
}
Matrix& Matrix::operator*(double n) {
	Matrix* newMatrix = new Matrix(*this);
	*newMatrix *= n;
	return *newMatrix;
}
void Matrix::operator*=(Matrix& m) {
	try {
		if(cols != m.rows) {
			throw NonConformant();
		}
		Matrix newMatrix(rows,m.cols);
		for(int i = 0;i < rows;++i) {
			for(int j = 0;j < m.cols;++j) {
				for(int k = 0;k < cols;++k) {
					newMatrix.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}
		*this = newMatrix;
	}
	catch(NonConformant& e) {
		printf("\e[31m\e[1m[ERROR]  %s\e[0m\n  \e[33m- Cannot multiply matrix of \e[1m%dx%d\e[0m\e[33m by \e[1m%dx%d\e[0m\n", e.what(), rows, cols, m.rows, m.cols);
	}
}
void Matrix::operator*=(double n) {
	for(int i = 0;i < rows; ++i) {
		for(int j = 0;j < cols; ++j) {
			matrix[i][j] *= n;
		}
	}
}


//Static Functions (HELPER)
int Matrix::getNumberLength(double n) {
	if(std::floor(n) == 0) {return 1;}
	int len = std::floor(std::log10(std::abs(n)) + 1);
	if(n < 0) {len ++;}
	return len;
}