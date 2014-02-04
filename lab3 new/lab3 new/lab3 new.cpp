#include "stdafx.h"
#include <iostream>
#include "string.h"
int main () {
	try {

		setlocale(LC_ALL,"Russian");

		string q;
		std::cout << "Конструктор без параметров:\n";
		std::cout << q<<"\n";
		string w ("Тест конструктора копирования\n");
		string e (w);
		std::cout << e;
		string r ("Тест конструктора, принимающего char*\n");
		std::cout << r;
		string t (1223);
		std::cout << "Тест конструктора, принимающего int\n";
		std::cout << t<<"\n";
		std::cout << "Тест конструктора, принимающего double\n";
		string y (123.3);
		std::cout << y<<"\n";
		std::cout << "Тест операторов = и +=\n";
		string u="Солнечный ";
		u+="day";
		u+=" Температура от ";
		u+=25.5;
		u+="градусов до ";
		u+=34;
		u+=" градусов\n";
		string i (" Very good!");
		u+=i;
		std::cout << u<<"\n";
		string i3="test";
		std::cout << "Тест оператора [], test [2]:\n";
		std::cout << i3[2]<<"\n";
		string o="Длина этой строки равна (28)";
		std::cout << o<<"\n";
		std::cout << o.len () <<"\n";
		std::cout << "Поиск первого вхождения подстроки \"вет\" в строку \"Приветпривет\", возвращает позицию первого символа:\n";
		string a="Приветпривет";
		string s="вет";
		std::cout << a.pos (s)<<"\n";
		std::cout << "Поиск второго вхождения:\n";
		std::cout << a.nextpos ()<<"\n";
		std::cout << "Удаление из строки \"примусорвет\" строки \"мусор\":\n";
		string d="примусорвет";
		string f="мусор";
		d.del (f);
		std::cout << d <<"\n";
		std::cout << "Удаление из строки \"пиццерия\" 2 символов начиная с 3 символа:\n";
		string f3="Пиццерия";
		f3.del (3, 2);
		std::cout << f3<<"\n";
		std::cout << "Удаление всех вхождений строки \"er\" в строке \"qwertyqwertyqwerty\":\n";
		string g="qwertyqwertyqwerty";
		string h="er";
		g.delall (h);
		std::cout << g<<"\n";
		std::cout << "Вставка подстроки \"бо\" в строку \"карамла\" начиная с 5 символа\n";
		string j="карамла";
		string k="бо";
		j.ins (k, 5);
		std::cout << j<<"\n";
		std::cout << "Замена первого вхождения строки \"го\" на \"вы\" в строке \"гопечка\"\n";
		string l="гопечка";
		string z="го";
		string x="вы";
		l.replace (z, x);
		std::cout << l<<"\n";
		std::cout << "Замена всех вхождений подстроки \"x\" на подстроку \"er\" в строке \"qwxtyqwxtyqwxty\":\n";
		string c="qwxtyqwxtyqwxty";
		string v="er";
		string b="x";
		c.replaceall (b, v);
		std::cout << c <<"\n";
		std::cout << "Отсечение пробельных символов в строке \"   \n\tБыть, или не быть?  \t\t\t\n\":\n";
		string m="   \n\tБыть, или не быть?  \t\t\t\n";
		m.trim ();
		std::cout << "\""<<m<<"\"\n";
		std::cout << "Перевод строки \"БОЛЬШИЕ БУКВЫ BIG LETTERS\" к нижнему регистру:\n";
		string q1="БОЛЬШИЕ БУКВЫ BIG LETTERS";
		q1.lower ();
		std::cout << q1<<"\n";
		std::cout << "Перевод строки \"маленькие буквы little letters\" к верхнему регистру:\n";
		string w2="маленькие буквы little letters";
		w2.upper ();
		std::cout << w2<<"\n";
		std::cout << "Преобразование строки \"12345\" к типу int:\n";
		string e2="12345";
		int e3=e2.to_int ();
		std::cout << e2<<"\n";
		///Преобразование в double
		std::cout << "Преобразование строки \"56,552\" к типу double:\n";
		string q5="56,552";
		double q55=q5.to_double ();
		std::cout << q55<<"\n";
		std::cout << "Инвертирование строки \"привет\":\n";
		string r2="Привет";
		r2.reverse ();
		std::cout << r2 <<"\n";
		std::cout << "Дружественная функция: длина строки \"Гоголь\"\n";
		string q3="Гоголь";
		std::cout << (Tlen(q3))<<"\n";
		std::cout << "Дружественная функция: конкатенация двух строк: сложим \"Владимир\" и \" Путин\"\n";
		string w4="Владимир";
		string e4=" Путин";
		string r4;
		r4=w4+e4;
		std::cout << r4<<"\n";

		std::cout << "Дружественная функция: Tswap - обменяем местами t4=\"Листья опали\" и y4=\"Трава зеленеет\"\n";
		string t4="Листья опали";
		string y4="Трава зеленеет";
		Tswap (t4, y4);
		std::cout << "t4="<<t4<<" y4="<<y4<<"\n";
		std::cout	<< "Дружественная функция: отсечение пробельных символов у строки:\n"
					<< "\"   \t\n Тусклеют угли в полумраке      \t\t\t\"";
		string i4="   \t\n Тусклеют угли в полумраке      \t\t\t";
		Ttrim (i4);
		std::cout << "\nРезультат:\n\""<<i4<<"\"\n";
		std::cout << "Дружественная функция: сравнение строк - оператор >\n";
		std::cout << "Сравним строки \"Стула\" и \"Стулу\"\n";
		string a4="Стула";
		string s4="Стулу";
		if (a4>s4) std::cout << a4<<" больше, чем "<<s4<<"\n";
		else std::cout << s4<<" больше, чем "<<a4<<"\n";
		std::cout << "Дружественная функция: сравнение строк - оператор <\n";
		std::cout << "Сравним строки \"Стула\" и \"Стулу\"\n";
		if (a4<s4) std::cout << a4<<" меньше, чем "<<s4<<"\n";
		else std::cout << s4<<" меньше, чем "<<a4<<"\n";
		std::cout << "Дружественная функция: сравнение строк - оператор ==\n";
		std::cout << "Сначала сравним строки \"Стула\" и \"Стулу\", а потом \"Стула\" и \"Стула\"\n";
		if (a4==s4) std::cout << "Строки "<<a4<<" и "<<s4<<" равны\n";
		else std::cout << "Строки "<<a4<<" и "<<s4<<" не равны\n";
		if (a4==a4) std::cout << "Строки "<<a4<<" и "<<a4<<" равны\n";
		else std::cout << "Строки "<<a4<<" и "<<a4<<" не равны\n";

	}
	catch (int a) {
		if (a==1) std::cout << "Выход за пределы строки!\n";
		if (a==2) std::cout << "Такой подстроки не найдено!\n";
		if (a==3) std::cout << "Строка должна полностью состоять из цифр!\n";
		if (a==4) std::cout << "Строка для преобразования в число слишком большая!\n";
	}

	return 0;
}