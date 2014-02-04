#pragma once
class Rational {
private:
	int m; //���������
	int n; //�����������
	void save (int, int); //��������� ��������� � ����������� � ������������ ����
	int del (int, int); //����� ������ ��������
public:
	Rational(void);
	Rational (int, int);
	~Rational(void);
	Rational mult (Rational, Rational); //��������� ���� ������������ �����. 
	Rational mult (Rational, int); //��������� ������������� � ������ 
	Rational divis (Rational, Rational); //������� ���� ������������ �����.
	Rational sum (Rational, Rational); //�������� ���� ������������ �����.
	Rational sum (Rational, int);
	Rational diff (Rational, Rational); //��������� ���� ������������ �����.
	void print1 (); //������ ������������ ����� � ���� �/b
	void print2 (); //������ ������������ ����� � ������� � ��������� ������. 
	int compare (Rational, Rational);
	int z (Rational);
};

