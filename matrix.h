#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Matrix
{
private:
	T** data;
	int m, n;

public:
	Matrix();

	Matrix<T>(int m, int n);

	Matrix<T>(int m, int n, const T& value); // TODO+

	Matrix<T>(const Matrix& Matrix);

	void Set_m(int m = 1);

	void Set_n(int n = 1);

	int Get_m();

	int Get_n();

	void Set_Data(const T& value); // TODO+

	T Get_Data(int i, int j) const;

	void Set_Data_Value(int i, int j, T value);

	void Print(const int& Number_Matrix);

	void Reset();

	Matrix& operator = (const Matrix& Matrix);

	~Matrix();

	T& operator () (int m, int n) const;

	Matrix& operator () (int m, int n, int new_value);

	Matrix operator + (const Matrix& New_Matrix);

	Matrix operator - (const Matrix& New_Matrix);

	Matrix operator * (const Matrix& New_Matrix);

	Matrix operator * (const T scalar);

	friend Matrix operator * (const T scalar, Matrix& Matrix); 

	Matrix operator / (const T scalar);

	T Ñalculating_trace_matrix();

	Matrix  Transpose();
	 
	void Random();

	Matrix& Pre_Minor(int row, int col) const;

	T Determinant() const;

	Matrix Search_Matrix_X(const Matrix& Vector);

	friend ostream& operator << (ostream& os, const Matrix& New_Matrix);
};

