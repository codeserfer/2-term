#pragma once
#include <iostream>
class string {
public:
	int len (); //возвращает длину сохраненной строки
	string& operator= (char*); //перегруженный оператор = для char*
	string& operator= (string&); //перегруженный оператор = для string
	string& operator= (int); //перегруженный оператор = для int
	string& operator= (double); //перегруженный оператор = для double
	string& operator+= (char*); //перегруженный оператор += для char*
	string& operator+= (int); //перегруженный оператор += для int
	string& operator+= (double); //перегруженный оператор += для double
	string& operator+= (string&); //перегруженный оператор += для string
	friend bool operator> (string &q1, string &q2); //перегруженный оператор сравнения >
	friend bool operator< (string &q1, string &q2); //перегруженный оператор сравнения <
	friend bool operator== (string &q1, string &q2); //перегруженный оператор сравнения ==
	char& operator[] (const int); //перегруженный оператор []
	friend std::ostream& operator<<(std::ostream& out, string& p); //перегруженный оператор вывода <<
	friend std::ostream& operator<<(std::ostream& out, string *p); //перегруженный оператор вывода <<
	friend string& operator+ (string&q1, string& q2); //конкатенация двух строк
	string (void); //конструктор без параметров
	string (char*); //конструктор, принимающий на вход строку типа char*
	string (int); //конструктор, принимающий на вход строку типа int
	string (double); //конструктор, принимающий на вход строку типа double
	string (string&); //конструктор копирования
	~string (void); //деструктор
	int pos (string); //Поиск первого вхождения подстроки
	int nextpos(); //нахождение следующего вхождения
	void del (int, int); //удаление подстроки
	void del (string&); //удаление подстроки
	void delall (string&); //удаление всех вхождений подстроки
	void ins (string&, int); //вставка подстроки на указанную позицию
	void replace (string&, string&); //замена первого вхождения подстроки what на replace_with
	void replaceall (string&, string&); //Замена всех вхождений подстроки what на replace_with
	void trim (); //отсечение пробельных символов 
	void lower (); //приведение всех буквенных символов (и латинских и кириллицы) к нижнему регистру
	void upper (); //приведение всех буквенных символов (и латинских и кириллицы) к верхнему регистру
	int to_int (); //преобразование в int
	double to_double (); //преобразование в double
	void reverse (); //инвертирование строки
	friend int Tlen (string&); //дружественная функция: длина строки в символах
	friend void Tswap (string& q1, string& q2); //дружественная функция: обмена содержимого двух строк
	friend string& Ttrim (string& q); //дружественная функция: отсечение пробельных символов (перенос строки, пробел, табуляция) с обеих сторон.
private:
	char* s; //указатель на массив char, в котором хранится строка
	int probel (char*); //считает количество пробельных символов в начале и конце строки, используется в функции trim ()
	int npos; //переменная, к которую сохраняется первое вхождение подстроки в строку
	char* what; //сохраненнаяя подстрока
	char* inttostr (int); //переводит int в char*
	char* inttostr (double); //переводит double в char*
	int stringtonumber (char*); //переводит char* в int
	bool cmp (char*, char*); //сравнение строк
	char* copy (char*); //копирование строки
	char tolower (char); //перевод символа в нижний регистр
	char toupper (char); //перевод символа в верхний регистр
	bool onlyint (char*); //проверяет, состоит ли строка только из цифр и знака "минус"
	bool onlydouble (char*); //проверяет, состоит ли строка только из цифр, знака "минус" и запятой
	int find (char*); //находит позицию вхождения подстроки в строку
	char* cut (char*, int, int); //аналог strcut
	char* concat (char*, char*); //конкатенация двух строк char*
	int len (char*); //возвращает длину переданной строки
};