#include "stdafx.h"
#include "Rational.h"
#include <iostream>

Rational::Rational(void) {
	n=0;
	m=0;
}

Rational::Rational (int m=0, int n=1) {
	if (n==0) throw (0);
	save (m, n);
}

int Rational::del (int a, int b) {
	int min=0;
	if (a<b) min=a;
	else min=b;
	for (int i=2; i<=min; i++) if (a%i==0 && b%i==0) return i;
	return 0;
}

void Rational::save (int m, int n) {
	bool minus=false; //минуса нет
	minus=(m<0)!=(n<0);
	m=abs(m);
	n=abs(n);
	while (del(m, n)) {
		int c_del=del (m, n);
		m/=c_del;
		n/=c_del;
	}
	if (minus) this->m=-1*m; else this->m=m;
	this->n=n;
}
Rational::~Rational(void) {

}

Rational Rational::mult (Rational a, Rational b) {
	this->save (a.m*b.m, a.n*b.n);
	return *this;
}

Rational Rational::mult (Rational a, int b) {
	this->save (a.m*b, a.n);
	return *this;
}

Rational Rational::divis (Rational a, Rational b) {
	this->save (a.m*b.n, a.n*b.m);
	return *this;
}

Rational Rational::sum (Rational a, Rational b) {
	this->save (b.n*a.m+a.n*b.m, a.n*b.n);
	return *this;
}

Rational Rational::sum (Rational a, int b) {
	this->save (a.m+b+a.n, a.n);
	return *this;
}

Rational Rational::diff (Rational a, Rational b) {
	if (a.m==0 || b.m==0) { this->save (0, 1); return *this; }
	this->save (b.n*a.m-a.n*b.m, a.n*b.n);
	return *this;
}

void Rational::print1 () {
	std::cout << m<<"/"<<n;
}

void Rational::print2 () {
	std::cout << (double)m/n;
}

int Rational::z (Rational a) {
	if (a.m>0) return 1;
	if (a.m==0) return 0;
	if (a.m<0) return -1;
}

int Rational::compare (Rational a, Rational b) {
	Rational c (0, 1);
	c=c.diff (a, b);
	if (c.z(c)>0) return 1;
	if (c.z(c)==0) return 0;
	if (c.z(c)<0) return -1;
}