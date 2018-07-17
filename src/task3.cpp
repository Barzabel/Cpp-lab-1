
#include "task2.h"
#include "task3.h"

// ������� ��������� ����� ���� ������� ����� �� hbound(�� ������� ���)
unsigned long long sumPrime(unsigned int hbound)
{
	// ���� ����� ����������� ������ ���������� 0
	if (hbound < 2)
		return 0;
	// ������ ������� ����� ����� 2
	unsigned long long result = 0;
	unsigned int prime = 2;
	while (prime < hbound)
	{	
		result = result + prime;
		// ���� ��������� ������� �����
		prime = nextPrime(prime);
	}
	return result;
}