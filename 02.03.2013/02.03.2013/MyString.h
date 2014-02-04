#pragma once
class MyString {
public:
	MyString(void);
	MyString(char*);
	MyString (MyString&);
	~MyString(void);
	void input ();
	void input (char*);
	void cut_screen ();
	int count (char*);
	char* output ();
	void output_screen();
	void get_array ();
	void paste (char*, int);
	void anagram ();
private:
	char* s1;
	char** m;
	int e;
	int longest;
	int longestid;
};

