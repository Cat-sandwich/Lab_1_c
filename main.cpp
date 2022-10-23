#include <stdio.h>
#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
char NUM[] = { '0','1','2','3','4','5','6','7','8','9' };

int check()
{
	int number = 0;
	while (number <= 0)
	{
		while (!(cin >> number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ���������� ��������...\n";
		}
		if (number <= 0) cout << "������� ���������� ��������...\n";
		
	}
	
	return number;
}

 
Matrix Random_Matrix(int m, int n)
{
	Matrix New_matrix(m, n);
	New_matrix.Random();
	return  New_matrix;
}

void Add_Matrix(int* size, Matrix ** Many_Matrix, Matrix New_matrix )
{
	*size += 1;
	Matrix* tmp = new Matrix[*size];
	if(*size-1 != 0)
	{
		for (int i = 0; i < (* size) - 1; i++)
		tmp[i] = (* Many_Matrix)[i];
	delete[] (* Many_Matrix);
	}
	tmp[*size - 1] = New_matrix;
	*Many_Matrix = tmp;
	
}
void Print_Matrix(Matrix* Many_Matrix, int current, int size)
{
	
	if (Many_Matrix == NULL) cout << "������ ���(\n\n";
	else (Many_Matrix)[current].Print(current+1);
}

int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}
void menu1()
{
	int key = 0;	
	bool menu1 = true;
	Matrix* Many_Matrix = NULL;
	Matrix New_matrix;
	int current = 0, size = 0;
	while (menu1)
	{
		
		system("cls");
		cout << "\t��� �������\n" << endl;
		Print_Matrix(Many_Matrix, current, size);
		cout<<"1 - ������ ������� ��������\n2 - ������� ��� ������� \n3 - ������� �� ����� ������� ������\n"<<endl;
		cout << "4 - �������� ���� ������� �� ������\n5 - ��������� �������\n0 - ��������� ������\n" << endl;
		cout << "-> ������\n-< �����\n" << endl;
		key = get_key();
		int m = 0, n = 0;
		switch (key)
		{
		case(49):

			cout <<"\t������� ����������� �������:\n\n" << endl;
			cout << "\n������� ���������� ��������:" << endl;
			m = check();		

			cout << "\n������� ���������� �����: " << endl; 
			n = check();
			printf("������ �������\n ");
			system("pause");

			New_matrix = Random_Matrix(m, n);			
			Add_Matrix( &size, &Many_Matrix, New_matrix);
			
			break;
		case(50):
			if ((size + 1) < 2)
			{
				cout << "\n� ��� ������ ���� ���� �� ��� �������...\n" << endl;
				system("pause");
				break;
			}			
			do
			{
				cout << "������� ����� �������, ������� �� ������ ������� � �������:\n" << endl;
				m = check();
				system("pause");
			} while (m > size);
			try
			{
			New_matrix = Many_Matrix[current] + Many_Matrix[m - 1];
			}
			catch (Exception& error)
			{
				error.print();
				system("pause");
			}
			Add_Matrix(&size, &Many_Matrix, New_matrix);
			break;
		case(51):
			if ((size + 1) < 2)
			{
				cout << "\n� ��� ������ ���� ���� �� ��� �������...\n" << endl;
				system("pause");
				break;
			}
			do
			{
				cout << "������� ����� �������, ������� �� ������ �������:\n" << endl;
				m = check();
				system("pause");
			} while (m > size);
			try
			{
				New_matrix = Many_Matrix[current] - Many_Matrix[m - 1];
			}
			catch (Exception& error)
			{
				error.print();
				system("pause");
			}
			Add_Matrix(&size, &Many_Matrix, New_matrix);
			
			break;
		case(52):
			if ((size + 1) < 2)
			{
				cout << "\n� ��� ������ ���� ���� �� ��� �������...\n" << endl;
				system("pause");
				break;
			}
			do
			{
				cout << "������� ����� �������, ������� �� ������ �������� �� �������:\n" << endl;
				m = check();
				system("pause");
			} while (m > size);
			try
			{
				New_matrix = Many_Matrix[current] * Many_Matrix[m - 1];
			}
			catch (Exception& error)
			{
				error.print();
				system("pause");
			}
			Add_Matrix(&size, &Many_Matrix, New_matrix);

			break;
		case(53):

			break;
		case(48):
			system("cls");

			system("pause");
			menu1 = false;
			break;
		case 75:
			if (current > 0) current--;
			break;
		case 77:
			if (current < size-1) current++;
			break;
		default:
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "������������! ��� ������������ ��������� \"����� ������\"\n" << endl;
	system("pause");
	menu1();
	system("pause");
	return 0;
}