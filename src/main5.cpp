
#include <locale.h>  
#include <iostream>
#include <string>
#include <cstring>

#include "task5.h"

using namespace std;

int main()
{
	// ��� ���������� ������ ��������� ������ �� �������
	setlocale(LC_ALL, "RUS");
	string term_str;
	char * term_char;
	char term_ch;
	// ������ ��������
	char **result;
	int N;

	while (1)
	{
		setlocale(LC_ALL, "RUS");
		cout << "������� ������ : " << endl;
		setlocale(LC_ALL, "C");

		cin >> term_str;

		setlocale(LC_ALL, "RUS");
		cout << "������� ������ ����������� : " << endl;
		setlocale(LC_ALL, "C");

		cin >> term_ch;

		term_char = (char *)term_str.c_str();

		split(&result, &N, term_char, term_ch);

		setlocale(LC_ALL, "RUS");
		cout << "���������: " << endl;
		setlocale(LC_ALL, "C");
		for (int i = 0; i < N; i++)
		{
			setlocale(LC_ALL, "RUS");
			cout << "������ �" << (i + 1) << "  :  ";
			setlocale(LC_ALL, "C");
			cout << result[i] << endl;
		}

		// ����������� ������
		for (int i = 0; i < N; i++)
		{
			delete result[i];
		}
		//delete result;
	}

	return 0;
}