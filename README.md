# MatrixLib
A simple matrix library for C++ with basic functionality

## API

### Constructors
  Create a size x size matrix of zeros  
	`Matrix(int size)`  
  Create a r x c matrix of zeros  
	`Matrix(int r, int c)`  
  Create a size x size matrix of random numbers between 0 - 1  
	`Matrix(int size, bool rand)`  
  Create a r x c matrix of random numbers between 0 - 1  
	`Matrix(int r, int c, bool rand)`  
  Create a vector matrix like so   
	`Matrix matrix = {x, x, x, x, x}`  
  Create a matrix like so  
	`Matrix matrix = {{x, x, x}, {x, x, x}}`  
  Create a matrix using a vector  
	`Matrix(vector<double> _matrix)`  
  ... Or using a 2D vector  
	`Matrix(vector<vector<double>> _matrix)`  
  Copy another matrix like so  
	`Matrix matrix = otherMatrix'  

### Access
  Access Element within matrix  
	`double get(int r, int c)`  
  or  
  `matrix[row][column]`  
  Set Element withing matrix  
	`void set(int r, int c, double val)`  
  or  
  `matrix[row[]column] = x`  
  Get 2D array representing matrix  
	`double** getMatrix()`  
  Get array represening a single row of the matrix  
	`double* getRow(int r)`  
  Get array represening a single column of the matrix  
	`double* getCol(int c)`  
  Get size of array (rows, columns) and set refrences passed  
	`void getSize(int* r, int* c)`  
  Get number of rows  
	`int getRows()`  
  Get number of columns  
	`int getCols()`  
  
 ### Convience Functions
  Set all elements to a number  
	`void setAll(double val)`  
  Set all elements to 0  
	`void zeros()`  
  Set all elements to 1  
	`void ones()`  
  Round all elements down (floor)  
	`void floor()`  
  Round all elements up (ceil)  
	`void ceil()`  
  Round all elements to integers  
	`void round()`  
  Randomize all elements between 0 - 1  
	`void rand()`  
  Randomize all elements between 0 - max  
	`void rand(int max)`  
  Randomize all elements between min - max  
	`void rand(int min, int max)`  
  Randomize all elements between min - max and round to integers  
	`void randInt(int min, int max)`  
  or  
  `void rand(int min, int max, bool useInt)`  
  Randomize all elements between 0 - max and round to integers  
	`void randInt(int max)`  
	Turn matrix into a identity matrix  
	`void identity()`  
  Transpose Matrix  
	`void transpose()`  
  Nicely print matrix  
	`void print()`  
  
  
  ### Static Operations / Constructors
  Return copy of floored array  
	`static Matrix& floorAll(Matrix& m)`  
  Return copy of ceiled array  
	`static Matrix& ceilAll(Matrix& m)`  
  Return copy of rounded array  
	`static Matrix& roundAll(Matrix& m)`  
  Create a new size x size matrix of random numbers between 0 - 1  
	`static Matrix& random(int size)`  
  Create a new r x c matrix of random numbers between 0 - 1  
	`static Matrix& random(int r, int c)`  
  Create a new matrix of random numbers between 0 - 1 that is the same size as m  
	`static Matrix& random(Matrix& m)`  
  Create a new size x size identity matrix  
	`static Matrix& identity(int size)`  
  Create a new r x c identity matrix  
	`static Matrix& identity(int r, int c)`  
  Create a new identity matrix  that is the same size as m  
	`static Matrix& identity(Matrix& m)`  
  Create a new matrix that is the transpose of m  
	`static Matrix& transpose(Matrix& m)`  
  Set the number of decimals to display when using Matrix::print()  
	`static void setDecimalPrintLength(int p)`  

### Operators
  Check if matricies have the same values  
	`bool matrixA == matrixB`  
  Return binary matrix where 1 means element == n otherwise 0  
	`Matrix& matrix == n`
  Return binary matrix where 1 means element > n otherwise 0  
	`Matrix& matrix > n`
  Return binary matrix where 1 means element < n otherwise 0  
	`Matrix& matrix < n`
  Return binary matrix where 1 means element >= n otherwise 0  
	`Matrix& matrix >= n`
  Return binary matrix where 1 means element <= n otherwise 0  
	`Matrix& matrix <= n`  
  Matrix addition  
	`Matrix& matrixA + matrixB`  
  Matrix addition by scalar  
	`Matrix& matrixA + x`  
  Matrix addition and set matrix  
	`void matrixA += matrixB`  
  Matrix addition by scalar and set matrix  
	`void matrixA += x`  
  Add one to every value in matrix (prefix)  
	`Matrix& ++matrix`  
  Add one to every value in matrix (postfix)  
	`Matrix& matrix++`  
  Matrix subtraction  
	`Matrix& matrixA - matrixB`  
  Matrix subtraction by scalar  
	`Matrix& matrix - x`  
  Matrix subtraction and set matrix  
	`void matrixA -= matrixB`  
  Matrix subtraction by scalar and set matrix  
	`void matrix -= x`  
  Subtract one from every element (prefix)  
	`Matrix& --matrix`  
  Subtract one from every element (postfix)  
	`Matrix& matrix--`  
  Matrix multiplication  
  `Matrix& matrixA * matrixB`  
  Matrix multiplication by scalar  
	`Matrix& matrixA * x`  
  Matrix multiplication and set  
  `void matrixA *= matrixB`  
  Matrix multiplication by scalar and set  
  `void matrix *= x`  
