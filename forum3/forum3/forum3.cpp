#include "stdafx.h"
#include <iostream>
#include "Rational.h"


int main () {
	setlocale(LC_ALL,"Russian");
	try {
		Rational q (16, 5);
		Rational w (10, 4);
		Rational e, r, t, y, u;
		e=e.sum (q, w);
		r=r.diff (q, w);
		t=t.mult (q, w);
		y=y.divis (q, w);
		Rational a (3, 5);
		u=u.sum (a, 2);
		std::cout << "Сумма дробей "; q.print1 (); std::cout<< " и ";  w.print1 (); std::cout<< " равна "; e.print1 (); std::cout <<"\n";
		std::cout << "Сумма дроби "; a.print1 (); std::cout << "и целого числа 2 равна "; u.print1 (); std::cout << "\n";
		std::cout << "Разность дробей "; q.print1 (); std::cout<< " и ";  w.print1 (); std::cout<< " равна "; r.print1 (); std::cout <<"\n";
		std::cout << "Произведение дробей "; q.print1 (); std::cout<< " и ";  w.print1 (); std::cout<< " равно "; t.print1 (); std::cout <<"\n";
		std::cout << "Частное дробей "; q.print1 (); std::cout<< " и ";  w.print1 (); std::cout<< " равно "; y.print1 (); std::cout <<"\n";
		std::cout << "Дроби "; q.print1 (); std::cout << " и "; w.print1 (); std::cout << " можно также записать как "; q.print2 (); std::cout << " и "; w.print2 (); std::cout << "\n";
		std::cout << "Сравнение дробей "; q.print1(); std::cout << " и "; w.print1(); std::cout << ": "<< q.compare (q, w)<<"\n";


		Rational q1 (-4, 5);
		Rational q2 (2, -5);
		Rational q3=q3.sum (q1, q2);
		std::cout << "Сумма дробей "; q1.print1 (); std::cout<< " и ";  q2.print1 (); std::cout<< " равна "; q3.print1 (); std::cout <<"\n";

		Rational q4 (6, 13);
		Rational q5=q5.mult (q4, 2);
		std::cout << "Произведение дроби "; q4.print1 (); std::cout << " и целого числа 2 равна "; q5.print1 (); std::cout <<"\n";
		std::cout << "\n";
	}
	catch (int err) {
		if (err==0) std::cout << "Знаменатель не может быть равен 0!\n";

	}
	return 0;
}

