#pragma once
class list {
private:
	struct catalog { //������� �������
		char* code; //��� ������
		char* name; //������������ ������
		char* num; //�������������� �����
		char* raz; //�������
		int m; //�����
		catalog* next;
		catalog* prv;
	};
	catalog* first_catalog;
	catalog* last_catalog;

	struct buy {
		int n; //����� �/�
		char* code; //��� ������
		char* date; //���� �������
		int col; //���������� ������
		char* price; //���� �� �������
		buy* next;
		buy* prv;
	};
	buy* first_buy;
	buy* last_buy;

	struct sale {
		int n; //����� �/�
		char* code; //��� ������
		char* date; //���� �������
		int col; //���������� ������
		char* price; //���� �� �������
		sale* next;
		sale* prv;
	};
	sale* first_sale;
	sale* last_sale;

	struct report1 {
		int col; //���������� ������ � �������
		char* s; //��������� ������ ������
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
	bool date (char*, char*); //���������� ��� ���� true - ������ ������ ������, false - ������ ������ ������
	bool money (char*, char*); //��������� ����� � ���������� ��� ������ ������
	void devision (char*, int);
	catalog* add (catalog*, catalog* &, catalog* &); //���������� �� ����
	int toRUR (char*); //������� ���� � ����� � ����� ���������� Int
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
	char* f_catalog; //��� ����� �������� �������
	char* f_buy; //��� ����� �������� �������
	char* f_sale; //��� ����� �������� �������
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