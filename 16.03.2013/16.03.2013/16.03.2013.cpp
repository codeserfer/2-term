#include "stdafx.h"
#include <iostream>
#include "MyString.h"



int main () {
	setlocale(LC_ALL, "Russian");
	MyString q;
	std::cout << "Введите цифры через запятую\n";
	char* buf=new char [1024];
	std::cin >> buf;
	char* s=new char [strlen(buf)+1];
	strcpy_s (s, strlen(buf)+1, buf);
	delete [] buf;
	q.printNums (s);
	return 0;
}

