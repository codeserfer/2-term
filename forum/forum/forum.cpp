#include "stdafx.h"
#include <iostream>
#include "matrix.h"
int main () {
	setlocale(LC_ALL, "Rus");
	matrix q;
	int n, m;
	std::cout << "¬ведите размеры массива\n";
	std::cin >> n;
	std::cin >> m;
	q.make (n, m);
	q.add ();
	q.print ();
	std::cout << "введите новые размеры\n";
	std::cin >> n;
	std::cin >> m;
	q.newsize (n, m);
	q.print ();
	std::cout << "¬ведите номер строки дл€ удалени€ (строки нумируютс€ с 0)\n";
	std::cin >> n;
	q.deln (n);
	q.print ();
	std::cout << "¬ведите номер столбца дл€ удалени€ (столбцы нумируютс€ с 0)\n";
	std::cin >> m;
	q.delm (m);
	q.print ();

	std::cout << "¬ведите номер строки дл€ добавлени€ (строки нумируютс€ с 0)\n";
	std::cin >> n;
	q.addn (n);
	q.print ();

	std::cout << "¬ведите номер столбца дл€ добавлени€ (столбцы нумируютс€ с 0)\n";
	std::cin >> m;
	q.addm (m);
	q.print ();
	return 0;
}

