#include <iostream>
using namespace std;


class Matrix
{
private:
	double** data;
	int m, n;

public:
	Matrix();
	Matrix(int m, int n);

	Matrix(int m, int n, double** matrix);

	Matrix(const Matrix& Matrix);

	void Set_m(int m = 1);

	void Set_n(int n = 1);

	int Get_m();

	int Get_n();

	double Get_Data(int i, int j);

	void Set_Data(int i, int j, double value);

	void Print(const int& Number_Matrix);

	void Reset();

	Matrix& operator =(const Matrix& Matrix);

	~Matrix();

	double& operator () (int m, int n) const;

	Matrix& operator () (int m, int n, int new_value);

	Matrix operator + (const Matrix& New_Matrix);

	Matrix operator - (const Matrix& New_Matrix);

	Matrix& operator * (const Matrix& New_Matrix);

	Matrix& operator * (const double scalar);

	friend Matrix& operator * (const double scalar, Matrix& Matrix);

	Matrix& operator / (const int scalar);

	double Ñalculating_trace_matrix();

	Matrix& Transposition();
	 
	void Random();

	Matrix Pre_Minor(int row, int col) const;

	double Determinant() const;

	Matrix Allied();

	Matrix Multiplication_by_Vector(const Matrix& Vector,  Matrix& M);
};

