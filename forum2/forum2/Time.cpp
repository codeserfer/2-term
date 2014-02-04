#include "stdafx.h"
#include "Time.h"
#include <iostream>

Time::Time(void)
{
	m=0;
	h=0;
	s=0;
}
Time::Time (int h=0, int m=0, int s=0) {
	this->h=h;
	this->m=m;
	this->s=s;
}

Time::~Time(void)
{
	std::cout << h << m << s;
}
