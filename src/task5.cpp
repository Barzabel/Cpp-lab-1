
#include <cstring>
#include "task5.h"

// ������� ��������� ������ �� ������ �� �����������
// int *N - ��������� �� ���������� �����
// char *buf - ������ ������� ����� �������
// char ch - ������ �����������
// char ***result - ���������

void split(char ***result, int *N, char *buf, char ch)
{
	// ��������
	int start_str = 0;
	int count_str = 0;
	int cut_str = 0;

	// ������� ������� �������� ����� ������� � ���������� ������� ����������� �� ������ ������
	int count_str_max = 0;
	bool ch_in_start_str = false;
	for (int i = 0; i < strlen(buf) + 1; i++)
	{
		// ���� ����������� ����� � ������ ������
		if (buf[i] == ch && i == 0)
		{
			ch_in_start_str = true;
			start_str = i + 1;
			continue;
		}
		else if (buf[i] == ch && ch_in_start_str == true)
		{
			start_str = i + 1;
			continue;
		}
		else
			ch_in_start_str = false;
		if ((buf[i] == '\0' && buf[i - 1] != ch) || ((i < strlen(buf)) && (buf[i] == ch) && (buf[i + 1] != ch)))
			count_str_max = count_str_max + 1;
	}	

	char ** str_arr = new char*[count_str_max];
	// ���������� ��� ������� ������ � '\0' 
	for (int i = start_str; i < strlen(buf) + 1; i++)
	{
		// ���� ����� ������ ����������� ��� ����� ������
		// � ��������� �������������� �������� �� ���� ������
		if ((buf[i] == '\0' && buf[i - 1] != ch) || ((i < strlen(buf)) && (buf[i] == ch) && (buf[i + 1] != ch)))
		{
			// ���������� ����� ������
			str_arr[count_str] = new char[i - start_str + 1 - cut_str];
			for (int j = 0; j < i - start_str - cut_str; j++)
			{
				str_arr[count_str][j] = buf[start_str + j];
			}
			// ��������� � ����� ������ ������� ������
			str_arr[count_str][i - start_str - cut_str] = '\0';
			count_str = count_str + 1;
			start_str = i + 1;
			cut_str = 0;
		}
		// ���� ��������� �������������� �������� ���� ������ ��� � ����� ������
		if ((buf[i] == '\0' && buf[i - 1] == ch) || ((i < strlen(buf)) && (buf[i] == ch) && (buf[i + 1] == ch)))
			cut_str = cut_str + 1;
	}
	// ����������� �������� ��������
	*N = count_str_max;
	*result = str_arr;
}