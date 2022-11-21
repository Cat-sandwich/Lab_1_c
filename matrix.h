#include <iostream>
#include <math.h>
using namespace std;

class Matrix
{
private:
	double** data;
	int m, n;

public:
	Matrix();

	Matrix(int m, int n);

	Matrix(int m, int n, const double& value); // TODO+

	Matrix(const Matrix& Matrix);

	void Set_m(int m = 1);

	void Set_n(int n = 1);

	int Get_m();

	int Get_n();

	void Set_Data(const double& value); // TODO+

	double Get_Data(int i, int j) const;

	void Set_Data_Value(int i, int j, double value);

	void Print(const int& Number_Matrix);

	void Reset();

	Matrix& operator = (const Matrix& Matrix);

	~Matrix();

	double& operator () (int m, int n) const;

	Matrix& operator () (int m, int n, int new_value);

	Matrix operator + (const Matrix& New_Matrix);

	Matrix operator - (const Matrix& New_Matrix);

	Matrix operator * (const Matrix& New_Matrix);

	Matrix operator * (const double& scalar);


	friend Matrix operator * (const double& scalar, Matrix& Matrix)
	{
		return Matrix * scalar;
	}

	Matrix operator / (const double& scalar);

	double Ñalculating_trace_matrix();

	Matrix  Transpose();
	 
	void Random();

	Matrix Pre_Minor(int row, int col) const;

	/*T Determinant() const;*/

	double NDeterminant(int size);

	Matrix Search_Matrix_X(const Matrix& Vector);

	friend ostream& operator << (ostream& os, const Matrix& New_Matrix);
};

