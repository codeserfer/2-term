#include "stdafx.h"
#include <iostream>
#include "MyString.h"

int main () {
	MyString q;
	q.input ("1 sdf fff 4jjj,ss,fff");
	//std::cout << q.output ();
	//q.cut_screen ();
	//std::cout <<q.count ("1 sdf fff");
	//q.get_array ();
	std::cout << q.paste ("!", 2);


	return 0;
}
