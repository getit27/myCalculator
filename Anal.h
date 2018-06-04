#pragma once
#include<string>
#include<list>
#include<ctype>

class Anal
{
private:
	const int I=-1;
	const int add=-2;
	const int subtract=-3;
	const int multiply=-4;
	const int divide=-5;
	const int djg=-6;
	const int arg=-7;
	const int leftbracket=-8;
	const int rightbracket=-9;
	const int membrane=-10;
	const int power=-11;
	const int unexpectednumber=1;
	const int invalidchar=2;
	const int unexpectedalpha=3;
	int error;
	int errorlocal;
	string strexpression;
	list<int> listexpression;
	void printerror();
	void dealWord(string word);
	void dealNumber(string number);
	void dealComplex();
	void dealSymbol(char symbol);
public:
	Anal(string expression);
	~Anal();
	void analexpression();
	list<int> getResult();
}
