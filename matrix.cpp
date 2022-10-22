#pragma once
#include "matrix.h"
#include "exceptions.h"
#include <iostream>
using namespace std;


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

void Matrix::Print(const char* ObjName)
{
	if (data == NULL) throw Empty();
	cout << "Object: " << ObjName << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << data[i][j] << "\t";
		cout << endl;
	}
	cout << "---------------------" << endl << endl;
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

double Matrix::operator () (int m, int n)
{
	if ((m > this->m) || (n > this->n)) throw Invalid_Index(m, n, this->m, this->n);

	return this->data[m][n];
}

Matrix& Matrix::operator () (int m, int n, int value)
{
	if ((m > this->m) || (n > this->n)) throw Invalid_Index(m, n, this->m, this->n);

	this->data[m][n] = value;
	return *this;

}

Matrix& Matrix::operator + (const Matrix& Maxtrix) {
	if (this->m != Maxtrix.m || this->n != Maxtrix.n) throw Different_Dimensions();

	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < n; j++) {
			this->data[i][j] += Maxtrix.data[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator - (const Matrix& Matrix) {
	if (this->m != Matrix.m || this->n != Matrix.n) throw Different_Dimensions();

	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < n; j++) {
			this->data[i][j] -= Matrix.data[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator * (const Matrix& M)
{
	if (n != M.n) throw Different_Dimensions();

	Matrix res(m, n);
	res.Reset();

	for (int i = 0; i < res.m; ++i)
		for (int j = 0; j < res.n; ++j)
			for (int k = 0; k < m; ++k)
				res.data[i][j] += data[i][k] * M.data[k][j];

	return res;
}