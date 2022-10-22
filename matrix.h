#include <iostream>
using namespace std;


class Matrix
{
private:
	double** data;
	int m, n;

public:
	Matrix(int m, int n);

	Matrix(int m, int n, double** matrix);

	Matrix(const Matrix& Matrix);

	void Set_m(int m = 1);

	void Set_n(int n = 1);

	int Get_m();

	int Get_n();

	double Get_Data(int i, int j);

	void Set_Data(int i, int j, double value);

	void Print(const char* ObjName);

	void Reset();

	Matrix& operator =(const Matrix& Matrix);

	~Matrix();

	double operator () (int m, int n);

	Matrix& operator () (int m, int n, int new_value);

	Matrix& operator + (const Matrix& Matrix);

	Matrix& operator - (const Matrix& Matrix);

	Matrix& operator * (const Matrix& Matrix);
};

