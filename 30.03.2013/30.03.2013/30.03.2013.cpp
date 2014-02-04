// 30.03.2013.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "matrix.h"

int main () {
	matrix q;
	q.make (2, 2);
	q.add ();
	matrix q1;
	q1=q*2;
	q1.print ();
	//q.print ();

	return 0;
}
