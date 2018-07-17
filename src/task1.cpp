
#include <iostream>
using namespace std;

#include "task1.h"

// ������� ���������� ����������� ������ �������� ��� ��� ���� �����
// ������� ��� �� �������������� ��������� �������
unsigned long nod(unsigned long a, unsigned long b)
{
	unsigned long tmp;
	while (a != b)
	{
		if (a > b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}

// ������� ���������� ����������� ������ �������� ��� ��� ���� �����
unsigned long nok(unsigned long a, unsigned long b)
{
	unsigned long  result;
	result = (unsigned long long int)a * (unsigned long long int)b / nod(a, b);
	return  result;
}

// ������ ���������� ����������� ������ �������� ��� ��� ���� ����������� ����� �������� � ��������� min - max
unsigned long findValue(unsigned int min, unsigned int max)
{
	// ������ min � max ������� ���� ��� ���������� 
	if (min > max)
	{
		unsigned int tmp = min;
		min = max;
		max = tmp;
	}
	// ������� ���
	unsigned long result = min;
	for (unsigned long i = min + 1; i <= max; i++)
	{
		result = nok(result,i);
	}
	return result;
}

// ������� ��� �������� ������������ �����
unsigned int getValue()
{
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		unsigned int a;
		cin >> a;
		// �������� �� ���������� ����������
		// ���� ���������� ���������� ��������� ����������
		if (cin.fail())
		{
			cin.clear(); // ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n'); // � ������� �������� ����������� ����� �� �������� ������
			cout << endl << "�� ����� ������������ ��������, ���������� �����" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // ������� ������ ��������
			return a;
		}
	}
}