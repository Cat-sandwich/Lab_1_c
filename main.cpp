#include <stdio.h>
#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
char NUM[] = { '0','1','2','3','4','5','6','7','8','9' };

int Check_Int()
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
double Check_Double()
{
	double number = 0;
	
	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������� ���������� ��������...\n";
	}
		

	return number;
}

void �hange_Matrix(Matrix** Many_Matrix, const int & current)
{
	cout << "������� ������� ��������, ������� ����� ��������:";
	int i = Check_Int() - 1;
	int j = Check_Int() - 1;
	cout << "������� ��������, �� ������� �� ������ �������� �����:";
	double value = Check_Double();
	(Many_Matrix[current])->Set_Data_Value(i, j, value);
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
	Matrix* Vector = NULL;
	int current = 0, size = 0;
	double value = 0;
	while (menu1)
	{
		
		system("cls");
		cout << "\t��� �������\n" << endl;
		Print_Matrix(Many_Matrix, current, size);

		cout<<"1 - ������ ������� ��������\n2 - ������� ��� ������� \n3 - ������� �� ����� ������� ������"<<endl;
		cout << "4 - �������� ���� ������� �� ������\n5 - ��������� �� ������\n6 - ��������� ��� ������" << endl;
		cout << "7 - ��������� ���� �������\n8 - ��������� �������" << endl;
		cout << "9 - �������� ���� �������� � ������� �������\n0 - ��������� ������" << endl;
		cout << "\"+\" - ������ ������� � ������������ ������" << endl;
		cout << "-> ������\n-< �����\n" << endl;

		double Scalar = 0;

		key = get_key();
		int m = 0, n = 0;
		switch (key)
		{
		case(49):

			cout << "\t������� ����������� �������: \n" ;
			cout << "\n������� ���������� ��������: " ;
			m = Check_Int();

			cout << "������� ���������� �����: " ;
			n = Check_Int();
			printf("������ �������\n ");
			system("pause");
			
			New_matrix = Random_Matrix(m, n);
			Add_Matrix(&size, &Many_Matrix, New_matrix);

			break;
		case(50):
			if ((size + 1) < 2)
			{
				cout << "\n� ��� ������ ���� ���� �� ��� �������...\n" << endl;
				system("pause");
				break;
			}
			cout << "������� ����� �������, ������� �� ������ ������� � �������:\n" << endl;
			m = Check_Int();
			while (m > size)
			{
				cout << "����� ������� ���..." << endl;
				cout << "���������� ��� ���..." << endl;
				m = Check_Int();

			} 
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
			cout << "������� ����� �������, ������� �� ������ �������:\n" << endl;
			m = Check_Int();

			while (m > size)
			{
				cout << "����� ������� ���..." << endl;
				cout << "���������� ��� ���..." << endl;
				m = Check_Int();
			}
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
				m = Check_Int();
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
			if (size == 0)
			{
				cout << "\n� ��� ������ ���� ���� �� ���� �������...\n" << endl;
				system("pause");
				break;
			}
			cout << "������� �����:" << endl;
			cin >> Scalar;
			New_matrix = Many_Matrix[current] * Scalar;
			Add_Matrix(&size, &Many_Matrix, New_matrix);
			system("pause");
			break;
		case(54):
			if (size == 0)
			{
				cout << "\n� ��� ������ ���� ���� �� ���� �������...\n" << endl;
				system("pause");
				break;
			}
			cout << "������� �����:" << endl;
			cin >> Scalar;
			try
			{
				New_matrix = Many_Matrix[current] / Scalar;

				Add_Matrix(&size, &Many_Matrix, New_matrix);
			}
			catch (Exception& Error)
			{
				Error.print();
				system("pause");
			}

			
			break;
		
		case(55):
			if (size == 0)
			{
				cout << "\n� ��� ������ ���� ���� �� ���� �������...\n" << endl;
				system("pause");
				break;
			}
			try
			{
				cout <<"���� ������� = " << Many_Matrix[current].�alculating_trace_matrix() << endl;
				system("pause");
			}
			catch (Exception& Error)
			{
				Error.print();
				system("pause");
			}
			break;
			
		case(56):
			if (size == 0)
			{
				cout << "\n� ��� ������ ���� ���� �� ���� �������...\n" << endl;
				system("pause");
				break;
			}
			if ((Many_Matrix[current].Get_m() == Many_Matrix[current].Get_n()) && (Many_Matrix[current].Get_m() != 3))
			{
				cout << "\n�������� ������� � �������� ��� �� ���...\n" << endl;
				system("pause");
				break;
			}

			Vector = new Matrix(3, 1);
			Vector->Random();

			Add_Matrix(&size, &Many_Matrix, *Vector);
			try
			{
				New_matrix = Many_Matrix[current].Search_Matrix_X(*Vector);
				Add_Matrix(&size, &Many_Matrix, New_matrix);
			}
			catch (Exception& Error)
			{
				Error.print();
				system("pause");
			}
						

			break;
		case(57):
			if (size == 0)
			{
				cout << "\n� ��� ������ ���� ���� �� ���� �������...\n" << endl;
				system("pause");
				break;
			}
			try
			{
				�hange_Matrix(&Many_Matrix, current);
				system("pause");
			}
			catch (Exception& Error)
			{
				Error.print();
				system("pause");
			}
			break;
		case(61):
			
			cout << "\t������� ����������� �������: \n";
			cout << "\n������� ���������� ��������: ";
			m = Check_Int();

			cout << "������� ���������� �����: ";
			n = Check_Int();
			
			cout << "\t������� �����, ������� ����� ��������� ��� �������:";
			value = Check_Double();
			New_matrix(m, n, value);
			Add_Matrix(&size, &Many_Matrix, New_matrix);
			cout << "������ �������\n ";
			system("pause");
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