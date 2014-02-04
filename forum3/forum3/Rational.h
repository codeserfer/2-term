#pragma once
class Rational {
private:
	int m; //числитель
	int n; //знаменатель
	void save (int, int); //сохраняет числитель и знаменатель в несократимом виде
	int del (int, int); //поиск общего делителя
public:
	Rational(void);
	Rational (int, int);
	~Rational(void);
	Rational mult (Rational, Rational); //Умножение двух рациональных чисел. 
	Rational mult (Rational, int); //Умножение рационального и целого 
	Rational divis (Rational, Rational); //Деление двух рациональных чисел.
	Rational sum (Rational, Rational); //Сложение двух рациональных чисел.
	Rational sum (Rational, int);
	Rational diff (Rational, Rational); //Вычитание двух рациональных чисел.
	void print1 (); //Печать рациональных чисел в виде а/b
	void print2 (); //Печать рациональных чисел в формате с плавающей точкой. 
	int compare (Rational, Rational);
	int z (Rational);
};

