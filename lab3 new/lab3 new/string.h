#pragma once
#include <iostream>
class string {
public:
	int len (); //���������� ����� ����������� ������
	string& operator= (char*); //������������� �������� = ��� char*
	string& operator= (string&); //������������� �������� = ��� string
	string& operator= (int); //������������� �������� = ��� int
	string& operator= (double); //������������� �������� = ��� double
	string& operator+= (char*); //������������� �������� += ��� char*
	string& operator+= (int); //������������� �������� += ��� int
	string& operator+= (double); //������������� �������� += ��� double
	string& operator+= (string&); //������������� �������� += ��� string
	friend bool operator> (string &q1, string &q2); //������������� �������� ��������� >
	friend bool operator< (string &q1, string &q2); //������������� �������� ��������� <
	friend bool operator== (string &q1, string &q2); //������������� �������� ��������� ==
	char& operator[] (const int); //������������� �������� []
	friend std::ostream& operator<<(std::ostream& out, string& p); //������������� �������� ������ <<
	friend std::ostream& operator<<(std::ostream& out, string *p); //������������� �������� ������ <<
	friend string& operator+ (string&q1, string& q2); //������������ ���� �����
	string (void); //����������� ��� ����������
	string (char*); //�����������, ����������� �� ���� ������ ���� char*
	string (int); //�����������, ����������� �� ���� ������ ���� int
	string (double); //�����������, ����������� �� ���� ������ ���� double
	string (string&); //����������� �����������
	~string (void); //����������
	int pos (string); //����� ������� ��������� ���������
	int nextpos(); //���������� ���������� ���������
	void del (int, int); //�������� ���������
	void del (string&); //�������� ���������
	void delall (string&); //�������� ���� ��������� ���������
	void ins (string&, int); //������� ��������� �� ��������� �������
	void replace (string&, string&); //������ ������� ��������� ��������� what �� replace_with
	void replaceall (string&, string&); //������ ���� ��������� ��������� what �� replace_with
	void trim (); //��������� ���������� �������� 
	void lower (); //���������� ���� ��������� �������� (� ��������� � ���������) � ������� ��������
	void upper (); //���������� ���� ��������� �������� (� ��������� � ���������) � �������� ��������
	int to_int (); //�������������� � int
	double to_double (); //�������������� � double
	void reverse (); //�������������� ������
	friend int Tlen (string&); //������������� �������: ����� ������ � ��������
	friend void Tswap (string& q1, string& q2); //������������� �������: ������ ����������� ���� �����
	friend string& Ttrim (string& q); //������������� �������: ��������� ���������� �������� (������� ������, ������, ���������) � ����� ������.
private:
	char* s; //��������� �� ������ char, � ������� �������� ������
	int probel (char*); //������� ���������� ���������� �������� � ������ � ����� ������, ������������ � ������� trim ()
	int npos; //����������, � ������� ����������� ������ ��������� ��������� � ������
	char* what; //������������ ���������
	char* inttostr (int); //��������� int � char*
	char* inttostr (double); //��������� double � char*
	int stringtonumber (char*); //��������� char* � int
	bool cmp (char*, char*); //��������� �����
	char* copy (char*); //����������� ������
	char tolower (char); //������� ������� � ������ �������
	char toupper (char); //������� ������� � ������� �������
	bool onlyint (char*); //���������, ������� �� ������ ������ �� ���� � ����� "�����"
	bool onlydouble (char*); //���������, ������� �� ������ ������ �� ����, ����� "�����" � �������
	int find (char*); //������� ������� ��������� ��������� � ������
	char* cut (char*, int, int); //������ strcut
	char* concat (char*, char*); //������������ ���� ����� char*
	int len (char*); //���������� ����� ���������� ������
};