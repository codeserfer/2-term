#include "stdafx.h"
#include <iostream>

int stringtonumber (char* s) {
	int num=0;
	int start=0;
	int end=strlen(s)-1;
	if (s[0]=='-') { start=1; end-=1; }
	for (int i=start, j=end; i<strlen (s); i++, j--) {
		num+=((int)s[i]-48)*pow(10, j);
	}
	if (start==0) return num;
	else return (-1*num);
}

int main () {
	setlocale(LC_ALL,"Russian");
	char* n1;
	char* n2;
	char* buf=new char [9999];
	std::cout << "Введите первое число\n";
	std::cin >> buf;
	n1=new char [strlen (buf)+1];
	strcpy_s (n1, strlen (buf)+1, buf);
	std::cout << "Введите второе число\n";
	std::cin >> buf;
	n2=new char [strlen (buf)+1];
	strcpy_s (n2, strlen (buf)+1, buf);
	//std::cout << n1 << " "<<n2;

	int maxlen=0;
	int minlen=0;
	if (strlen (n1)>strlen (n2)) maxlen=strlen (n1)+1;
	else maxlen=strlen (n2)+1;
	if (strlen (n1)>strlen (n2)) minlen=strlen (n2);
	else minlen=strlen (n1);
	char* summ=new char [maxlen];
	int d=0;
	int isumm=maxlen-1;
	std::cout << isumm;
	int i1=strlen (n1)-1, i2=strlen (n2)-1;
	for (; i1>=0&&i2>=0; i1--, i2--) {
		int q1=n1[i1]-48;
		int q2=n2[i2]-48;
		if (q1+q2+d>9) {
			summ [--isumm]=q1+q2+d-10+48;
			d=1;
		}
		else {
			summ [--isumm]=q1+q2+48+d;
			d=0;
		}
		//std::cout << "Сложим " << q1 << " И " << q2<<"\n";
	}
	if (i1>0) for (int i=i1; i>=0; i--) { summ [--isumm]=n1[i]+d; d=0; /*std::cout << "q";*/ }
	if (i2>0) for (int i=i2; i>=0; i--) { summ [--isumm]=n2[i]+d; d=0; /*std::cout << "w";*/ }
	summ [maxlen-1]='\0';
	std::cout << summ;
	
}