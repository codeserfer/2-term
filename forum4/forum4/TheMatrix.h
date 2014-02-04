#pragma once
class TheMatrix {
	int** array;
	int N, M;
public:
	TheMatrix(void);
	TheMatrix(int N, int M);
	~TheMatrix(void);
	void show();
	void fillMatrix();
	void getMemory(int, int);
	TheMatrix& operator*(const int num);
	friend TheMatrix& operator*(const TheMatrix& A, const TheMatrix& B);
	friend TheMatrix& operator+(const TheMatrix& A, const TheMatrix& B);
	TheMatrix& operator=(const TheMatrix&);
};