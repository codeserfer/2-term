#include "stdafx.h"
#include "string.h"
#include <iostream>

//конструктор без параметров
string::string(void) {
	s=new char [1]; //выделяем память под нулевой символ
	s[0]='\0'; //сохраняем нулевой символ
	npos=0;
}
//конструктор без параметров

//деструктор
string::~string(void) {
	if (s) delete [] s; //очищение памяти
}
//деструктор

 //возвращает длину переданной строки
int string::len (char* s) {
	int i=0;
	while (s[i++]!='\0'); //циклом идем по строке, пока не встретим нулевой символ
	return --i; //так как i содержит позицию нуля, надо вернуть предыдущую позицию
}
//возвращает длину переданной строки

//возвращает длину строки, сохраненной в свойствах класса
int string::len () {
	return len(s);
}
//возвращает длину строки, сохраненной в свойствах класса

//копирование строки
char* string::copy (char* s) {
	if (!s) return NULL;
	char* s1=new char [len(s)+1];
	int i=0;
	for (;i<len(s); i++) s1[i]=s[i];
	s1[i]='\0';
	return s1;
}
//копирование строки

//конструктор, принимающий на вход строку типа char*
string::string (char* w) {
	s=copy(w); //сохраняем переданную строку в свойство класса
	npos=0;
	return;
}
//конструктор, принимающий на вход строку типа char*

//переводит int в char*
char* string::inttostr (int a) {
	char* buf=new char [1024];
	int n=0;
	while (a>9) {
		buf[n++]=(char)(a%10+48);
		a/=10;
	}
	buf[n++]=(char)(a+48); 
	char* s=new char [n+1];
	for (int i=n-1; i>=0; i--) s[n-i-1]=buf[i];
	s [n]='\0';
	return s;
}
//переводит int в char*

//переводит double в char*
char* string::inttostr (double a) {
	char* buf=new char [1024];
	sprintf_s (buf, len(buf)+1, "%f", a);
	int lenbuf=len(buf)+1;
	char* s=copy (buf);
	return s;
}
//переводит double в char*

//конструктор, принимающий на вход строку типа int
string::string (int w) {
	s=copy(inttostr(w)); //переводим переданное число в строку и сохраняем ее в свойство класса
	npos=0;
	return;
}
//конструктор, принимающий на вход строку типа int

//конструктор, принимающий на вход строку типа double
string::string (double w) {
	s=copy(inttostr(w)); //переводим переданное число в строку и сохраняем ее в свойство класса
	npos=0;
	return;
}
//конструктор, принимающий на вход строку типа double

//конструктор копирования
string::string (string& q) {
	s=copy (q.s); //сохраняем строку из переданного экземпляра класса в текущий класс
	npos=0;
	return; 
}
//конструктор копирования

//перегруженный оператор = для char*
string& string::operator= (char* b) {
	s=copy(b); //сохраняем переданную строку
	npos=0;
	return *this;
}
//перегруженный оператор = для char*

//перегруженный оператор = для string
string& string::operator= (string& b) {
	s=copy (b.s); //сохраняем строку из переданного класса
	npos=0;
	return *this;
}
//перегруженный оператор = для string

//перегруженный оператор = для int
string& string::operator= (int b) {
	s=copy (inttostr(b)); //переводим число в строку и сохраняем ее
	npos=0;
	return *this;
}
//перегруженный оператор = для int

//перегруженный оператор = для double
string& string::operator= (double b) {
	s=copy (inttostr(b)); //переводим число в строку и сохраняем ее
	npos=0;
	return *this;
}
//перегруженный оператор = для double

//конкатенация двух строк char*
char* string::concat (char* s1, char* s2) {
	if (!s1 && s2) return s2;
	if (s1 && !s2) return s1;
	if (!s1 && !s2) return NULL;
	char* snew=new char [len(s1)+len(s2)+1];
	int i=0;
	while (s1[i]!='\0') snew[i]=s1[i++];
	int j=0;
	while (s2[j]!='\0') snew[i++]=s2[j++];
	snew[i]='\0';
	return snew;
}
//конкатенация двух строк char*

//перегруженный оператор += для char*
string& string::operator+= (char* b) {
	if (!s) { s=copy (b); return *this; } //если строка в классе пуста, то просто сохраняем переданную строку
	this->s=concat (this->s, b); //если строка в классе не пуста, то конкатенируем их
	return *this;
}
//перегруженный оператор += для char*

//перегруженный оператор += для int
string& string::operator+= (int b) {
	if (!s) { s=inttostr(b); return *this; } //если строка в класса пуста, то просто переводим переданное число в строку и сохраняем ее
	this->s=concat (this->s, inttostr(b)); //если строка в классе не пуста, то конкатенируем ее и результат перевода переданного число в строку
	return *this;
}
//перегруженный оператор += для int

//перегруженный оператор += для double
string& string::operator+= (double b) {
	if (!s) { s=inttostr(b); return *this; } //если строка в класса пуста, то просто переводим переданное число в строку и сохраняем ее
	this->s=concat (this->s, inttostr(b)); //если строка в классе не пуста, то конкатенируем ее и результат перевода переданного число в строку
	return *this;
}
//перегруженный оператор += для double

//перегруженный оператор += для string
string& string::operator+= (string& b) {
	if (!this->s) { s=b.s; return *this; } //если строка в классе пуста, то присваиваем ей строку из переданного класса
	this->s=concat (this->s, b.s); //если строка в классе не пуста, то конкатенируем ее и строку из переданного класса
	return *this;
}
//перегруженный оператор += для string

//перегруженный оператор []
char& string::operator[] (const int index) {
	if (index>=len(s) || index<0) throw (1); //если переданный номер больше, чем символов в строке, то кидаем exception
	return s[index]; //возвращаем тредуемый символ
}
//перегруженный оператор []

//перегруженный оператор сравнения >
bool operator> (string &q1, string &q2) {
	int minlen=0;
	//ищем длину меньшей строки:
	if (q1.len()<q2.len()) minlen=q1.len();
	else minlen=q2.len ();
	//сравниваем:
	for (int i=0; i<minlen; i++) {
		if (q1.s[i]>q2.s[i]) return true;
		if (q1.s[i]<q2.s[i]) return false;
	}
	return true;
}
//перегруженный оператор сравнения >

//перегруженный оператор сравнения <
bool operator< (string &q1, string &q2) {
	int minlen=0;
	//ищем длину меньшей строки:
	if (q1.len()<q2.len()) minlen=q1.len();
	else minlen=q2.len ();
	//сравниваем:
	for (int i=0; i<minlen; i++) {
		if (q1.s[i]<q2.s[i]) return true;
		if (q1.s[i]>q2.s[i]) return false;
	}
	return true;
}
//перегруженный оператор сравнения <

//сравнение строк
bool string::cmp (char* s1, char* s2) {
	if (len(s1)!=len(s2)) return false;
	for (int i=0; i<len(s1)+1; i++) if (s1[i]!=s2[i]) return false;
	return true;
}
//сравнение строк

//перегруженный оператор сравнения ==
bool operator== (string &q1, string &q2) {
	if (q1.cmp(q1.s, q2.s)) return true;
	else return false;
	return true;
}
//перегруженный оператор сравнения ==

//перегруженный оператор вывода <<
std::ostream& operator<<(std::ostream& out, string& p) {
	out <<p.s;
	return out;
}
//перегруженный оператор вывода <<

//перегруженный оператор вывода <<
std::ostream& operator<<(std::ostream& out, string *p) {
	out <<p->s;
	return out;
}
//перегруженный оператор вывода <<

//перегруженный оператор + (конкатенация двух строк из двух экземпляров классов)
string& operator+ (string&q1, string& q2) {
	string* buf=new string (q1.concat (q1.s, q2.s)); //создаем строку суммарной длины и копируем туда результат конкатенации
	return *buf; //возвращаем ссылку на экземпляр класса
}
//перегруженный оператор + (конкатенация двух строк из двух экземпляров классов)

//считает количество пробельных символов в начале и конце строки, используется в функции trim ()
int string::probel (char* s) {
	int c=0;
	for (int i=0; i<len(s)+1; i++) {
		char q=s[i];
		if (q==' ' || q=='\n' || q=='\t') c++;
		else break;
	}
	for (int i=len(s)-1; i>=0; i--) {
		char q=s[i];
		if (q==' ' || q=='\n' || q=='\t') c++;
		else break;
	}
	return c;
}
//считает количество пробельных символов в начале и конце строки, используется в функции trim ()

//отсечение пробельных символов 
void string::trim () {
	int p=probel (s);
	char* q=new char [len(s)-p+1];
	bool f1=false;
	int j=0;
	for (int i=0; i<len(q)+1; i++) {
		char w=s[i];
		if ((w==' ' || w=='\n' || w=='\t')&&!f1) continue;
		f1=true;
		q[j]=s[i];
		if (j==len(s)-p-1) break;
		j++;
	}
	q[++j]='\0';
	delete [] s;
	s=q;
	return;
}
//отсечение пробельных символов 

//дружественная функция: отсечение пробельных символов (перенос строки, пробел, табуляция) с обеих сторон.
string& Ttrim (string& q) {
	q.trim (); //вызываем функцию trim () для строки, сохраненную как свойство класса
	return q;
}
//дружественная функция: отсечение пробельных символов (перенос строки, пробел, табуляция) с обеих сторон.

//дружественная функция: обмена содержимого двух строк
void Tswap (string& q1, string& q2) {
	string  b=b.copy(q1.s);
	q1.s=q2.s;
	q2.s=b.copy(b.s);
}
//дружественная функция: обмена содержимого двух строк

//переводит char* в int
int string::stringtonumber (char* s) {
	int num=0;
	int start=0;
	int end=len(s)-1;
	if (s[0]=='-') { start=1; end-=1; }
	for (int i=start, j=end; i<len (s); i++, j--) {
		num+=((int)s[i]-48)*pow(10, j);
	}
	if (start==0) return num;
	else return (-1*num);
}
//переводит char* в int

//аналог strcut
char* string::cut (char* q, int start, int l) {
	char* b=new char [l+1];
	int j=0;
	for (int i=start; i<start+l; i++,j++) b[j]=q[i];
	b[j]='\0';
	return b;
}
//аналог strcut

//Поиск первого вхождения подстроки
int string::pos (string what) {
	npos=0;
	for (int i=0; i<=len(s); i++) {
		for(int j=0; j<what.len(); j++) {
			if (what.s[j]!=s[i+j]) break;
			if (j==what.len()-1) {
				npos=i+1;
				this->what=copy (what.s); //сохраняем
				return i;
			}
		}
	}
	throw 2;
	return 0;
}
//Поиск первого вхождения подстроки

//находит позицию вхождения подстроки в строку
int string::find (char* what) {
	for (int i=0; i<=len(s); i++) {
		for(int j=0; j<len(what); j++) {
			if (what[j]!=s[i+j]) break;
			if (j==len(what)-1) {
				return i;
			}
		}
	}
	return -1;
}
//находит позицию вхождения подстроки в строку

//удаление подстроки
void string::del (int begin, int length) {
	char* q=new char [len(s)-length+2];
	int j=0;
	for (int i=0; i<len(s); i++) if (i<begin || i>begin+length-1) q[j++]=s[i];
	q[j]='\0';
	delete [] s;
	s=q;
}
//удаление подстроки

//удаление всех вхождений подстроки
void string::delall (string& q) {
	int s=find (q.s);
	while (s!=-1) { //пока подстроки еще находятся, удаляем
		del (s, len (q.s));
		s=find (q.s);
	}
}
//удаление всех вхождений подстроки

//нахождение следующего вхождения
int string::nextpos() {
	for (int i=npos; i<len(s); i++) {
		for(int j=0; j<len(what); j++) {
			if (what[j]!=s[i+j]) break;
			if (j==len(what)-1) {
				npos=i+1;
				return i;
			}
		}
	}
	throw 2;
}
//нахождение следующего вхождения

//удаление подстроки
void string::del (string& w) {
	int begin=pos (w);
	int length=len (w.s);
	del (begin, length);
	return;
}
//удаление подстроки

//перевод символа в нижний регистр
char string::tolower (char c) {
	if ((int)c>=(int)'A' && (int)c<=(int)'Z') return (char)((int)c+32);
	if ((int)c>=(int)'А' && (int)c<=(int)'Я') return (char)((int)c+32);
	if ((int)c==(int)'Ё') return 'ё';
	return c;
}
//перевод символа в нижний регистр

//приведение всех буквенных символов (и латинских и кириллицы) к нижнему регистру
void string::lower () {
	for (int i=0; i<len(s)+1; i++) {
		s[i]=tolower(s[i]);
	}
}
//приведение всех буквенных символов (и латинских и кириллицы) к нижнему регистру

//перевод символа в верхний регистр
char string::toupper (char c) {
	if ((int)c>=(int)'a' && (int)c<=(int)'z') return (char)((int)c-32);
	if ((int)c>=(int)'а' && (int)c<=(int)'я') return (char)((int)c-32);
	if ((int)c==(int)'ё') return 'Ё';
	return c;
}
//перевод символа в верхний регистр

//приведение всех буквенных символов (и латинских и кириллицы) к верхнему регистру
void string::upper () {
	for (int i=0; i<len(s)+1; i++) {
		s[i]=toupper(s[i]);
	}
}
//приведение всех буквенных символов (и латинских и кириллицы) к верхнему регистру:

//проверяет, состоит ли строка только из цифр и знака "минус"
bool string::onlyint (char* s) {
	for (int i=0; i<len(s); i++) if (((int)s[i]<(int)'0' || (int)s[i]>(int)'9') && s[0]!='-') return false;
	return true;
}
//проверяет, состоит ли строка только из цифр и знака "минус"

//проверяет, состоит ли строка только из цифр, знака "минус" и запятой
bool string::onlydouble (char* s) {
	for (int i=0; i<len(s); i++) if (((int)s[i]<(int)'0' || (int)s[i]>(int)'9') && s[0]!='-' && s[i]!=',') return false;
	return true;
}
//проверяет, состоит ли строка только из цифр, знака "минус" и запятой

//преобразование в int
int string::to_int () {
	if (!onlyint (s)) throw (3);
	if (len(s)>10) throw (4);
	if (len(s)==10 && s[0]!='-') throw (4);
	return stringtonumber (s);
}
//преобразование в int

//переводит char* в double
double string::to_double () {
	if (!onlydouble (s)) throw (3);
	if (len(s)>10) throw (4);
	if (len(s)==10 && s[0]!='-') throw (4);
	int z=this->find (",");
	int w1=stringtonumber (cut(s, 0, z));
	int w2=stringtonumber (cut (s, z+1, len(s)-z-1));
	int col=len(inttostr(w2));
	return w1+w2*pow (10, -1*col);
}
//переводит char* в double

//инвертирование строки
void string::reverse() {
	for (int i=0, j=len(s)-1; i<((len(s)+1)/2); i++, j--) {
		char q=s[i];
		s[i]=s[j];
		s[j]=q;
	}
	return;
}
//инвертирование строки

//вставка подстроки на указанную позицию
void string::ins (string& what, int where) {
	char* q=new char [len(s)+len(what.s)+1];
	int i=0; //счетчик общей строки
	int j=0; //счетчик исходной строки1
	int k=0; //счестчик вставляемой строки
	for (;i<len(s)+len(what.s); i++) {
		if (i<where) { q[i]=s[j++]; continue;}
		if (i>=where+len(what.s)) { q[i]=s[j++]; continue;}
		q[i]=what.s[k++];
	}
	q[i]='\0';
	delete [] s;
	s=q;
}
//вставка подстроки на указанную позицию

//замена первого вхождения подстроки what на replace_with
void string::replace (string& what, string& with) {
	int newlen=len(s)-len(what.s)+len(with.s)+1;
	char* q=new char [newlen];
	int where=find (what.s);
	int i=0;
	int j=0;
	int k=where+len(with.s)-(len(with.s)-len(what.s));
	for (;i<newlen-1; i++) {
		if (i<where) { q[i]=s[i]; continue; }
		if (i>=where && i<where+len(with.s)) { q[i]=with.s[j++]; continue; }
		q[i]=s[k++];
	}
	q[i]='\0';
	delete [] s;
	s=q;
}
//замена первого вхождения подстроки what на replace_with

//Замена всех вхождений подстроки what на replace_with
void string::replaceall (string& what, string& replace_with) {
	int where=find (what.s);
	while (where!=-1) { //пока есть что заменять, заменяем:
		this->replace (what, replace_with);
		where=find (what.s);
	}
}
//Замена всех вхождений подстроки what на replace_with

//дружественная функция: длина строки в символах
int Tlen (string& q) {
	return q.len();
}
//дружественная функция: длина строки в символах