#include "task5.h"
#include <iostream>
/*
N - ���������� �����,
buf ������� ������
ch - ������ �����������
*/
void split(char ***result, int *N, char *buf, char ch)
{
	char *ptr = buf;
	int len = 0;
	unsigned rows = 0;
	//��������� ������� (����� ������� ������ ��� ������ ������ ������� ����������, �� ��� �����)
	while (*ptr != '\0') 
	{
		while (*ptr == ch)	//������������ ������� ����������� ���� ��� �������
			ptr++;
		if (*ptr != '\0')	//������� �������
			rows++;
		while ((*ptr != ch) && (*ptr != '\0'))	//��������� �������
			ptr++;
	}
	if (rows == 0)
	{
		*N = 0;
		return;
	}
	//������� ������ ���������� ������ �����
	char **strarr = new char *[rows];
	*N = rows;
	ptr = buf;
	rows = 0;
	while (*ptr != '\0')
	{
		while (*ptr == ch)	//���� ������ ������
			ptr++;
		len = 0;
		while ((*ptr != ch) && (*ptr != '\0'))	//��������� �������
		{
			ptr++;
			len++;
		}
		strarr[rows] = new char[len+1];
		memcpy(strarr[rows], (ptr - len), len);
		strarr[rows][len] = '\0';
		rows++;
	}
	*result = strarr;
}