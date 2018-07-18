﻿// Task_1.cpp: определяет точку входа для консольного приложения.
//
#include <locale.h>  
#include <iostream>
using namespace std;

#include "task1.h"

int main()
{
	// Для коректного вывода руссукого текста на консоль
	setlocale(LC_ALL, "RUS");

	cout << "Введите два натуральных числа," << endl <<
		    "для нахождения наименьшего общего числа, которое делиться" << endl <<
		    "на все числа из диапозона между ними" << endl << endl;

	unsigned int min, max;
	while (1)
	{
		cout << "Введите первое число диапозона: " << endl;

		min = getValue();

		cout << endl << "Введите второе число диапозона: " << endl << endl;

		max = getValue();

		unsigned long result = findValue(min, max);

		cout << "Результат вычисления равен : " << result << endl << endl;
	}

	return 0;
}

