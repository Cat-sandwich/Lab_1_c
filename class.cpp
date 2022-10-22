#pragma once
#include "class.h"
#include <iostream>
using namespace std;



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

unsigned Matrix::Get_m()
{
	return m;
}

unsigned Matrix::Get_n()
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
	if ((i < 0) || (i >= m))
		return;
	if ((j < 0) || (j >= n))
		return;
	data[i][j] = value;
}

void Matrix::Print(const char* ObjName)
{
	cout << "Object: " << ObjName << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << data[i][j] << "\t";
		cout << endl;
	}
	cout << "---------------------" << endl << endl;
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