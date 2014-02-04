#include "StdAfx.h"
#include "TheMatrix.h"
#include "iostream"
using namespace std;

TheMatrix::TheMatrix(void) {
	array = NULL;
	N = M = 0;
}

TheMatrix::TheMatrix(int N, int M) {
	getMemory(N, M);
	fillMatrix();
}

TheMatrix::~TheMatrix(void){
	if (array) {
		for (int i = 0; i < M; i++)  {
			delete [] array[i];
		}
		delete [] array;
		array = NULL;
	}
}

void TheMatrix::getMemory(int N, int M){
	this->N = N; this->M = M;
	this->array = new int*[N];
	for (int i = 0; i < N; i++) {
		this->array[i] = new int[M];
	}
}

void TheMatrix::fillMatrix() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "array[" << i << "][" << j << "] = ";
			cin >> array[i][j];
			cout << endl;
		}
	}
	return;
}

void TheMatrix::show() {
	if (N == 0 || M == 0)  {
		cout << "Матрица пуста\n\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

TheMatrix& TheMatrix::operator=(const TheMatrix& source) {
	if (&source == this) {
		return *this;
	}
	getMemory(source.N, source.M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			this->array[i][j] = source.array[i][j];
		}
	}
	return *this;
}

/* 1. Умножить матрицу на число (operator*). */
TheMatrix& TheMatrix::operator*(int num) {
	//TheMatrix* result = new TheMatrix(this->N; this->M);
	TheMatrix* result = new TheMatrix;
	if (!array) return *result;
	result->getMemory(this->N, this->M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result->array[i][j] = this->array[i][j]*num;
		}
	}
	return *result; 
}

/* 2. Умножить матрицу на матрицу (operator*). Если матрицы умножить нельзя, то вернуть исключение. */
TheMatrix& operator*(const TheMatrix& A, const TheMatrix& B) {
	if (A.M != B.N) throw 1;
	int sum;
	TheMatrix* result = new TheMatrix;
	result->getMemory(A.N, B.M); 
	for (int i = 0; i < A.N; i++) { 
		for(int j = 0; j < B.M; j++) {
			sum = 0;
			for(int count = 0; count < A.M; count++) {
				sum += A.array[i][count] * B.array[count][j];
			}
			result->array[i][j] = sum;
		}
	}
	return *result;
}

/* 3. Сложить две матрицы (operator+). Если матрицы сложить нельзя, то вернуть исключение. */
TheMatrix& operator+(const TheMatrix& A, const TheMatrix& B) {
	if (A.N != B.N || A.M != B.M) throw 2;
	TheMatrix* result = new TheMatrix;
	result->getMemory(A.N, B.M); 
	for (int i = 0; i < A.N; i++) {
		for(int j = 0; j < B.M; j++) {
			result->array[i][j] = A.array[i][j] + B.array[i][j];
		}
	}
	return *result;
}