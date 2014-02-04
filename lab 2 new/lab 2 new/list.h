#pragma once
class list {
private:
	struct catalog { //каталог товаров
		char* code; //код товара
		char* name; //наименование товара
		char* num; //номенклатурный номер
		char* raz; //размеры
		int m; //масса
		catalog* next;
		catalog* prv;
	};
	catalog* first_catalog;
	catalog* last_catalog;

	struct buy {
		int n; //номер п/п
		char* code; //код товара
		char* date; //дата покупки
		int col; //количество товара
		char* price; //цена за еденицу
		buy* next;
		buy* prv;
	};
	buy* first_buy;
	buy* last_buy;

	struct sale {
		int n; //номер п/п
		char* code; //код товара
		char* date; //дата продажи
		int col; //количество товара
		char* price; //цена за единицу
		sale* next;
		sale* prv;
	};
	sale* first_sale;
	sale* last_sale;

	struct report1 {
		int col; //количество товара в наличии
		char* s; //выводимая строка отчета
		report1* next;
		report1* prv;
	};
	report1* first_report1;
	report1* last_report1;

	struct report2 {
		char* s;
		char* date;
		report2* next;
		report2* prv;
	};
	report2* first_report2;
	report2* last_report2;

	int stringtonumber (char*);
	char* cut (char*, int, int);
	bool date (char*, char*); //сравнивает две даты true - первая больша второй, false - вторая больше первой
	bool money (char*, char*); //сравнение денег в одинаковой или разной валюте
	void devision (char*, int);
	catalog* add (catalog*, catalog* &, catalog* &); //добавление по коду
	int toRUR (char*); //перевод евро в рубли и сравы возвращает Int
	void addToReport1 (char*, int);
	void addToReport2 (char*, char*);
	char* inttostr (int);
	void strinsert (char* &, char*, int);
	bool swap (catalog*, catalog*);
	bool swap (buy*, buy*);
	bool swap (sale*, sale*);
	bool swap (report1*, report1*);
	bool swap (report2*, report2*);
	void get_report ();
	void make_report (catalog*);
	void make_report (buy*, sale*);
	char* f_catalog; //имя файла каталога товаров
	char* f_buy; //имя файла каталога покупки
	char* f_sale; //имя файла каталога продажи
public:
	list();
	~list(void);
	void showreport ();
	bool print (int);
	void sortcatalog (int, bool);
	void sortbuy (int, bool);
	void sortsale (int, bool);
	bool loadfile (char*, int);
	bool delete_one (char*);
	bool delete_one (int, int);
	bool edit (char*, char*, char*, char*, int);
	bool edit (int, char*, char*, int, char*, int);
	void add (int, char*, char*, int, char*, int);
	void add (char*, char*, char*, char*, int);
	void showreport (char*);
	bool unique (char*);
	bool unique (int, int);
	bool load (char*, char*, char*);
	void remake ();
};