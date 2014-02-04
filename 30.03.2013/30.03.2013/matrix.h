#pragma once
class matrix {
private:
	int** a; //указатель на матрицу
	int n; //высота матрицы
	int m; //ширина матрицы
public:
	matrix(void); //конструктор
	~matrix(void); //деструктор
	void add (); //добавление элементов
	void print (); //вывод матрицы
	void newsize (int, int); //изменение размеров матрицы
	void make (int, int); //выделение памяти под матрицу
	void deln (int); //удаление строки
	void delm (int); //удаление столбца
	void addn (int); //добавление строки
	void addm (int); //добавление столбца
	matrix operator* (const int);
	matrix& operator= (const matrix&);
	
};
