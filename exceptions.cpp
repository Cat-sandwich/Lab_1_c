#include "exceptions.h"
#include "matrix.h"
#include <iostream>
using namespace std;


Exception::Exception() {}

Invalid_Index::Invalid_Index(int i, int j, int m ,int n)
{
	this->i = i;
	this->j = j;
	this->m = m;
	this->n = n;

}

void Invalid_Index::print() const {
	cout << "��������� ������: ������ " << i << j << " �� ������" << endl;
}


Empty::Empty() {}

void Empty::print() const 
{
	cout << "��������� ������: � ������� ��� ���������" << endl;
}

Different_Dimensions::Different_Dimensions(){}

void Different_Dimensions::print() const 
{
	cout << "��������� ������: ����������� ������ �� ���������" << endl;
}

Divizion_By_Zero::Divizion_By_Zero() {}

void Divizion_By_Zero::print() const
{
	cout << "��������� ������: ������� ������� �� ����" << endl;
}
