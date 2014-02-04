#include "stdafx.h"
#include "matrix.h"
#include <iostream>

matrix::matrix(void) {
	a=NULL;
	n=0;
	m=0;
}


matrix::~matrix(void) {
	for (int i=0; i<m; i++) delete [] a[i];
	delete [] a;
	a=NULL;
}

void matrix::make (int n1, int m1) {
	a=new int* [n1];
	for (int i=0; i<m1; i++) a[i]=new int [n1];
	n=n1;
	m=m1;
	return;
}
void matrix::add () {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			std::cin >> a[i][j];
		}
	}
	return;
}

void matrix::print () {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			std::cout << a[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

void matrix::newsize (int n1, int m1) {
	int** b=new int* [n1];
	for (int i=0; i<m1; i++) b [i]=new int [n1];
	for (int i=0; i<n1; i++) {
		for (int j=0; j<m1; j++) {
			if ((i<n) && (j<m)) b[i][j]=a[i][j];
			else b[i][j]=0;
		}
	}
	a=b;
	n=n1;
	m=m1;
	return;
}

void matrix::deln (int n1) {
	int** b=new int* [n-1];
	for (int i=0; i<n-1; i++) b [i]=new int [m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i<=n1) b[i][j]=a[i][j];
			else b[i-1][j]=a[i][j];
		}
	}
	a=b;
	n--;
	return;
}

void matrix::delm (int m1) { 
	int** b=new int* [n];
	for (int i=0; i<n; i++) b[i]=new int [m-1];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (j<=m1) b[i][j]=a[i][j];
			else b[i][j-1]=a[i][j];
		}
	}
	a=b;
	m--;
	return;
}

void matrix::addn (int n1) {
	int** b=new int* [n+1];
	for (int i=0; i<n+1; i++) b [i]=new int [m];
	for (int i=0; i<n+1; i++) {
		for (int j=0; j<m; j++) {
			if (i<n1) b[i][j]=a[i][j];
			else {
				if (i==n1) b[i][j]=0;
				else b[i][j]=a[i-1][j];
			}
		}
	}
	a=b;
	n++;
	return;
}

void matrix::addm (int m1) {
	int** b=new int* [n];
	for (int i=0; i<n; i++) b [i]=new int [m+1];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m+1; j++) {
			if (j<m1) b[i][j]=a[i][j];
			else {
				if (j==m1) b[i][j]=0;
				else b[i][j]=a[i][j-1];
			}
		}
	}
	a=b;
	m++;
	return;
}