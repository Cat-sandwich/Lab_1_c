#pragma once
#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <random>
using namespace std;

Matrix::Matrix(){}

Matrix::Matrix(int m, int n)
{
	this->m = m;
	this->n = n;

	data = (double**) new double* [m];

	for (int i = 0; i < m; i++)
		data[i] = (double*)new double[n];

}
Matrix::Matrix(int m, int n, double** matrix)
{
	this->m = m;
	this->n = n;

	matrix = (double**) new double* [m];

	for (int i = 0; i < m; i++)
		matrix[i] = (double*)new double[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			this->data[i][j] = matrix[i][j];
}

Matrix::Matrix(const Matrix& Matrix)
{
	m = Matrix.m;
	n = Matrix.n;


	data = (double**) new double* [m];

	for (int i = 0; i < m; i++)
		data[i] = (double*) new double[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			data[i][j] = Matrix.data[i][j];
}

void Matrix::Set_m(int m)
{
	if (m > 0)
		this->m = m;
}

void Matrix::Set_n(int n)
{
	if (n > 0)
		this->n = n;
}

int Matrix::Get_m()
{
	return m;
}

int Matrix::Get_n()
{
	return n;
}

double Matrix::Get_Data(int i, int j)
{
	if ((m > 0) && (n > 0))
		return data[i][j];
	else
		return 0;
}
void Matrix::Set_Data(int i, int j, double value)
{
	if (data == NULL) throw Empty();
	data[i][j] = value;
}

void Matrix::Print(const int& Number_Matrix)
{
	if (data == NULL) throw Empty();
	cout << "Number_Matrix: " << Number_Matrix << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << data[i][j] << "\t";
		cout << endl;
	}
}

void Matrix::Reset()
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = 0;
}
Matrix& Matrix::operator =(const Matrix& Matrix)
{
	if (n > 0)
	{
		for (int i = 0; i < m; i++)
			delete[] data[i];
	}

	if (m > 0)
	{
		delete[] data;
	}

	m = Matrix.m;
	n = Matrix.n;

	data = (double**) new double* [m];
	for (int i = 0; i < m; i++)
		data[i] = (double*) new double[n];

	for (int i = 0; i < m; i++)
 		for (int j = 0; j < n; j++)
			data[i][j] = Matrix.data[i][j];
	return *this;
}

Matrix::~Matrix()
{
	if (n > 0)
	{
		for (int i = 0; i < m; i++)
			delete[] data[i];
	}

	if (m > 0)
		delete[] data;
}

double& Matrix::operator ()(int m, int n) const
{
	if ((m > this->m) || (n > this->n)) throw Invalid_Index(m, n, this->m, this->n);

	return (double&) data[m][n];
}

Matrix& Matrix::operator () (int m, int n, int value)
{
	if ((m > this->m) || (n > this->n)) throw Invalid_Index(m, n, this->m, this->n);

	this->data[m][n] = value;
	return *this;

}

Matrix Matrix::operator + (const Matrix& New_Matrix) {
	if (this->m != New_Matrix.m || this->n != New_Matrix.n) throw Different_Dimensions();
	Matrix res(m, n);
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < n; j++) {
			res.data[i][j] = this->data[i][j] + New_Matrix.data[i][j];
		}
	}
	return res;
}

Matrix Matrix::operator - (const Matrix& New_Matrix) {
	if (this->m != New_Matrix.m || this->n != New_Matrix.n) throw Different_Dimensions();

	Matrix res(m, n);
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < n; j++) {
			res.data[i][j] = this->data[i][j] - New_Matrix.data[i][j];
		}
	}
	return res;
}

Matrix& Matrix::operator * (const Matrix& New_Matrix)
{
	if (n != New_Matrix.m) throw Different_Dimensions();

	Matrix res(m, n);
	res.Reset();

	for (int i = 0; i < res.m; ++i)
		for (int j = 0; j < res.n; ++j)
			for (int k = 0; k < m; ++k)
				res.data[i][j] += data[i][k] * New_Matrix.data[k][j];

	return res;
}

Matrix& Matrix::operator * (const double scalar)
{
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			this->data[i][j] *= scalar;
		}
	}
	return *this;
}

Matrix& operator * (const double scalar, Matrix& Matrix)
{
	return Matrix * scalar;
}

Matrix& Matrix::operator / (const int scalar) {
	if (scalar == 0) throw Divizion_By_Zero();
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			this->data[i][j] /= scalar;
		}
	}
	return *this;
}

double Matrix::Ñalculating_trace_matrix()
{
	if (n != m) throw Different_Dimensions();
	double trace = 0;
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			if (i == j)
				trace += data[i][j];
		}
	}
	return trace;
}

Matrix& Matrix::Transposition()
{
	if (data == NULL) throw Empty();
	Matrix res(n, m);
	res.Reset();

	for (int i = 0; i < m; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			res.data[i][j] = data[j][i];
		}
	}
	return res;

}

void Matrix::Random()
{
	srand(time(0));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = 1 + rand() % 10;
}

Matrix Matrix::Pre_Minor(int row, int col) const
{
	if (n != m) throw Different_Dimensions();
	Matrix New_Matrix(m - 1, n -1);
	int i, j, in, jn;

	for (i = 0, in = 0; i < m; i++) {
		if (i != row) {
			for (j = 0, jn = 0; j < m; j++) {
				if (j != col) {
					New_Matrix(in, jn++) = (*this)(i, j);
				}
			}
			in++;
		}
	}
	return New_Matrix;
}

double Matrix::Determinant() const
{
	double determ = 0;
	if (m == 1) {
		return (*this)(0, 0);
	}
	for (int i = 0; i < m; i++) {
		double a = (*this)(0, i) * (i % 2 ? -1 : 1);
		determ += a * this->Pre_Minor(0, i).Determinant();
	}
	return determ;
}

Matrix Matrix::Allied()
{
	if (((m - 1) <= 0) || (m != n))	throw Different_Dimensions();

	Matrix New_Matrix(m, n);
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			New_Matrix(i, j) = this->Pre_Minor(i, j).Determinant() * ((i + j) % 2 ? -1 : 1);
		}
	}
	return New_Matrix;
}

Matrix Matrix::Multiplication_by_Vector(const Matrix& Vector,  Matrix& M)
{
	if (M.n != Vector.m) throw Different_Dimensions();
	Matrix Mat = M.Allied();
	return Mat * Vector;
}