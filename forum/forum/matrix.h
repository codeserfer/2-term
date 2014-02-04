#pragma once
class matrix {
private:
	int** a;
	int n;
	int m;
public:
	matrix(void);
	~matrix(void);
	void add ();
	void print ();
	void newsize (int, int);
	void make (int, int);
	void deln (int);
	void delm (int);
	void addn (int);
	void addm (int);
};

