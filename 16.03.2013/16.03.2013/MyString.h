#pragma once
class MyString {
public:
	MyString(void);
	~MyString(void);
	void printNums (char*);
private:
	char* s;
	bool p (char *); //���������, �������� �� ����� ������������
	char* cat (char*, int, int); //������� �� ������, ��������� � �������� �������
	int stringtonumber (char*);
};

