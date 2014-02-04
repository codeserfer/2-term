#pragma once
class MyString {
public:
	MyString(void);
	~MyString(void);
	void printNums (char*);
private:
	char* s;
	bool p (char *); //проверяет, является ли число возрастающим
	char* cat (char*, int, int); //вырезка из строки, начальная и конечная позиции
	int stringtonumber (char*);
};

