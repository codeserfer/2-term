#include "stdafx.h"
#include "string.h"
#include <iostream>

//����������� ��� ����������
string::string(void) {
	s=new char [1]; //�������� ������ ��� ������� ������
	s[0]='\0'; //��������� ������� ������
	npos=0;
}
//����������� ��� ����������

//����������
string::~string(void) {
	if (s) delete [] s; //�������� ������
}
//����������

 //���������� ����� ���������� ������
int string::len (char* s) {
	int i=0;
	while (s[i++]!='\0'); //������ ���� �� ������, ���� �� �������� ������� ������
	return --i; //��� ��� i �������� ������� ����, ���� ������� ���������� �������
}
//���������� ����� ���������� ������

//���������� ����� ������, ����������� � ��������� ������
int string::len () {
	return len(s);
}
//���������� ����� ������, ����������� � ��������� ������

//����������� ������
char* string::copy (char* s) {
	if (!s) return NULL;
	char* s1=new char [len(s)+1];
	int i=0;
	for (;i<len(s); i++) s1[i]=s[i];
	s1[i]='\0';
	return s1;
}
//����������� ������

//�����������, ����������� �� ���� ������ ���� char*
string::string (char* w) {
	s=copy(w); //��������� ���������� ������ � �������� ������
	npos=0;
	return;
}
//�����������, ����������� �� ���� ������ ���� char*

//��������� int � char*
char* string::inttostr (int a) {
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
//��������� int � char*

//��������� double � char*
char* string::inttostr (double a) {
	char* buf=new char [1024];
	sprintf_s (buf, len(buf)+1, "%f", a);
	int lenbuf=len(buf)+1;
	char* s=copy (buf);
	return s;
}
//��������� double � char*

//�����������, ����������� �� ���� ������ ���� int
string::string (int w) {
	s=copy(inttostr(w)); //��������� ���������� ����� � ������ � ��������� �� � �������� ������
	npos=0;
	return;
}
//�����������, ����������� �� ���� ������ ���� int

//�����������, ����������� �� ���� ������ ���� double
string::string (double w) {
	s=copy(inttostr(w)); //��������� ���������� ����� � ������ � ��������� �� � �������� ������
	npos=0;
	return;
}
//�����������, ����������� �� ���� ������ ���� double

//����������� �����������
string::string (string& q) {
	s=copy (q.s); //��������� ������ �� ����������� ���������� ������ � ������� �����
	npos=0;
	return; 
}
//����������� �����������

//������������� �������� = ��� char*
string& string::operator= (char* b) {
	s=copy(b); //��������� ���������� ������
	npos=0;
	return *this;
}
//������������� �������� = ��� char*

//������������� �������� = ��� string
string& string::operator= (string& b) {
	s=copy (b.s); //��������� ������ �� ����������� ������
	npos=0;
	return *this;
}
//������������� �������� = ��� string

//������������� �������� = ��� int
string& string::operator= (int b) {
	s=copy (inttostr(b)); //��������� ����� � ������ � ��������� ��
	npos=0;
	return *this;
}
//������������� �������� = ��� int

//������������� �������� = ��� double
string& string::operator= (double b) {
	s=copy (inttostr(b)); //��������� ����� � ������ � ��������� ��
	npos=0;
	return *this;
}
//������������� �������� = ��� double

//������������ ���� ����� char*
char* string::concat (char* s1, char* s2) {
	if (!s1 && s2) return s2;
	if (s1 && !s2) return s1;
	if (!s1 && !s2) return NULL;
	char* snew=new char [len(s1)+len(s2)+1];
	int i=0;
	while (s1[i]!='\0') snew[i]=s1[i++];
	int j=0;
	while (s2[j]!='\0') snew[i++]=s2[j++];
	snew[i]='\0';
	return snew;
}
//������������ ���� ����� char*

//������������� �������� += ��� char*
string& string::operator+= (char* b) {
	if (!s) { s=copy (b); return *this; } //���� ������ � ������ �����, �� ������ ��������� ���������� ������
	this->s=concat (this->s, b); //���� ������ � ������ �� �����, �� ������������� ��
	return *this;
}
//������������� �������� += ��� char*

//������������� �������� += ��� int
string& string::operator+= (int b) {
	if (!s) { s=inttostr(b); return *this; } //���� ������ � ������ �����, �� ������ ��������� ���������� ����� � ������ � ��������� ��
	this->s=concat (this->s, inttostr(b)); //���� ������ � ������ �� �����, �� ������������� �� � ��������� �������� ����������� ����� � ������
	return *this;
}
//������������� �������� += ��� int

//������������� �������� += ��� double
string& string::operator+= (double b) {
	if (!s) { s=inttostr(b); return *this; } //���� ������ � ������ �����, �� ������ ��������� ���������� ����� � ������ � ��������� ��
	this->s=concat (this->s, inttostr(b)); //���� ������ � ������ �� �����, �� ������������� �� � ��������� �������� ����������� ����� � ������
	return *this;
}
//������������� �������� += ��� double

//������������� �������� += ��� string
string& string::operator+= (string& b) {
	if (!this->s) { s=b.s; return *this; } //���� ������ � ������ �����, �� ����������� �� ������ �� ����������� ������
	this->s=concat (this->s, b.s); //���� ������ � ������ �� �����, �� ������������� �� � ������ �� ����������� ������
	return *this;
}
//������������� �������� += ��� string

//������������� �������� []
char& string::operator[] (const int index) {
	if (index>=len(s) || index<0) throw (1); //���� ���������� ����� ������, ��� �������� � ������, �� ������ exception
	return s[index]; //���������� ��������� ������
}
//������������� �������� []

//������������� �������� ��������� >
bool operator> (string &q1, string &q2) {
	int minlen=0;
	//���� ����� ������� ������:
	if (q1.len()<q2.len()) minlen=q1.len();
	else minlen=q2.len ();
	//����������:
	for (int i=0; i<minlen; i++) {
		if (q1.s[i]>q2.s[i]) return true;
		if (q1.s[i]<q2.s[i]) return false;
	}
	return true;
}
//������������� �������� ��������� >

//������������� �������� ��������� <
bool operator< (string &q1, string &q2) {
	int minlen=0;
	//���� ����� ������� ������:
	if (q1.len()<q2.len()) minlen=q1.len();
	else minlen=q2.len ();
	//����������:
	for (int i=0; i<minlen; i++) {
		if (q1.s[i]<q2.s[i]) return true;
		if (q1.s[i]>q2.s[i]) return false;
	}
	return true;
}
//������������� �������� ��������� <

//��������� �����
bool string::cmp (char* s1, char* s2) {
	if (len(s1)!=len(s2)) return false;
	for (int i=0; i<len(s1)+1; i++) if (s1[i]!=s2[i]) return false;
	return true;
}
//��������� �����

//������������� �������� ��������� ==
bool operator== (string &q1, string &q2) {
	if (q1.cmp(q1.s, q2.s)) return true;
	else return false;
	return true;
}
//������������� �������� ��������� ==

//������������� �������� ������ <<
std::ostream& operator<<(std::ostream& out, string& p) {
	out <<p.s;
	return out;
}
//������������� �������� ������ <<

//������������� �������� ������ <<
std::ostream& operator<<(std::ostream& out, string *p) {
	out <<p->s;
	return out;
}
//������������� �������� ������ <<

//������������� �������� + (������������ ���� ����� �� ���� ����������� �������)
string& operator+ (string&q1, string& q2) {
	string* buf=new string (q1.concat (q1.s, q2.s)); //������� ������ ��������� ����� � �������� ���� ��������� ������������
	return *buf; //���������� ������ �� ��������� ������
}
//������������� �������� + (������������ ���� ����� �� ���� ����������� �������)

//������� ���������� ���������� �������� � ������ � ����� ������, ������������ � ������� trim ()
int string::probel (char* s) {
	int c=0;
	for (int i=0; i<len(s)+1; i++) {
		char q=s[i];
		if (q==' ' || q=='\n' || q=='\t') c++;
		else break;
	}
	for (int i=len(s)-1; i>=0; i--) {
		char q=s[i];
		if (q==' ' || q=='\n' || q=='\t') c++;
		else break;
	}
	return c;
}
//������� ���������� ���������� �������� � ������ � ����� ������, ������������ � ������� trim ()

//��������� ���������� �������� 
void string::trim () {
	int p=probel (s);
	char* q=new char [len(s)-p+1];
	bool f1=false;
	int j=0;
	for (int i=0; i<len(q)+1; i++) {
		char w=s[i];
		if ((w==' ' || w=='\n' || w=='\t')&&!f1) continue;
		f1=true;
		q[j]=s[i];
		if (j==len(s)-p-1) break;
		j++;
	}
	q[++j]='\0';
	delete [] s;
	s=q;
	return;
}
//��������� ���������� �������� 

//������������� �������: ��������� ���������� �������� (������� ������, ������, ���������) � ����� ������.
string& Ttrim (string& q) {
	q.trim (); //�������� ������� trim () ��� ������, ����������� ��� �������� ������
	return q;
}
//������������� �������: ��������� ���������� �������� (������� ������, ������, ���������) � ����� ������.

//������������� �������: ������ ����������� ���� �����
void Tswap (string& q1, string& q2) {
	string  b=b.copy(q1.s);
	q1.s=q2.s;
	q2.s=b.copy(b.s);
}
//������������� �������: ������ ����������� ���� �����

//��������� char* � int
int string::stringtonumber (char* s) {
	int num=0;
	int start=0;
	int end=len(s)-1;
	if (s[0]=='-') { start=1; end-=1; }
	for (int i=start, j=end; i<len (s); i++, j--) {
		num+=((int)s[i]-48)*pow(10, j);
	}
	if (start==0) return num;
	else return (-1*num);
}
//��������� char* � int

//������ strcut
char* string::cut (char* q, int start, int l) {
	char* b=new char [l+1];
	int j=0;
	for (int i=start; i<start+l; i++,j++) b[j]=q[i];
	b[j]='\0';
	return b;
}
//������ strcut

//����� ������� ��������� ���������
int string::pos (string what) {
	npos=0;
	for (int i=0; i<=len(s); i++) {
		for(int j=0; j<what.len(); j++) {
			if (what.s[j]!=s[i+j]) break;
			if (j==what.len()-1) {
				npos=i+1;
				this->what=copy (what.s); //���������
				return i;
			}
		}
	}
	throw 2;
	return 0;
}
//����� ������� ��������� ���������

//������� ������� ��������� ��������� � ������
int string::find (char* what) {
	for (int i=0; i<=len(s); i++) {
		for(int j=0; j<len(what); j++) {
			if (what[j]!=s[i+j]) break;
			if (j==len(what)-1) {
				return i;
			}
		}
	}
	return -1;
}
//������� ������� ��������� ��������� � ������

//�������� ���������
void string::del (int begin, int length) {
	char* q=new char [len(s)-length+2];
	int j=0;
	for (int i=0; i<len(s); i++) if (i<begin || i>begin+length-1) q[j++]=s[i];
	q[j]='\0';
	delete [] s;
	s=q;
}
//�������� ���������

//�������� ���� ��������� ���������
void string::delall (string& q) {
	int s=find (q.s);
	while (s!=-1) { //���� ��������� ��� ���������, �������
		del (s, len (q.s));
		s=find (q.s);
	}
}
//�������� ���� ��������� ���������

//���������� ���������� ���������
int string::nextpos() {
	for (int i=npos; i<len(s); i++) {
		for(int j=0; j<len(what); j++) {
			if (what[j]!=s[i+j]) break;
			if (j==len(what)-1) {
				npos=i+1;
				return i;
			}
		}
	}
	throw 2;
}
//���������� ���������� ���������

//�������� ���������
void string::del (string& w) {
	int begin=pos (w);
	int length=len (w.s);
	del (begin, length);
	return;
}
//�������� ���������

//������� ������� � ������ �������
char string::tolower (char c) {
	if ((int)c>=(int)'A' && (int)c<=(int)'Z') return (char)((int)c+32);
	if ((int)c>=(int)'�' && (int)c<=(int)'�') return (char)((int)c+32);
	if ((int)c==(int)'�') return '�';
	return c;
}
//������� ������� � ������ �������

//���������� ���� ��������� �������� (� ��������� � ���������) � ������� ��������
void string::lower () {
	for (int i=0; i<len(s)+1; i++) {
		s[i]=tolower(s[i]);
	}
}
//���������� ���� ��������� �������� (� ��������� � ���������) � ������� ��������

//������� ������� � ������� �������
char string::toupper (char c) {
	if ((int)c>=(int)'a' && (int)c<=(int)'z') return (char)((int)c-32);
	if ((int)c>=(int)'�' && (int)c<=(int)'�') return (char)((int)c-32);
	if ((int)c==(int)'�') return '�';
	return c;
}
//������� ������� � ������� �������

//���������� ���� ��������� �������� (� ��������� � ���������) � �������� ��������
void string::upper () {
	for (int i=0; i<len(s)+1; i++) {
		s[i]=toupper(s[i]);
	}
}
//���������� ���� ��������� �������� (� ��������� � ���������) � �������� ��������:

//���������, ������� �� ������ ������ �� ���� � ����� "�����"
bool string::onlyint (char* s) {
	for (int i=0; i<len(s); i++) if (((int)s[i]<(int)'0' || (int)s[i]>(int)'9') && s[0]!='-') return false;
	return true;
}
//���������, ������� �� ������ ������ �� ���� � ����� "�����"

//���������, ������� �� ������ ������ �� ����, ����� "�����" � �������
bool string::onlydouble (char* s) {
	for (int i=0; i<len(s); i++) if (((int)s[i]<(int)'0' || (int)s[i]>(int)'9') && s[0]!='-' && s[i]!=',') return false;
	return true;
}
//���������, ������� �� ������ ������ �� ����, ����� "�����" � �������

//�������������� � int
int string::to_int () {
	if (!onlyint (s)) throw (3);
	if (len(s)>10) throw (4);
	if (len(s)==10 && s[0]!='-') throw (4);
	return stringtonumber (s);
}
//�������������� � int

//��������� char* � double
double string::to_double () {
	if (!onlydouble (s)) throw (3);
	if (len(s)>10) throw (4);
	if (len(s)==10 && s[0]!='-') throw (4);
	int z=this->find (",");
	int w1=stringtonumber (cut(s, 0, z));
	int w2=stringtonumber (cut (s, z+1, len(s)-z-1));
	int col=len(inttostr(w2));
	return w1+w2*pow (10, -1*col);
}
//��������� char* � double

//�������������� ������
void string::reverse() {
	for (int i=0, j=len(s)-1; i<((len(s)+1)/2); i++, j--) {
		char q=s[i];
		s[i]=s[j];
		s[j]=q;
	}
	return;
}
//�������������� ������

//������� ��������� �� ��������� �������
void string::ins (string& what, int where) {
	char* q=new char [len(s)+len(what.s)+1];
	int i=0; //������� ����� ������
	int j=0; //������� �������� ������1
	int k=0; //�������� ����������� ������
	for (;i<len(s)+len(what.s); i++) {
		if (i<where) { q[i]=s[j++]; continue;}
		if (i>=where+len(what.s)) { q[i]=s[j++]; continue;}
		q[i]=what.s[k++];
	}
	q[i]='\0';
	delete [] s;
	s=q;
}
//������� ��������� �� ��������� �������

//������ ������� ��������� ��������� what �� replace_with
void string::replace (string& what, string& with) {
	int newlen=len(s)-len(what.s)+len(with.s)+1;
	char* q=new char [newlen];
	int where=find (what.s);
	int i=0;
	int j=0;
	int k=where+len(with.s)-(len(with.s)-len(what.s));
	for (;i<newlen-1; i++) {
		if (i<where) { q[i]=s[i]; continue; }
		if (i>=where && i<where+len(with.s)) { q[i]=with.s[j++]; continue; }
		q[i]=s[k++];
	}
	q[i]='\0';
	delete [] s;
	s=q;
}
//������ ������� ��������� ��������� what �� replace_with

//������ ���� ��������� ��������� what �� replace_with
void string::replaceall (string& what, string& replace_with) {
	int where=find (what.s);
	while (where!=-1) { //���� ���� ��� ��������, ��������:
		this->replace (what, replace_with);
		where=find (what.s);
	}
}
//������ ���� ��������� ��������� what �� replace_with

//������������� �������: ����� ������ � ��������
int Tlen (string& q) {
	return q.len();
}
//������������� �������: ����� ������ � ��������