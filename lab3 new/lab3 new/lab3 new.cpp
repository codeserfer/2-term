#include "stdafx.h"
#include <iostream>
#include "string.h"
int main () {
	try {

		setlocale(LC_ALL,"Russian");

		string q;
		std::cout << "����������� ��� ����������:\n";
		std::cout << q<<"\n";
		string w ("���� ������������ �����������\n");
		string e (w);
		std::cout << e;
		string r ("���� ������������, ������������ char*\n");
		std::cout << r;
		string t (1223);
		std::cout << "���� ������������, ������������ int\n";
		std::cout << t<<"\n";
		std::cout << "���� ������������, ������������ double\n";
		string y (123.3);
		std::cout << y<<"\n";
		std::cout << "���� ���������� = � +=\n";
		string u="��������� ";
		u+="day";
		u+=" ����������� �� ";
		u+=25.5;
		u+="�������� �� ";
		u+=34;
		u+=" ��������\n";
		string i (" Very good!");
		u+=i;
		std::cout << u<<"\n";
		string i3="test";
		std::cout << "���� ��������� [], test [2]:\n";
		std::cout << i3[2]<<"\n";
		string o="����� ���� ������ ����� (28)";
		std::cout << o<<"\n";
		std::cout << o.len () <<"\n";
		std::cout << "����� ������� ��������� ��������� \"���\" � ������ \"������������\", ���������� ������� ������� �������:\n";
		string a="������������";
		string s="���";
		std::cout << a.pos (s)<<"\n";
		std::cout << "����� ������� ���������:\n";
		std::cout << a.nextpos ()<<"\n";
		std::cout << "�������� �� ������ \"�����������\" ������ \"�����\":\n";
		string d="�����������";
		string f="�����";
		d.del (f);
		std::cout << d <<"\n";
		std::cout << "�������� �� ������ \"��������\" 2 �������� ������� � 3 �������:\n";
		string f3="��������";
		f3.del (3, 2);
		std::cout << f3<<"\n";
		std::cout << "�������� ���� ��������� ������ \"er\" � ������ \"qwertyqwertyqwerty\":\n";
		string g="qwertyqwertyqwerty";
		string h="er";
		g.delall (h);
		std::cout << g<<"\n";
		std::cout << "������� ��������� \"��\" � ������ \"�������\" ������� � 5 �������\n";
		string j="�������";
		string k="��";
		j.ins (k, 5);
		std::cout << j<<"\n";
		std::cout << "������ ������� ��������� ������ \"��\" �� \"��\" � ������ \"�������\"\n";
		string l="�������";
		string z="��";
		string x="��";
		l.replace (z, x);
		std::cout << l<<"\n";
		std::cout << "������ ���� ��������� ��������� \"x\" �� ��������� \"er\" � ������ \"qwxtyqwxtyqwxty\":\n";
		string c="qwxtyqwxtyqwxty";
		string v="er";
		string b="x";
		c.replaceall (b, v);
		std::cout << c <<"\n";
		std::cout << "��������� ���������� �������� � ������ \"   \n\t����, ��� �� ����?  \t\t\t\n\":\n";
		string m="   \n\t����, ��� �� ����?  \t\t\t\n";
		m.trim ();
		std::cout << "\""<<m<<"\"\n";
		std::cout << "������� ������ \"������� ����� BIG LETTERS\" � ������� ��������:\n";
		string q1="������� ����� BIG LETTERS";
		q1.lower ();
		std::cout << q1<<"\n";
		std::cout << "������� ������ \"��������� ����� little letters\" � �������� ��������:\n";
		string w2="��������� ����� little letters";
		w2.upper ();
		std::cout << w2<<"\n";
		std::cout << "�������������� ������ \"12345\" � ���� int:\n";
		string e2="12345";
		int e3=e2.to_int ();
		std::cout << e2<<"\n";
		///�������������� � double
		std::cout << "�������������� ������ \"56,552\" � ���� double:\n";
		string q5="56,552";
		double q55=q5.to_double ();
		std::cout << q55<<"\n";
		std::cout << "�������������� ������ \"������\":\n";
		string r2="������";
		r2.reverse ();
		std::cout << r2 <<"\n";
		std::cout << "������������� �������: ����� ������ \"������\"\n";
		string q3="������";
		std::cout << (Tlen(q3))<<"\n";
		std::cout << "������������� �������: ������������ ���� �����: ������ \"��������\" � \" �����\"\n";
		string w4="��������";
		string e4=" �����";
		string r4;
		r4=w4+e4;
		std::cout << r4<<"\n";

		std::cout << "������������� �������: Tswap - �������� ������� t4=\"������ �����\" � y4=\"����� ��������\"\n";
		string t4="������ �����";
		string y4="����� ��������";
		Tswap (t4, y4);
		std::cout << "t4="<<t4<<" y4="<<y4<<"\n";
		std::cout	<< "������������� �������: ��������� ���������� �������� � ������:\n"
					<< "\"   \t\n �������� ���� � ���������      \t\t\t\"";
		string i4="   \t\n �������� ���� � ���������      \t\t\t";
		Ttrim (i4);
		std::cout << "\n���������:\n\""<<i4<<"\"\n";
		std::cout << "������������� �������: ��������� ����� - �������� >\n";
		std::cout << "������� ������ \"�����\" � \"�����\"\n";
		string a4="�����";
		string s4="�����";
		if (a4>s4) std::cout << a4<<" ������, ��� "<<s4<<"\n";
		else std::cout << s4<<" ������, ��� "<<a4<<"\n";
		std::cout << "������������� �������: ��������� ����� - �������� <\n";
		std::cout << "������� ������ \"�����\" � \"�����\"\n";
		if (a4<s4) std::cout << a4<<" ������, ��� "<<s4<<"\n";
		else std::cout << s4<<" ������, ��� "<<a4<<"\n";
		std::cout << "������������� �������: ��������� ����� - �������� ==\n";
		std::cout << "������� ������� ������ \"�����\" � \"�����\", � ����� \"�����\" � \"�����\"\n";
		if (a4==s4) std::cout << "������ "<<a4<<" � "<<s4<<" �����\n";
		else std::cout << "������ "<<a4<<" � "<<s4<<" �� �����\n";
		if (a4==a4) std::cout << "������ "<<a4<<" � "<<a4<<" �����\n";
		else std::cout << "������ "<<a4<<" � "<<a4<<" �� �����\n";

	}
	catch (int a) {
		if (a==1) std::cout << "����� �� ������� ������!\n";
		if (a==2) std::cout << "����� ��������� �� �������!\n";
		if (a==3) std::cout << "������ ������ ��������� �������� �� ����!\n";
		if (a==4) std::cout << "������ ��� �������������� � ����� ������� �������!\n";
	}

	return 0;
}