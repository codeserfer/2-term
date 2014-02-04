#include "stdafx.h"
#include "MyString.h"
#include <iostream>

MyString::MyString(void){
	s1=NULL;
	longest=0;
	longestid=0;
}

MyString::MyString (char* k) {
	MyString ();
	s1=NULL;
	input (k);
}

MyString::MyString (MyString& old) {
	MyString ();
	s1=NULL;
	input (old.s1);
}
MyString::~MyString(void){
	
}

void MyString::cut_screen () {
	//надо обработать случай двойных пробелов
	for (int i=0; i<strlen (s1); i++) {
		if (((int)s1[i]>=int('0') && (int)s1[i]<=int('9')) || ((int)s1[i]>=int('a') && (int)s1[i]<=int('z'))) std::cout << s1[i]; else std::cout <<std::endl;
	}
	return;

}



int MyString::count (char* s) {
	//надо обработать случай двойных пробелов
	int c=0;
	for (int i=0; i<strlen (s); i++) {
		if (!(((int)s[i]>=int('0') && (int)s[i]<=int('9')) || ((int)s[i]>=int('a') && (int)s[i]<=int('z')))) c++;
	}
	return ++c;

}

void MyString::paste (char* s, int n) {
	//char* s2=new char [strlen(s1)+strlen(s)];
	//strcpy_s (s1, n, s);
	//for (int i=0; i<n; i++) std::cout << s1[i];//s2[i]=s1[i];
	//for (int i=0; i<strlen (s); i++) std::cout << s[i]; //s2[i]=s[i-n];
	//for (int i=n+strlen(s); i<strlen (s1)-strlen(s); i++) s1[i-strlen(s)];//s2[i]=s[i-strlen(s)];
	//return s2;
	//return "";
	
	char* half1=new char [(strlen (s1)+strlen (s)+1];
	strncpy (half1, s1, n);
	half1 [n]='\0';
	char* half2=new char [strlen(s)];
	for (int i=n, j=0; i<strlen (s1); i++, j++) {
		half2[j]=s1[i];
	}
	strcat (half1, s);
	strcat (half1, half2);
	delete [] s1;
	delete half2;
	s1=half1;
}

void MyString::get_array () {
	int q=count (s1);
	char**m=new char* [q];
	char buf [256];
	int w=0;
	e=0;
	for (int i=0; i<strlen (s1)+1; i++) {
		if (((int)s1[i]>=int('0') && (int)s1[i]<=int('9')) || ((int)s1[i]>=int('a') && (int)s1[i]<=int('z'))) {
			buf[w++]=s1[i];
		}
		else {
			m[e]=new char [w+1];
			if (longest<w) { longest=w; longestid=e; }
			//strcpy_s (m[e], w+1, buf);
			for (int j=0; j<w+1;j++) m[e][j]=buf[j];
			m[e][w]='\0';
			std::cout <<  m[e] << " " << std::endl;
			//m[e++]=buf;
			e++;
			w=0;
		}
	}
	std::cout << "Longest word is - " << m[longestid];
}

void MyString::input () {
	char buf [256];
	std::cin >> buf;
	if (s1) delete [] s1;
	char* s=new char [strlen (buf)+1];
	strcpy_s (s, strlen (buf)+1, buf);
	delete [] buf;
	s1=s;
	return;
}

void MyString::input (char* buf) {
	if (s1) delete [] s1;
	char* s=new char [strlen (buf)+1];
	strcpy_s (s, strlen (buf)+1, buf);
	s1=s;
	return;
}

char* MyString::output () {
	return s1;
}

void MyString::output_screen () {
	std::cout << s1;
	return;
}

void MyString::anagram () {
	int len=strlen (s1);
	for (int i=0; i<len/2; i++) s1[i]=s1[len-i];
}



	return;
}