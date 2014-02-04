#include "stdafx.h"
#include <iostream> 
#include "list.h"

//���������� ������ ������
void add (int q, list* &q1) {
	if (q==1) {
		char* temp=new char[1024];
		std::cout << "������� ��� ������\n";
		std::cin >> temp;
		char* code=new char[strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		if (q1->unique (code)) { std::cout << "����� � ����� ����� ��� ����, ���������� �����\n"; return; }
		std::cout << "������� ������������ ������\n";
		std::cin >> temp;
		char* name=new char[strlen(temp)+1];
		strcpy_s (name, strlen (temp)+1, temp);
		std::cout << "������� �������������� ����� ������\n";
		std::cin >> temp;
		char* num=new char[strlen(temp)+1];
		strcpy_s (num, strlen (temp)+1, temp);
		std::cout << "������� �������� ������\n";
		std::cin >> temp;
		char* raz=new char[strlen(temp)+1];
		strcpy_s (raz, strlen (temp)+1, temp);
		std::cout << "������� ����� ������\n";
		int m=0;
		std::cin >> m;
		q1->add (code, name, num, raz, m);
		return;
	}
	if (q==2) {
		char* temp=new char[1024];
		std::cout << "������� ����� �/�\n";
		int n=0;
		std::cin >> n;
		if (q1->unique (2, n)) { std::cout << "����� � ����� ������� �/�, ���������� �����\n"; return; }
		std::cout << "������� ��� ������\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "������� ���� ������� ������\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "������� ���������� ������\n";
		int col=0;
		std::cin >> col;
		std::cout << "������� ���� �� ������� ������\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		q1->add (n, code, date, col, price, 2);
		return;
	}
	if (q==3) {
		char* temp=new char[1024];
		std::cout << "������� ����� �/�\n";
		int n=0;
		std::cin >> n;
		if (q1->unique (3, n)) { std::cout << "����� � ����� ������� �/�, ���������� �����\n"; return; }
		std::cout << "������� ��� ������\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "������� ���� ������� ������\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "������� ���������� ������\n";
		int col=0;
		std::cin >> col;
		std::cout << "������� ���� �� ������� ������\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		q1->add (n, code, date, col, price, 3);
		return;
	}
}
//���������� ������ ������

//�������������� ������
void edit (int q, list* &q1) {
	if (q==1) {
		char* temp=new char[1024];
		std::cout << "������� ��� ������, ������� ���� ��������\n";
		std::cin >> temp;
		char* code=new char[strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "������� ����� ������������ ������\n";
		std::cin >> temp;
		char* name=new char[strlen(temp)+1];
		strcpy_s (name, strlen (temp)+1, temp);
		std::cout << "������� ����� �������������� ����� ������\n";
		std::cin >> temp;
		char* num=new char[strlen(temp)+1];
		strcpy_s (num, strlen (temp)+1, temp);
		std::cout << "������� ����� �������� ������\n";
		std::cin >> temp;
		char* raz=new char[strlen(temp)+1];
		strcpy_s (raz, strlen (temp)+1, temp);
		std::cout << "������� ����� ����� ������\n";
		int m=0;
		std::cin >> m;
		if (!q1->edit (code, name, num, raz, m)) std::cout << "������ ��� ������ ����������� ������\n";
		return;
	}
	if (q==2) {
		char* temp=new char[1024];
		std::cout << "������� ����� �/� ������, ������� ���� ��������\n";
		int n=0;
		std::cin >> n;
		std::cout << "������� ����� ��� ������\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "������� ����� ���� ������� ������\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "������� ����� ���������� ������\n";
		int col=0;
		std::cin >> col;
		std::cout << "������� ����� ���� �� ������� ������\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		if (!q1->edit (n, code, date, col, price, 2)) std::cout << "������ ��� ������ ����������� ������\n";
		return;
	}
	if (q==3) {
		char* temp=new char[1024];
		std::cout << "������� ����� �/� ������, ������� ���� ��������\n";
		int n=0;
		std::cin >> n;
		std::cout << "������� ����� ��� ������\n";
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		std::cout << "������� ����� ���� ������� ������\n";
		std::cin >> temp;
		char* date=new char [strlen(temp)+1];
		strcpy_s (date, strlen (temp)+1, temp);
		std::cout << "������� ����� ���������� ������\n";
		int col=0;
		std::cin >> col;
		std::cout << "������� ����� ���� �� ������� ������\n";
		std::cin >> temp;
		char* price=new char [strlen(temp)+1];
		strcpy_s (price, strlen (temp)+1, temp);
		if (!q1->edit (n, code, date, col, price, 3)) std::cout << "������ ��� ������ ����������� ������\n";
		return;
	}
}
//�������������� ������

//�������� ������
void delete_elem (int q, list* &q1) {
	if (q==1) {
		std::cout << "������� ��� ������, ������� ���� ������� �� �������� �������\n";
		char* temp=new char[1024];
		std::cin >> temp;
		char* code=new char [strlen(temp)+1];
		strcpy_s (code, strlen (temp)+1, temp);
		if (!q1->delete_one (code)) std::cout << "������ ��������\n";
		else std::cout << "������� ������\n";
		return;
	}
	if (q==2) {
		std::cout << "������� ����� �/� ������, ������� ���� ������� �� �������� ������� �������\n";
		int n=0;
		std::cin >> n;
		if (!q1->delete_one (n, 2)) { std::cout << "������ ��������\n"; return; }
		else std::cout << "������� ������\n";
		return;
	}
	if (q==3) {
		std::cout << "������� ����� �/� ������, ������� ���� ������� �� �������� ������� �������\n";
		int n=0;
		std::cin >> n;
		if (!q1->delete_one (n, 3)) { std::cout << "������ ��������\n"; return; }
		else std::cout << "������� ������\n";
		return;
	}
}
//�������� ������

//����� ���� � ���� ������ ����
int menu () {
	std::cout<< "�������� �������� ��������\n"
			<< "0. �����\n"
			<< "1. ������� �� ����� ������� �������\n"
			<< "2. �������� ������ � ������� �������\n"
			<< "3. ������� ������ � �������� �������\n"
			<< "4. ������������� ������ � �������� �������\n"
			<< "\n"
			<< "5. ������� �� ����� ������� ������� �������\n"
			<< "6. �������� ������ � ������� ������� �������\n"
			<< "7. ������� ������ �� �������� ������� �������\n"
			<< "8. ������������� ������ � �������� ������� �������\n"
			<< "\n"
			<< "9. ������� �� ����� ������� ������� �������\n"
			<< "10. �������� ������ � ������� ������� �������\n"
			<< "11. ������� ������ �� �������� ������� �������\n"
			<< "12. ������������� ������ � �������� ������� �������\n"
			<< "\n"
			<< "13. ������� ����� � ������� ������\n"
			<< "14. ������� ����� �� ������\n"
			<< "15. ��������� ��������\n"
			<< "16. ��������� ��������\n";
	int menu=-1;
	std::cin >> menu;
	return menu;
}
//����� ���� � ���� ������ ����

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
				std::cout	<< "�������� ��� � ������� ����������\n"
							<< "0. ��� ����������\n"
							<< "1. ��� ������ - �� �����������\n"
							<< "2. ��� ������ - �� ��������\n"
							<< "3. ������������ ������ - �� �����������\n"
							<< "4. ������������ ������ - �� ��������\n"
							<< "5. �������������� ����� - �� �����������\n"
							<< "6. �������������� ����� - �� ��������\n"
							<< "7. �������� - �� �����������\n"
							<< "8. �������� - �� ��������\n"
							<< "9. ����� - �� �����������\n"
							<< "10. ����� - �� ��������\n";
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
				std::cout	<< "�������� ��� � ������� ����������\n"
							<< "0. ��� ����������\n"
							<< "1. ����� �/� - �� �����������\n"
							<< "2. ����� �/� - �� ��������\n"
							<< "3. ��� ������ - �� �����������\n"
							<< "4. ��� ������ - �� ��������\n"
							<< "5. ���� ������� - �� �����������\n"
							<< "6. ���� ������� - �� ��������\n"
							<< "7. ���������� ������ - �� �����������\n"
							<< "8. ���������� ������ - �� ��������\n"
							<< "9. ���� �� ������� - �� �����������\n"
							<< "10. ���� �� ������� - �� ��������\n";
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
				std::cout	<< "�������� ��� � ������� ����������\n"
							<< "0. ��� ����������\n"
							<< "1. ����� �/� - �� �����������\n"
							<< "2. ����� �/� - �� ��������\n"
							<< "3. ��� ������ - �� �����������\n"
							<< "4. ��� ������ - �� ��������\n"
							<< "5. ���� ������� - �� �����������\n"
							<< "6. ���� ������� - �� ��������\n"
							<< "7. ���������� ������ - �� �����������\n"
							<< "8. ���������� ������ - �� ��������\n"
							<< "9. ���� �� ������� - �� �����������\n"
							<< "10. ���� �� ������� - �� ��������\n";
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
				std::cout << "������� ��� ������, �� �������� ������� �������� �����\n";
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
				std::cout << "�������� ����� ����, ���������� �����\n";
				continue;
				break;
		}
	}
	delete q1;
	system("pause");
	return 0;
}