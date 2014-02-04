#include "stdafx.h"
#include "list.h"
#include <iostream>
#include <conio.h>
#include <fstream>

list::list(void) {
	first_catalog=NULL;
	last_catalog=NULL;
	first_buy=NULL;
	last_buy=NULL;
	first_sale=NULL;
	last_sale=NULL;
	first_report1=NULL;
	last_report1=NULL;
	first_report2=NULL;
	last_report2=NULL;
	//std::cout << "Конструктор\n";
}

list::~list(void) {
	//std::cout << "Деструктор\n";
	catalog*cur1=first_catalog;
	while (cur1) {
		delete [] cur1->code;
		delete [] cur1->name;
		delete [] cur1->num;
		delete [] cur1->raz;
		cur1=cur1->next;
	}
	delete cur1;

	buy*cur2=first_buy;
	while (cur2) {
		delete [] cur2->code;
		delete [] cur2->date;
		delete [] cur2->price;
		cur2=cur2->next;
	}
	delete cur2;

	sale*cur3=first_sale;
	while (cur3) {
		delete [] cur3->code;
		delete [] cur3->date;
		delete [] cur3->price;
		cur3=cur3->next;
	}
	delete cur3;

	report1* cur4=first_report1;
	while (cur4) {
		delete [] cur4->s;
		cur4=cur4->next;
	}
	delete cur4;

	report2* cur5=first_report2;
	while (cur5) {
		delete [] cur5->s;
		cur5=cur5->next;
	}
	delete cur5;
}

bool list::loadfile (char* file, int n) {
	if (n==1) {
		std::ifstream fin(file);
		if (!fin) return false;
		char buf [1024];
		while(!fin.eof() && fin>> buf) devision (buf, 1);
		f_catalog=file;
		return true;
	}
	if (n==2) {
		std::ifstream fin(file);
		if (!fin) return false;
		char buf [1024];
		while(!fin.eof() && fin>> buf) devision (buf, 2);
		f_buy=file;
		return true;
	}
	if (n==3) {
		std::ifstream fin(file);
		if (!fin) return false;
		char buf [1024];
		while(!fin.eof() && fin>> buf) devision (buf, 3);
		f_sale=file;
		return true;
	}
	return false;
}

void list::strinsert (char* &s, char* source, int q){ // \0 не добавляет!
	for (int i=q; i<q+strlen (source); i++) s [i]=source [i-q];
	return;
}
char* list::inttostr (int a) {
	char* buf=new char [1024];
	int n=0;
	while (a>9) {
		buf[n++]=(char)(a%10+48);
		a/=10;
	}
	buf[n++]=(char)(a+48); 
	char* s=new char [n+1];
	for (int i=n-1; i>=0; i--) s[n-i-1]=buf[i];
	s [n]='\0';
	return s;
}
int list::stringtonumber (char* s){
	int num=0;
	for (int i=0, j=strlen(s)-1; i<strlen (s); i++, j--) {
		num+=((int)s[i]-48)*pow(10, j);
	}
	return num;
}
char* list::cut (char* s, int q1, int q2) {
	char s1 [1024];
	int w=0;
	for (int i=q1; i<q2+1; i++, w++) {
		s1 [w]=s[i];
	}
	s1[w]='\0';
	char* s2=new char (strlen (s1)+1);
	int i;
	for (i=0; i<strlen (s1); i++) s2[i]=s1[i];
	s2[i]='\0';
	return s2;
}

//сравнивает две даты
bool list::date (char* s1, char* s2) { //сравнивает две даты true - первая больша второй, false - вторая больше первой
	//дата – формат даты ДД.ММ.ГГГГ (например 22.03.2013);
	int year1=stringtonumber(cut(s1, 6, 9));
	int year2=stringtonumber(cut(s2, 6, 9));
	int mounth1=stringtonumber(cut(s1, 3, 4));
	int mounth2=stringtonumber(cut(s2, 3, 4));
	int day1=stringtonumber(cut(s1, 0, 1));
	int day2=stringtonumber(cut(s2, 0, 1));

	int q1=year1*365+mounth1*30+day1;
	int q2=year2*365+mounth2*30+day2;
	if (q1>=q2) return true; else return false;
	/*
	if (year1>year2) return true;
	else {
		if (year1<year2) return false;
		else {
			if (mounth1>mounth2) return true;
			else {
				if (mounth1<mounth2) return false;
				else {
					if (day1>day2) return true;
					//else return false;
					else if (day1>day2) return false;
				}
			}
		}
	}
	//return false;
	*/
}
//сравнивает две даты

void list::devision (char* s, int nn) {
	if (nn==1) {
		int w=0; //счетчик параметров
		int q=0;
		char* s1=new char [strlen (s)+2];
		char* code=NULL; //код товара
		char* name=NULL; //наименование товара
		char* num=NULL; //номенклатурный номер
		char* raz=NULL; //размеры
		int m; //масса
		s1[strlen(s)]=';';
		s1[strlen(s)+1]='\0';
		for (int i=0; i<strlen(s); i++) s1[i]=s[i];
		s=s1;
		for (int i=0; i<strlen (s); i++) {
			if (s[i]==';') { 
				char* temp=new char [i-q+1];
				temp=cut (s, q, i-1);
				if (w==0) code=temp;
				if (w==1) name=temp;
				if (w==2) num=temp;
				if (w==3) raz=temp;
				if (w==4) m=stringtonumber (temp);
				q=i+1; 
				w++;
			}
		}
		add (code, name, num, raz, m);
	return;
	}
	if (nn==2 || nn==3) {
		int w=0; //счетчик параметров
		int q=0;
		char* s1=new char [strlen (s)+2];
		int n=0; //номер п/п
		char* code=NULL; //код товара
		char* date=NULL; //дата покупки
		int col=0; //количество товара
		char* price=NULL; //цена за единицу
		s1[strlen(s)]=';';
		s1[strlen(s)+1]='\0';
		for (int i=0; i<strlen(s); i++) s1[i]=s[i];
		s=s1;
		for (int i=0; i<strlen (s); i++) {
			if (s[i]==';') { 
				char* temp=new char [i-q+1];
				temp=cut (s, q, i-1);
				if (w==0) n=stringtonumber(temp);
				if (w==1) code=temp;
				if (w==2) date=temp;
				if (w==3) col=stringtonumber (temp);
				if (w==4) price=temp;
				q=i+1; 
				w++;
			}
		}
		add (n, code, date, col, price, nn);
	}
}

void list::remake () {
	if (!(first_buy) && (!first_catalog) && (!first_sale)) {
		std::cout << "Каталоги будут удалены, продолжить?(1, 0)\n";
		int q=0;
		std::cin >> q;
		if (!q) return;
	}
	std::ofstream fin1 (f_catalog);
	if (!fin1) { std::cout << "Ошибка чтения файла\n"; return; }
	for (catalog*i=first_catalog; i; i=i->next) if (i->next) fin1<<i->code<< ";"<<i->name<<";"<<i->num<<";"<<i->raz<<";"<<i->m<<"\n"; else fin1<<i->code<< ";"<<i->name<<";"<<i->num<<";"<<i->raz<<";"<<i->m;

	std::ofstream fin2 (f_buy);
	if (!fin2) { std::cout << "Ошибка чтения файла\n"; return; }
	for (buy*i=first_buy; i; i=i->next) if (i->next) fin2<<i->n<<";"<<i->code<<";"<<i->date<<";"<<i->col<<";"<<i->price<<"\n"; else fin2<<i->n<<";"<<i->code<<";"<<i->date<<";"<<i->col<<";"<<i->price;

	std::ofstream fin3 (f_sale);
	if (!fin3) { std::cout << "Ошибка чтения файла\n"; return; }
	for (sale*i=first_sale; i; i=i->next) if (i->next) fin3<<i->n<<";"<<i->code<<";"<<i->date<<";"<<i->col<<";"<<i->price<<"\n"; else fin3<<i->n<<";"<<i->code<<";"<<i->date<<";"<<i->col<<";"<<i->price;
}
//Добавление для каталога товаров
void list::add (char* code, char* name, char* num, char* raz, int m){
	if (!first_catalog){
		first_catalog=new catalog;
		first_catalog->code=new char [strlen (code)+1];
		strcpy_s (first_catalog->code, strlen(code)+1, code);
		first_catalog->name=new char [strlen (name)+1];
		strcpy_s (first_catalog->name, strlen(name)+1, name);
		first_catalog->num=new char [strlen (num)+1];
		strcpy_s (first_catalog->num, strlen(num)+1, num);
		first_catalog->raz=new char [strlen (raz)+1];
		strcpy_s (first_catalog->raz, strlen(raz)+1, raz);
		first_catalog->m=m;
		last_catalog=first_catalog;
		first_catalog->next=NULL;
		first_catalog->prv=NULL;
		return;
	}
	catalog* q=new catalog;
	last_catalog->next=q;
	q->next=NULL;
	q->prv=last_catalog;
	q->code=new char [strlen (code)+1];
	strcpy_s (q->code, strlen(code)+1, code);
	q->name=new char [strlen (name)+1];
	strcpy_s (q->name, strlen(name)+1, name);
	q->num=new char [strlen (num)+1];
	strcpy_s (q->num, strlen(num)+1, num);
	q->raz=new char [strlen (raz)+1];
	strcpy_s (q->raz, strlen(raz)+1, raz);
	q->m=m;
	last_catalog=q;
	
	//std::ofstream fin ("catalog.csv");
	//fin<<m;
	//fin<<m;
	return;
}
//Добавление для каталога товаров

//Редактирование для каталога товаров
bool list::edit (char* code, char* name, char* num, char* raz, int m) {
	//std::cout << "МЫ ТУТ\n";
	catalog* cur=first_catalog;
	if (!cur) return false;
	//std::cout << "Заходим в цикл\n";
	while (cur) {
		if (!strcmp(cur->code, code)) break;
		if (!cur->next) break;
		cur=cur->next;
	}
	//std::cout << "Сравниваем " << cur->code << " и " << code << "\n";
	if (strcmp(cur->code, code)!=0) return false;
	cur->name=name;
	cur->num=num;
	cur->raz=raz;
	cur->m=m;
	return true;
}
//Редактирование для каталога товаров
bool list::edit (int n, char* code, char* date, int col, char* price, int w) {
	if (w==2) {
		buy* cur=first_buy;
		if (!cur) return false;
		while (cur) {
			if (cur->n==n) break;
			if (!cur->next) break;
			cur=cur->next;
		}
		if (cur->n!=n) return false;
		cur->code=code;
		cur->date=date;
		cur->col=col;
		cur->price=price;
		return true;
	}
	if (w==3) {
		sale* cur=first_sale;
		if (!cur) return false;
		while (cur) {
			if (cur->n==n) break;
			if (!cur->next) break;
			cur=cur->next;
		}
		if (cur->n!=n) return false;
		cur->code=code;
		cur->date=date;
		cur->col=col;
		cur->price=price;
		return true;
	}
	return false;
}
//Добавление для покупка товаров и продажа товаров
void list::add (int n, char* code, char* date, int col, char* price, int w){
	if (w==2) {
		if (!first_buy){
			first_buy=new buy;
			first_buy->n=n;
			first_buy->code=new char [strlen (code)+1];
			strcpy_s (first_buy->code, strlen(code)+1, code);
			first_buy->date=new char [strlen (date)+1];
			strcpy_s (first_buy->date, strlen(date)+1, date);
			first_buy->col=col;
			first_buy->price=new char [strlen (price)+1];
			strcpy_s (first_buy->price, strlen(price)+1, price);
			first_buy->next=NULL;
			first_buy->prv=NULL;
			last_buy=first_buy;
			last_buy->next=NULL;
			last_buy->prv=NULL;
			return;
		}
		buy* q=new buy;
		last_buy->next=q;
		q->next=NULL;
		q->prv=last_buy;
		q->n=n;
		q->code=new char [strlen (code)+1];
		strcpy_s (q->code, strlen(code)+1, code);
		q->date=new char [strlen (date)+1];
		strcpy_s (q->date, strlen(date)+1, date);
		q->col=col;
		q->price=new char [strlen (price)+1];
		strcpy_s (q->price, strlen(price)+1, price);
		last_buy=q;
		return;
	}
	if (w==3) {
		if (!first_sale){
			first_sale=new sale;
			first_sale->n=n;
			first_sale->code=new char [strlen (code)+1];
			strcpy_s (first_sale->code, strlen(code)+1, code);
			first_sale->date=new char [strlen (date)+1];
			strcpy_s (first_sale->date, strlen(date)+1, date);
			first_sale->col=col;
			first_sale->price=new char [strlen (price)+1];
			strcpy_s (first_sale->price, strlen(price)+1, price);
			first_sale->next=NULL;
			first_sale->prv=NULL;
			last_sale=first_sale;
			last_sale->next=NULL;
			last_sale->prv=NULL;
			return;
		}
		sale* q=new sale;
		last_sale->next=q;
		q->next=NULL;
		q->prv=last_sale;
		q->n=n;
		q->code=new char [strlen (code)+1];
		strcpy_s (q->code, strlen(code)+1, code);
		q->date=new char [strlen (date)+1];
		strcpy_s (q->date, strlen(date)+1, date);
		q->col=col;
		q->price=new char [strlen (price)+1];
		strcpy_s (q->price, strlen(price)+1, price);
		last_sale=q;
		return;
	}
}
//Добавление для покупка товаров и продажа товаров

//удаление одного элемента
bool list::delete_one (char* code) {
	catalog* cur=first_catalog;
	if (!cur) return false;
	while (cur) {
		if (!strcmp(cur->code, code)) break;
		if (!cur->next) break;
		cur=cur->next;
	}
	if (strcmp(cur->code, code)!=0) return false;
	delete [] cur->code;
	delete [] cur->name;
	delete [] cur->num;
	delete [] cur->raz;
	if (cur->prv) cur->prv->next=cur->next;
	if (cur->next) cur->next->prv=cur->prv;
	if (first_catalog==cur) first_catalog=cur->next;
	if (last_catalog==cur) last_catalog=cur->prv;
	delete cur;
	return true;
}
bool list::delete_one (int n, int nn) {
	if (nn==2) {
		buy* cur=first_buy;
		if (!cur) return false;
		while (cur) {
			if (cur->n==n) break;
			if (!cur->next) break;
			cur=cur->next;
		}
		if (cur->n!=n) return false;
		delete [] cur->code;
		delete [] cur->date;
		delete [] cur->price;
		if (cur->prv) cur->prv->next=cur->next;
		if (cur->next) cur->next->prv=cur->prv;
		if (cur==first_buy) first_buy=cur->next;
		if (cur==last_buy) last_buy=cur->prv;
		delete cur;
		return true;
	}
	if (nn==3) {
		sale* cur=first_sale;
		if (!cur) return false;
		while (cur) {
			if (cur->n==n) break;
			if (!cur->next) break;
			cur=cur->next;
		}
		if (cur->n!=n) return false;
		delete [] cur->code;
		delete [] cur->date;
		delete [] cur->price;
		if (cur->prv) cur->prv->next=cur->next;
		if (cur->next) cur->next->prv=cur->prv;
		if (cur==first_sale) first_sale=cur->next;
		if (cur==last_sale) last_sale=cur->prv;
		delete cur;
		return true;
	}
	return false;
}
//удаление одного элемента

//вывод списков
bool list::print (int n) {
	if (n==1) {
		
		if (!first_catalog) { std::cout << "Список пуст!\n"; return false; }
		std::cout << "Код товара  Наименование товара\tНоменклатурный номер\tГабариты   Масса\n";
		catalog* cur=first_catalog;
		while (cur) {
			//std::cout << cur->code << " " << cur->name << " " << cur->num << " " << cur->raz << " " << cur->m << "\n";
			std::cout << "   " << cur->code << "\t    " << cur->name << "\t\t" << cur->num << "\t\t" << cur->raz << "\t\t" << cur->m << "\n";
			//std::cout << " (cur=" <<cur<<", prv="<<cur->prv<<", next=" <<cur->next<<")"<<std::endl;
			cur=cur->next;
		}
		return true;
	}
	if (n==2) {
		//std::cout << "Выводим покупку товаров:\n";
		if (!first_buy) { std::cout << "Список пуст!\n"; return false; }
		std::cout << "Номер п/п\tКод товара\tДата покупки\tКоличество\tЦена за ед-у\n";
		buy* cur=first_buy;
		while (cur) {
			//std::cout << cur->n << " " << cur->code << " " << cur->date << " " << cur->col << " " << cur->price << " (cur=" <<cur<<", prv="<<cur->prv<<", next=" <<cur->next<<")"<<std::endl;
			std::cout << "   " << cur->n << "  \t\t" << cur->code << "\t\t" << cur->date << "  \t" << cur->col << "\t\t" << cur->price << "\n";
			//std::cout << "(cur=" <<cur<<", prv="<<cur->prv<<", next=" <<cur->next<<")"<<std::endl;
			cur=cur->next;
		}
		return true;
	}
	if (n==3) {
		if (!first_sale) { std::cout << "Список пуст!\n"; return false; }
		std::cout << "Номер п/п\tКод товара\tДата продажи\tКоличество\tЦена за ед-у\n";
		sale* cur=first_sale;
		while (cur) {
			std::cout << "   " << cur->n << "  \t\t" << cur->code << "\t\t" << cur->date << "  \t" << cur->col << "\t\t" << cur->price << "\n";
			//std::cout << cur->n << " " << cur->code << " " << cur->date << " " << cur->col << " " << cur->price << "\n";
			//std::cout << (cur=" <<cur<<", prv="<<cur->prv<<", next=" <<cur->next<<")"<<std::endl;
			cur=cur->next;
		}
		return true;
	}
}
//вывод списков

//получает строку с деньгами, возвращает int с рублями
int list::toRUR (char* s) {
	if (!strcmp (cut(s, strlen (s)-3, strlen (s)), "RUR")) return stringtonumber(cut (s, 0, strlen(s)-4));
	else return  stringtonumber(cut (s, 0, strlen(s)-4))*40;
}
//получает строку с деньгами, возвращает int с рублями

//сравнивает две суммы денег
bool list::money (char* s1, char* s2) { //сравнивает две суммы денег true - первая больша второй, false - вторая больше первой
	int money1=0; //первая сумма денег в рублях
	int money2=0; //вторая сумма денег в рублях
	std::cout <<cut (s1, strlen(s1)-3, strlen(s1));
	std::cout <<cut (s2, strlen(s2)-3, strlen(s2));
	if (!strcmp (cut (s1, strlen(s1)-3, strlen(s1)), "EUR")) money1=toRUR (s1); 
	else money1=stringtonumber(s1);
	if (!strcmp (cut (s2, strlen(s2)-3, strlen(s2)), "EUR")) money2=toRUR (s2);
	else  money2=stringtonumber(s2);
	if (money1>money2) return true;
	else return false;
}
//сравнивает две суммы денег

//добавление нового элемента после заданного
list::catalog* list::add (catalog* q, catalog* &first, catalog* &last) {
	catalog* cur=new catalog;
	//std::cout << "Создался новый элемент с адресом " << cur << "\n";
	cur->next=q->next;
	q->next=cur;
	cur->next->prv=q;
	cur->prv=q;
	return cur;
}
//добавление нового элемента после заданного

void list::addToReport1 (char* s, int col) {
	if (!first_report1) {
		first_report1=new report1;
		first_report1->col=col;
		first_report1->s=s;
		first_report1->next=NULL;
		first_report1->prv=NULL;
		last_report1=first_report1;
		//std::cout << "Самый пеервый элемент" << first_report1->s << "\n";
		return;
	}
	report1* q=first_report1;

	if (col<=q->col) {
		report1* cur=new report1;
		cur->col=col;
		cur->s=s;
		cur->next=first_report1;
		first_report1=cur;
		if (cur->next) cur->next->prv=cur;
		cur->prv=NULL;
		return;
	}
	int min=first_report1->col;
	report1* min_r=first_report1;
	while (q) {
		if (q->col<min) { min=q->col; min_r=q; }//break;
		if (!q->next) break; //оО
		q=q->next;
	}
	q=min_r;
	report1* cur=new report1;
	cur->next=q->next;
	q->next=cur;
	cur->s=s;
	if (cur->next) cur->next->prv=cur;
	cur->prv=q;	


	if (q==last_report1) last_report1=cur;
	cur->col=col;
	cur->s=s;
	return;
}
void list::addToReport2 (char* s, char* date) {
	if (!first_report2) {
		first_report2=new report2;
		first_report2->date=date;
		first_report2->s=s;
		first_report2->next=NULL;
		first_report2->prv=NULL;
		last_report2=first_report2;
		return;
	}
	report2* cur=new report2;
	last_report2->next=cur;
	cur->prv=last_report2;
	last_report2=cur;
	last_report2->date=date;
	last_report2->s=s;
	last_report2->next=NULL;
	return;
}
void list::make_report (catalog* cur) {
	buy* cur1=first_buy;
	int col=0; //количество товара в наличии
	int buy=0; //сумма, на которую товар был закуплен
	while (cur1) {
		if (!strcmp(cur->code, cur1->code)) {
			col+=cur1->col;
			buy+=toRUR (cur1->price)*cur1->col;
		}
		cur1=cur1->next;
	}
	sale* cur2=first_sale;
	int sale=0; //сумма, вырученная с продажи
	while (cur2) {
		if (!strcmp (cur2->code, cur->code)) {
			sale+=toRUR(cur2->price)*cur2->col;
		}
		cur2=cur2->next;
	}
	char* buf=new char[1024];
	int r=0;
	strinsert (buf, "   ", 0);
	r+=2;
	if (strlen(cur->name)>3) { strinsert (buf, cut(cur->name, 0, 3), r+1); r+=4; }
	else  { strinsert (buf, cur->name, r+1); r+=strlen (cur->name); }
	strinsert (buf, "\t\t\t", r+1);
	r+=3;
	strinsert (buf, inttostr(col), r+1);
	r+=strlen (inttostr (col));
	strinsert (buf, "\t\t   ", r+1);
	r+=5;
	strinsert (buf, inttostr (buy), r+1);
	r+=strlen (inttostr (buy));
	strinsert (buf, "\t\t\t", r+1);
	r+=3;
	strinsert (buf, inttostr(sale), r+1);
	r+=strlen (inttostr(sale));
	buf [++r]='\0';
	char* buf2=new char [strlen (buf)+1];
	strcpy_s (buf2, strlen (buf)+1, buf);
	addToReport1 (buf, col);
}
void list::showreport () {
	if (!first_catalog) {
		std::cout << "Каталоги не загружены!\n";
		return;
	}
	report1* i=first_report1;
	while (i) {
		delete [] i->s;
		//delete i;
		i=i->next;
	}
	first_report1=NULL;
	get_report ();
	report1* cur=first_report1;
	while (cur) {
		std::cout << cur->s<<"\n";
		cur=cur->next;
	}
	return;
}
void list::showreport (char* s) {
	report2* d=first_report2;
	while (d) {
		delete [] d->s;
		//delete d;
		d=d->next;
	}
	first_report2=NULL;
	last_report2=NULL;
	
	buy* cur1=first_buy;
	while (cur1) {
		if (!strcmp(cur1->code, s)) {
			char* buf=new char [1024];
			int r=0;
			strinsert (buf, "       \tПокупка", r);
			r+=14;
			strinsert (buf, "\t     ", r+1);
			r+=6;
			strinsert (buf, cur1->date, r+1);
			r+=10;
			strinsert (buf, "\t\t\t", r+1);
			r+=3;
			strinsert (buf, inttostr(cur1->col), r+1);
			r+=strlen (inttostr (cur1->col));
			strinsert (buf, "\t\t\t", r+1);
			r+=3;
			int sum=cur1->col*toRUR(cur1->price);
			strinsert (buf, inttostr (sum), r+1);
			r+=strlen (inttostr (sum));
			buf [++r]='\0';
			char* buf2=new char [strlen (buf)+1];
			strcpy_s (buf2, strlen (buf)+1, buf);
			addToReport2 (buf2, cur1->date);
		}
		cur1=cur1->next;
	}
	
	sale* cur2=first_sale;
	while (cur2) {
		if (!strcmp(cur2->code, s)) {
			char* buf=new char [1024];
			int r=0;
			strinsert (buf, "       \tПродажа", r);
			r+=14;
			strinsert (buf, "\t     ", r+1);
			r+=6;
			strinsert (buf, cur2->date, r+1);
			r+=10;
			strinsert (buf, "\t\t\t", r+1);
			r+=3;
			strinsert (buf, inttostr(cur2->col), r+1);
			r+=strlen (inttostr (cur2->col));
			strinsert (buf, "\t\t\t", r+1);
			r+=3;
			int sum=cur2->col*toRUR(cur2->price);
			strinsert (buf, inttostr (sum), r+1);
			r+=strlen (inttostr (sum));
			buf [++r]='\0';
			char* buf2=new char [strlen (buf)+1];
			strcpy_s (buf2, strlen (buf)+1, buf);
			addToReport2 (buf2, cur2->date);
		}
		cur2=cur2->next;
	}
	
	if (!first_report2) { std::cout << "По данному товару данные отсутствуют\n"; return; }
	std::cout << "\t\t\tОтсчет по товару\n\n";
	std::cout << "     Тип операции  \tдата\t\tколичество товара\t\tсумма\n\n";
	report2* i=first_report2;
	report2* j=first_report2;
	while (i) {
		j=first_report2;
		while (j->next) {
			if (date (j->date, j->next->date)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
			if (!j->next) break;
			j=j->next;
		}
		i=i->next;
		if (!i) break; //оО
	}
	report2* currr=first_report2;
	while (currr) {
		std::cout << currr->s;
		std::cout << "\n";
		currr=currr->next;
	}
	return;
}
void list::get_report () {
	std::cout << "\t\t\tОтсчет о наличии товара\n";
	std::cout << "  Наименование\tколичество товара   сумма, на которую\t\tсумма,\n";
	std::cout << "    товара\t     в наличии\t    товар был куплен\tвырученная с продажи\n";
	catalog* cur=first_catalog;
	while (cur) {
		make_report (cur);
		cur=cur->next;
	}
}

//сортировка каталога товаров
void list::sortcatalog (int n, bool f) { // (столбец сортировки, тип сортировки - true по возрастанию или false убыванию)
	bool w=true;
	catalog* i=first_catalog;
	catalog* j=first_catalog;
	while (i) {
		j=first_catalog;
		while (j->next) {
			//по возрастанию
			if (f) {
				if (n==1) {
					if (strcmp (j->code, j->next->code)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==2) {
					if (strcmp (j->name, j->next->name)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==3) {
					if (strcmp (j->num, j->next->num)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==4) {
					if (strcmp (j->raz, j->next->raz)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==5) {
					if (j->m>j->next->m) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
			}
			//по возрастанию
				
			//по убыванию
			else {
				if (n==1) {
					if (strcmp (j->code, j->next->code)<0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==2) {
						if (strcmp (j->name, j->next->name)<0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==3) {
					if (strcmp (j->num, j->next->num)<0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==4) {
					if (strcmp (j->raz, j->next->raz)<0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==5) {
					if (j->m>j->next->m) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
			}	
			//по убыванию
		
			if (!j->next) break; //оО
			j=j->next;
		}
		i=i->next;
		//if (!i) break; //оО
		if (!i && w) { i=first_catalog; w=false; }
	}
	return;
}
//сортировка каталога товаров

//сортировка каталога покупки товаров
void list::sortbuy (int n, bool f) {
	bool w=true;
	buy* i=first_buy;
	buy* j=first_buy;
	while (i) {
		j=first_buy;
		while (j->next) {
			//по возрастанию
			if (f) {
				if (n==1) {
					if (j->n>j->next->n) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==2) {
					if (strcmp (j->code, j->next->code)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==3) {
					//sortbuy (3, false); ///////
					//if (strcmp (j->num, j->next->num)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
					if (date (j->date, j->next->date)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==4) {
					if (j->col>j->next->col) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==5) {
					if (toRUR (j->price)>toRUR (j->next->price)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
			}
			//по возрастанию
				
			//по убыванию
			else {
				if (n==1) {
					if (j->n<j->next->n) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==2) {
					if (strcmp (j->code, j->next->code)<0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==3) {
					if (!date (j->date, j->next->date)) {
						//std::cout << "date решил, что " << j->date << " меньше " << j->next->date <<"\n";
						if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
					}
				}
				if (n==4) {
					if (j->col<j->next->col) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==5) {
					if (toRUR (j->price)<toRUR (j->next->price)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
			}	
			//по убыванию
		
			if (!j->next) break; //оО
			j=j->next;
		}
		i=i->next;
		//if (!i) break; //оО
		if (!i && w) { i=first_buy; w=false; }
	}
	return;
}
//сортировка каталога покупки товаров

void list::sortsale (int n, bool f) {
	bool w=true;
	sale* i=first_sale;
	sale* j=first_sale;
	while (i) {
		j=first_sale;
		while (j->next) {
			//по возрастанию
			if (f) {
				if (n==1) {
					if (j->n>j->next->n) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==2) {
					if (strcmp (j->code, j->next->code)>0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==3) {
					if (date (j->date, j->next->date)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==4) {
					if (j->col>j->next->col) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==5) {
					if (toRUR (j->price)>toRUR (j->next->price)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
			}
			//по возрастанию
				
			//по убыванию
			else {
				if (n==1) {
					if (j->n<j->next->n) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==2) {
					if (strcmp (j->code, j->next->code)<0) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==3) {
					if (!date (j->date, j->next->date)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==4) {
					if (j->col<j->next->col) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
				if (n==5) {
					if (toRUR (j->price)<toRUR (j->next->price)) if (!swap (j, j->next)) std::cout << "Ошибка обмена\n";
				}
			}	
			//по убыванию
			if (!j->next) break; //оО
			j=j->next;
		}
		i=i->next;
		//if (!i) break; //оО
		if (!i && w) { i=first_sale; w=false; }
	}
	return;
}

//обмен местами элементов в каталоге товаров
bool list::swap (catalog* cur1, catalog* cur2) {
	if (first_catalog&&(cur1!=cur2)) {
		catalog* buf;
		if (cur1->prv) cur1->prv->next=cur2;
		if (cur2->prv) cur2->prv->next=cur1;

		buf=cur1->next;
		cur1->next=cur2->next;
		cur2->next=buf;

		buf=cur1->prv;
		cur1->prv=cur2->prv;
		cur2->prv=buf;

		if (cur1->next) cur1->next->prv=cur1;
		if (cur2->next) cur2->next->prv=cur2;

		if (cur1==first_catalog) first_catalog=cur2;
		else if (cur2==first_catalog) first_catalog=cur1;

		if (cur1==last_catalog) last_catalog=cur2;
		else if (cur2==last_catalog) last_catalog=cur1;
			
		return true;
	}
	return false;
}
//обмен местами элементов в каталоге товаров

//обмен местами элементов в каталоге покупки товаров
bool list::swap (buy* cur1, buy* cur2) {
	if (first_buy&&(cur1!=cur2)) {
		buy* buf;
		if (cur1->prv) cur1->prv->next=cur2;
		if (cur2->prv) cur2->prv->next=cur1;

		buf=cur1->next;
		cur1->next=cur2->next;
		cur2->next=buf;

		buf=cur1->prv;
		cur1->prv=cur2->prv;
		cur2->prv=buf;

		if (cur1->next) cur1->next->prv=cur1;
		if (cur2->next) cur2->next->prv=cur2;

		if (cur1==first_buy) first_buy=cur2;
		else if (cur2==first_buy) first_buy=cur1;

		if (cur1==last_buy) last_buy=cur2;
		else if (cur2==last_buy) last_buy=cur1;
			
		return true;
	}
	return false;
}
//обмен местами элементов в каталоге покупки товаров

//обмен местами элементов в каталоге продажи товаров
bool list::swap (sale* cur1, sale* cur2) {
	if (first_sale&&(cur1!=cur2)) {
		sale* buf;
		if (cur1->prv) cur1->prv->next=cur2;
		if (cur2->prv) cur2->prv->next=cur1;

		buf=cur1->next;
		cur1->next=cur2->next;
		cur2->next=buf;

		buf=cur1->prv;
		cur1->prv=cur2->prv;
		cur2->prv=buf;

		if (cur1->next) cur1->next->prv=cur1;
		if (cur2->next) cur2->next->prv=cur2;

		if (cur1==first_sale) first_sale=cur2;
		else if (cur2==first_sale) first_sale=cur1;

		if (cur1==last_sale) last_sale=cur2;
		else if (cur2==last_sale) last_sale=cur1;
		return true;
	}
	return false;
}
//обмен местами элементов в каталоге продажи товаров

//обмен местами элементов в первом отчете
bool list::swap (report1* cur1, report1* cur2) {
	if (first_report1&&(cur1!=cur2)) {
		report1* buf;
		if (cur1->prv) cur1->prv->next=cur2;
		if (cur2->prv) cur2->prv->next=cur1;

		buf=cur1->next;
		cur1->next=cur2->next;
		cur2->next=buf;

		buf=cur1->prv;
		cur1->prv=cur2->prv;
		cur2->prv=buf;

		if (cur1->next) cur1->next->prv=cur1;
		if (cur2->next) cur2->next->prv=cur2;

		if (cur1==first_report1) first_report1=cur2;
		else if (cur2==first_report1) first_report1=cur1;

		if (cur1==last_report1) last_report1=cur2;
		else if (cur2==last_report1) last_report1=cur1;
		return true;
	}
	return false;
}
//обмен местами элементов в первом отчете

//обмен местами элементов во втором отчете
bool list::swap (report2* cur1, report2* cur2) {
	if (first_report2&&(cur1!=cur2)) {
		report2* buf;
		if (cur1->prv) cur1->prv->next=cur2;
		if (cur2->prv) cur2->prv->next=cur1;

		buf=cur1->next;
		cur1->next=cur2->next;
		cur2->next=buf;

		buf=cur1->prv;
		cur1->prv=cur2->prv;
		cur2->prv=buf;

		if (cur1->next) cur1->next->prv=cur1;
		if (cur2->next) cur2->next->prv=cur2;

		if (cur1==first_report2) first_report2=cur2;
		else if (cur2==first_report2) first_report2=cur1;

		if (cur1==last_report2) last_report2=cur2;
		else if (cur2==last_report2) last_report2=cur1;
		return true;
	}
	return false;
}
//обмен местами элементов во втором отчете
bool list::unique (char* s) {
	catalog* cur=first_catalog;
	while (cur) {
		if (!strcmp(cur->code, s)) return true;
		cur=cur->next;
	}
	return false;
}

bool list::unique (int q, int s) {
	if (q==2) {
		buy* cur=first_buy;
		while (cur) {
			if (cur->n==s) return true;
			cur=cur->next;
		}
		return false;
	}
	if (q==3) {
		sale* cur=first_sale;
		while (cur) {
			if (cur->n==s) return true;
			cur=cur->next;
		}
		return false;
	}
}

bool list::load (char* f1, char* f2, char* f3) {
	if (!loadfile (f1, 1)) {
		std::cout << "Ошибка в имени файла каталога товаров!\n";
		system ("pause");
		return false;
	}
	if (!loadfile (f2, 2)){
		std::cout << "Ошибка в имени файла покупки товаров!\n";
		system ("pause");
		return false;
	}
	if (!loadfile (f3, 3)){
		std::cout << "Ошибка в имени файла покупки товаров!\n";
		system ("pause");
		return false;
	}
	return true;
}