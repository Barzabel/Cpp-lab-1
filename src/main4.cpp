#include <locale.h>  
#include <iostream>
#include <string>
#include <cstring>

#include "task4.h"

using namespace std;

int main()
{
	// ��� ���������� ������ ��������� ������ �� �������
	setlocale(LC_ALL, "RUS");
	string term1_str, term2_str;
	char * term1_char, * term2_char;

	while (1)
	{
		//  ������� ��� ������������ �����
		cout << "������� ������ ����� ��� �������� : " << endl;
		cin >> term1_str;
		cout << "������� ������ ����� ��� �������� : " << endl;
		cin >> term2_str;
		char * result = sum((char *)term1_str.c_str(), (char *)term2_str.c_str());
		cout << "��������� �������� : " << result << endl << endl;
		delete result;
	}
	return 0;
}
