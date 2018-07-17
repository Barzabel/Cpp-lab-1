#include "task2.h"
#include <cmath>
#include <ctime>

#include <iostream>

using namespace std;


// �������� ����� �� ��������
bool checkPrime(unsigned int value)
{	
	for (unsigned int i = 2; i <= sqrt(value); i++)
		if (value%i == 0)
			return false;
	return true;
}

// ���������� n - ��� �������� �����(� ����).
unsigned long long nPrime(unsigned int n)
{
	// ���� n ����������� ���������� 0
	if (n < 1)
		return 0;

	// ������ ������� ����� � ���� - 1
	unsigned long long result = 1;

	// ������� �������� ������ ��� ������� ����� �� ������� �� n
	// ������ ����� �� ��� �����
	for (unsigned int i = 0; i < n; i++)
	{
		// ��������� ����� ���������� �������� �����
		result = result + 1;
		// ����� ���������� ����� ���� �� ������ �������
		while (checkPrime(result) == false)
		{
			result = result + 1;
		}
	}
	return result;
}

// ���������� ���������� ���������� �������� ����� � value.
unsigned long long nextPrime(unsigned long long value)
{
	unsigned long long result;
	if (value == 0 || value == 1)
		result = 2;
	else
		result = value + 1;
	// ������� ��������� ������� �����
	while (checkPrime(result) == false)
	{
		result = result + 1;
	}

	return result;
}