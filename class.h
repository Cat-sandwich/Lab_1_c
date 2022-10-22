#include <iostream>
using namespace std;


class Matrix
{
private:
	double** data;
	int m, n;

public:

	Matrix(int m, int n, double** matrix);

	Matrix(const Matrix& Matrix);

	void Set_m(int m = 1);

	void Set_n(int n = 1);

	unsigned Get_m();

	unsigned Get_n();

	double Get_Data(int i, int j);

	void Set_Data(int i, int j, double value);

	void Print(const char* ObjName);

	Matrix& operator =(const Matrix& Matrix);

	~Matrix();
};

