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
		std::cout << "����� ������ "; q.print1 (); std::cout<< " � ";  w.print1 (); std::cout<< " ����� "; e.print1 (); std::cout <<"\n";
		std::cout << "����� ����� "; a.print1 (); std::cout << "� ������ ����� 2 ����� "; u.print1 (); std::cout << "\n";
		std::cout << "�������� ������ "; q.print1 (); std::cout<< " � ";  w.print1 (); std::cout<< " ����� "; r.print1 (); std::cout <<"\n";
		std::cout << "������������ ������ "; q.print1 (); std::cout<< " � ";  w.print1 (); std::cout<< " ����� "; t.print1 (); std::cout <<"\n";
		std::cout << "������� ������ "; q.print1 (); std::cout<< " � ";  w.print1 (); std::cout<< " ����� "; y.print1 (); std::cout <<"\n";
		std::cout << "����� "; q.print1 (); std::cout << " � "; w.print1 (); std::cout << " ����� ����� �������� ��� "; q.print2 (); std::cout << " � "; w.print2 (); std::cout << "\n";
		std::cout << "��������� ������ "; q.print1(); std::cout << " � "; w.print1(); std::cout << ": "<< q.compare (q, w)<<"\n";


		Rational q1 (-4, 5);
		Rational q2 (2, -5);
		Rational q3=q3.sum (q1, q2);
		std::cout << "����� ������ "; q1.print1 (); std::cout<< " � ";  q2.print1 (); std::cout<< " ����� "; q3.print1 (); std::cout <<"\n";

		Rational q4 (6, 13);
		Rational q5=q5.mult (q4, 2);
		std::cout << "������������ ����� "; q4.print1 (); std::cout << " � ������ ����� 2 ����� "; q5.print1 (); std::cout <<"\n";
		std::cout << "\n";
	}
	catch (int err) {
		if (err==0) std::cout << "����������� �� ����� ���� ����� 0!\n";

	}
	return 0;
}

