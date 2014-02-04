#include "stdafx.h"
#include <iostream> 
#include "list.h"

//Добавление нового товара
void add (int q, list* &q1) {
	if (q==1) {
		char* temp=new char[1024];
		std::cout << "Введите код товара\n";
		std::cin >> temp;
		char* code=new char[strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		if (q1->unique (code)) { std::cout << "Товар с таким кодом уже есть, попробуйте снова\n"; return; }
		std::cout << "Введите наименование товара\n";
		std::cin >> temp;
		char* name=new char[strlen(temp)+1];
		strcpy_s (name, strlen (temp)+1, temp);
		std::cout << "Введите номенклатурный номер товара\n";
		std::cin >> temp;
		char* num=new char[strlen(temp)+1];
		strcpy_s (num, strlen (temp)+1, temp);
		std::cout << "Введите габариты товара\n";
		std::cin >> temp;
		char* raz=new char[strlen(temp)+1];
		strcpy_s (raz, strlen (temp)+1, temp);
		std::cout << "Введите массу товара\n";
		int m=0;
		std::cin >> m;
		q1->add (code, name, num, raz, m);
		return;
	}
	if (q==2) {
		char* temp=new char[1024];
		std::cout << "Введите номер п/п\n";
		int n=0;
		std::cin >> n;
		if (q1->unique (2, n)) { std::cout << "Товар с таким номером п/п, попробуйте снова\n"; return; }
		std::cout << "Введите код товара\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "Введите дату покупки товара\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "Введите количество товара\n";
		int col=0;
		std::cin >> col;
		std::cout << "Введите цену за еденицу товара\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		q1->add (n, code, date, col, price, 2);
		return;
	}
	if (q==3) {
		char* temp=new char[1024];
		std::cout << "Введите номер п/п\n";
		int n=0;
		std::cin >> n;
		if (q1->unique (3, n)) { std::cout << "Товар с таким номером п/п, попробуйте снова\n"; return; }
		std::cout << "Введите код товара\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "Введите дату покупки товара\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "Введите количество товара\n";
		int col=0;
		std::cin >> col;
		std::cout << "Введите цену за еденицу товара\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		q1->add (n, code, date, col, price, 3);
		return;
	}
}
//Добавление нового товара

//редактирование товара
void edit (int q, list* &q1) {
	if (q==1) {
		char* temp=new char[1024];
		std::cout << "Введите код товара, который надо изменить\n";
		std::cin >> temp;
		char* code=new char[strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "Введите новое наименование товара\n";
		std::cin >> temp;
		char* name=new char[strlen(temp)+1];
		strcpy_s (name, strlen (temp)+1, temp);
		std::cout << "Введите новый номенклатурный номер товара\n";
		std::cin >> temp;
		char* num=new char[strlen(temp)+1];
		strcpy_s (num, strlen (temp)+1, temp);
		std::cout << "Введите новые габариты товара\n";
		std::cin >> temp;
		char* raz=new char[strlen(temp)+1];
		strcpy_s (raz, strlen (temp)+1, temp);
		std::cout << "Введите новую массу товара\n";
		int m=0;
		std::cin >> m;
		if (!q1->edit (code, name, num, raz, m)) std::cout << "Ошибка при поиске изменяемого товара\n";
		return;
	}
	if (q==2) {
		char* temp=new char[1024];
		std::cout << "Введите номер п/п товара, который надо изменить\n";
		int n=0;
		std::cin >> n;
		std::cout << "Введите новый код товара\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "Введите новую дату покупки товара\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "Введите новое количество товара\n";
		int col=0;
		std::cin >> col;
		std::cout << "Введите новую цену за еденицу товара\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		if (!q1->edit (n, code, date, col, price, 2)) std::cout << "Ошибка при поиске изменяемого товара\n";
		return;
	}
	if (q==3) {
		char* temp=new char[1024];
		std::cout << "Введите номер п/п товара, который надо изменить\n";
		int n=0;
		std::cin >> n;
		std::cout << "Введите новый код товара\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "Введите новую дату продажи товара\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "Введите новое количество товара\n";
		int col=0;
		std::cin >> col;
		std::cout << "Введите новую цену за еденицу товара\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		if (!q1->edit (n, code, date, col, price, 3)) std::cout << "Ошибка при поиске изменяемого товара\n";
		return;
	}
}
//редактирование товара

//удаление товара
void delete_elem (int q, list* &q1) {
	if (q==1) {
		std::cout << "Введите код товара, который надо удалить из каталога товаров\n";
		char* temp=new char[1024];
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		if (!q1->delete_one (code)) std::cout << "Ошибка удаления\n";
		else std::cout << "Элемент удален\n";
		return;
	}
	if (q==2) {
		std::cout << "Введите номер п/п товара, который надо удалить из каталога покупки товаров\n";
		int n=0;
		std::cin >> n;
		if (!q1->delete_one (n, 2)) { std::cout << "Ошибка удаления\n"; return; }
		else std::cout << "Элемент удален\n";
		return;
	}
	if (q==3) {
		std::cout << "Введите номер п/п товара, который надо удалить из каталога продажи товаров\n";
		int n=0;
		std::cin >> n;
		if (!q1->delete_one (n, 3)) { std::cout << "Ошибка удаления\n"; return; }
		else std::cout << "Элемент удален\n";
		return;
	}
}
//удаление товара

//вывод меню и ввод пункта меню
int menu () {
	std::cout<< "Выберите желаемое действие\n"
			<< "0. Выход\n"
			<< "1. Вывести на экран каталог товаров\n"
			<< "2. Добавить запись в каталог товаров\n"
			<< "3. Удалить запись в каталоге товаров\n"
			<< "4. Редактировать запись в каталоге товаров\n"
			<< "\n"
			<< "5. Вывести на экран каталог покупки товаров\n"
			<< "6. Добавить запись в каталог покупки товаров\n"
			<< "7. Удалить запись из каталога покупки товаров\n"
			<< "8. Редактировать запись в каталоге покупки товаров\n"
			<< "\n"
			<< "9. Вывести на экран каталог продажи товаров\n"
			<< "10. Добавить запись в каталог продажи товаров\n"
			<< "11. Удалить запись из каталога продажи товаров\n"
			<< "12. Редактировать запись в каталоге продажи товаров\n"
			<< "\n"
			<< "13. Вывести отчет о наличии товара\n"
			<< "14. Вывести отчет по товару\n"
			<< "15. Загрузить каталоги\n"
			<< "16. Сохранить каталоги\n";
	int menu=-1;
	std::cin >> menu;
	return menu;
}
//вывод меню и ввод пункта меню

int main () {
	setlocale (LC_ALL, "Russian");
	list* q1=new list;

	for (;;) {
		int m=menu ();
		switch (m) {
			case 0:
				delete q1;
				system("pause");
				return 0;
			case 1:
				{
				if (!q1->print (1)) break;
				int type=0;
				std::cout	<< "Выберите тип и столбец сортировки\n"
							<< "0. Без сортировки\n"
							<< "1. Код товара - по возрастанию\n"
							<< "2. Код товата - по убыванию\n"
							<< "3. Наименование товара - по возрастанию\n"
							<< "4. Наименование товара - по убыванию\n"
							<< "5. Номенклатурный номер - по возрастанию\n"
							<< "6. Номенклатурный номер - по убыванию\n"
							<< "7. Габариты - по возрастанию\n"
							<< "8. Габариты - по убыванию\n"
							<< "9. Масса - по возрастанию\n"
							<< "10. Масса - по убыванию\n";
				std::cin >> type;
				if (type==0) break;
				if (type==1) q1->sortcatalog (1, true);
				if (type==2) q1->sortcatalog (1, false);
				if (type==3) q1->sortcatalog (2, true);
				if (type==4) q1->sortcatalog (2, false);
				if (type==5) q1->sortcatalog (3, false); 
				if (type==6) q1->sortcatalog (3, false);
				if (type==7) q1->sortcatalog (4, true);
				if (type==8) q1->sortcatalog (4, false);
				if (type==9) q1->sortcatalog (5, true);
				if (type==10) q1->sortcatalog (5, false);
				q1->print (1);
				break;
				}
			case 2:
				add (1, q1);
				break;
			case 3: {
				delete_elem (1, q1);
				break;
					}
			case 4:
				edit (1, q1);
				break;
			case 5:
				{
				if (!q1->print (2)) break;
				int type=0;
				std::cout	<< "Выберите тип и столбец сортировки\n"
							<< "0. Без сортировки\n"
							<< "1. Номер п/п - по возрастанию\n"
							<< "2. Номер п/п - по убыванию\n"
							<< "3. Код товара - по возрастанию\n"
							<< "4. Код товара - по убыванию\n"
							<< "5. Дата покупки - по возрастанию\n"
							<< "6. Дата покупки - по убыванию\n"
							<< "7. Количество товара - по возрастанию\n"
							<< "8. Количество товара - по убыванию\n"
							<< "9. Цена за единицу - по возрастанию\n"
							<< "10. Цена за единицу - по убыванию\n";
				std::cin >> type;
				if (type==0) break;
				if (type==1) q1->sortbuy (1, true);
				if (type==2) q1->sortbuy (1, false);
				if (type==3) q1->sortbuy (2, true);
				if (type==4) q1->sortbuy (2, false);
				if (type==5) { q1->sortbuy (3, false); q1->sortbuy (3, true); }
				if (type==6) q1->sortbuy (3, false);
				if (type==7) q1->sortbuy (4, true);
				if (type==8) q1->sortbuy (4, false);
				if (type==9) q1->sortbuy (5, true);
				if (type==10) q1->sortbuy (5, false);
				q1->print (2);
				break;
				}
			case 6:
				add (2, q1);
				break;
			case 7: {
				delete_elem (2, q1);
				break;
					}
			case 8:
				edit (2, q1);
				break;
			case 9:
				{
				if (!q1->print (3)) break;
				int type=0;
				std::cout	<< "Выберите тип и столбец сортировки\n"
							<< "0. Без сортировки\n"
							<< "1. Номер п/п - по возрастанию\n"
							<< "2. Номер п/п - по убыванию\n"
							<< "3. Код товара - по возрастанию\n"
							<< "4. Код товара - по убыванию\n"
							<< "5. Дата продажи - по возрастанию\n"
							<< "6. Дата продажи - по убыванию\n"
							<< "7. Количество товара - по возрастанию\n"
							<< "8. Количество товара - по убыванию\n"
							<< "9. Цена за единицу - по возрастанию\n"
							<< "10. Цена за единицу - по убыванию\n";
				std::cin >> type;
				if (type==0) break;
				if (type==1) q1->sortsale (1, true);
				if (type==2) q1->sortsale (1, false);
				if (type==3) q1->sortsale (2, true);
				if (type==4) q1->sortsale (2, false);
				if (type==5) { q1->sortsale (3, false); q1->sortsale (3, true); }
				if (type==6) q1->sortsale (3, false);
				if (type==7) q1->sortsale (4, true);
				if (type==8) q1->sortsale (4, false);
				if (type==9) q1->sortsale (5, true);
				if (type==10) q1->sortsale (5, false);
				q1->print (3);
				break;
				}
			case 10:
				add (3, q1);
				break;
			case 11:{
				delete_elem (3, q1);
				break;
					}
			case 12:
				edit (3, q1);
				break;
			case 13:
				q1->showreport ();
				break;
			case 14:
				{
				std::cout << "Введите код товара, по которому желаете получить отчет\n";
				char* buf=new char [1024];
				std::cin >> buf;
				char* s=new char [strlen (buf)+1];
				strcpy_s (s, strlen (buf)+1, buf);
				q1->showreport (s);
				break;
				}
			case 15:
				q1->load ("catalog.csv", "buy.csv", "sale.csv");
				break;
			case 16:
				q1->remake ();
				break;
			default:
				std::cout << "Неверный пункт меню, попробуйте снова\n";
				continue;
				break;
		}
	}
	delete q1;
	system("pause");
	return 0;
}