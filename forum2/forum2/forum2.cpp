// forum2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Time.h"
int sumd (int a) { //сумма делителей числа a
	int sum=0;
	for (int i=1; i<a/2+1; i++) if (a%i==0) sum+=i;
	return sum;
}

bool perfect (int a) {
	if (sumd(a)==a) return true;
	return false;
}

void printd (int a) {
	for (int i=2; i<a/2+1; i++) if (a%i==0) std::cout << "+"<<i;
}
int main () {

	/*for (int i=2; i<=1000; i++) if (perfect(i)) {
		std::cout<<i<<": ";
		std::cout << "1";
		printd(i);
		std::cout << "\n";
	}*/

	Time* q=new Time ();
	Time* b=new Time (1, 2, 3);
	Time* c=new Time (4,-5 ,4);
	delete q;
	delete b;
	delete c;
	return 0;
}