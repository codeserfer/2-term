#include "stdafx.h"
#include "MyString.h"
#include <iostream>

MyString::MyString(void) {
	
}


MyString::~MyString(void) {
	delete [] s;
}

bool MyString::p (char* s) {
	for (int i=0; i<strlen (s)-1; i++) if (s[i]>=s[i+1]) return false;
	return true;

}
char* MyString::cat (char* s, int q1, int q2) {
	char s1 [1024];
	int w=0;
	for (int i=q1; i<q2+1; i++, w++) {
		s1 [w]=s[i];
	}
	s1[w]='\0';
	char* s2=new char (strlen (s1)+1);
	int i;
	for (i=0; i<strlen (s1); i++) s2[i]=s1[i];
	s2[i]='\0';
	return s2;
}
int MyString::stringtonumber (char* s){
	int num=0;
	for (int i=0, j=strlen(s)-1; i<strlen (s); i++, j--) {
		num+=((int)s[i]-48)*pow(10, j);
	}
	return num;
}
void MyString::printNums (char* s) {
	int q=0;
	char* s1=new char [strlen (s)+2];
	s1[strlen(s)]=',';
	s1[strlen(s)+1]='\0';
	for (int i=0; i<strlen(s); i++) s1[i]=s[i];
	s=s1;
	for (int i=0; i<strlen (s); i++) {
		if (s[i]==',') { 
			char* temp=new char [i-q+1];
			temp=cat (s, q, i-1);
			//if (p(temp)) std::cout <<temp << "\n"; //возвращает char*
			if (p(temp)) std::cout << stringtonumber (temp) <<"\n"; //возвращает int
			q=i+1; 
		}
	}
	return;
}
