#include "stdafx.h"
#include "iostream"
#include "TheMatrix.h"
#include "conio.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Russian");
	TheMatrix m1(1, 2);
	TheMatrix m2(2, 3);
	TheMatrix m3;

	m3 = m1*2;
	m3.show();

	try {
		m3 = m1*m2;
		m3.show();
	} catch (int i) {
		cout << "Нельзя перемножить матрицы\n\n";
	}

	try {
		m3 = m1+m2;
		m3.show();
	} catch (int i) {
		cout << "Нельзя сложить матрицы\n\n";
	}

	_getch();
	return 0;
}