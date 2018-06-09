#include"Anal.h"

void Anal::printerror()
{
	printf("error:");
	switch(error)
	{
	case 1:
		printf("unexpected number");
		break;
	case 2:
		printf("invalid char");
		break;
	case 3:
		printf("unexpected alpha");
		break;
	case 4:
		printf("undefined word");
		break;
	case 5:
		printf("unknown state");
		break;
	defalut:
		printf("unknown error");
	}
	printf("\n");
	cout<<strexpression<<endl;
	for(int i=0;i<errorlocal;i++)
		printf(" ");
	printf("^\n");
	return;
}


Anal::Anal(string expression)
{
	strexpression=expression;
}


Anal::~Anal()
{

}


void Anal::analExpression()
{
	int state=0;//0:wait for new order1:number2:word
	const int waiting=0;
	const int number=1;
	const int word=2;
	const int complexnumber=3;
	string order;

	int len=strexpression.size();
	error=none;
	for(int i=0;i<len;i++)
	{
		if(strexpression[i]=='+'||strexpression[i]=='-'||strexpression[i]=='*'||strexpression[i]=='/'||strexpression[i]=='('||strexpression[i]==')'||strexpression[i]=='^'||strexpression[i]=='|')
		{
			if(state==number)
			{
				dealNumber(order);
				order="";
				state=waiting;
				dealSymbol(strexpression[i]);
			}
			if(state==word)
			{
				if(dealWord(order)==1)
				{
					error==undefinedword;
					errorlocal=i-order.length();
					return;
				}
				order="";
				state=waiting;
				dealSymbol(strexpression[i]);
			}
			if(state==complexnumber)
			{
				dealComplex();
				state=waiting;
				dealSymbol(strexpression[i]);
			}
			if(state==waiting)
			{
				dealSymbol(strexpression[i]);
			}
			else
			{
				error=unknownstate;
				errorlocal=i;
				return;
			}
		}
		else if(isdigit(strexpression[i]))
		{
			if(state==waiting)
			{
				order="";
				order+=strexpression[i];
				state=number;
			}
			else if(state==number)
			{
				order+=strexpression[i];
			}
			else
			{
				error=unexpectednumber;
				errorlocal=i;
				return;
			}
		}
		else if(isalpha(strexpression[i]))
		{
			if(state==waiting)
			{
				state=word;
				order="";
				order+=strexpression[i];
			}
			else if(state==word)
			{
				order+=strexpression[i];
			}
			else if(state==number)
			{
				if(strexpression[i]=='i')
				{
					state=complexnumber;
					dealNumber(order);
					order="";
				}
				else
				{
					error=unexpectedalpha;
					errorlocal=i;
					return;
				}
			}
			else
			{
				error=unexpectedalpha;
				errorlocal=i;
				return;
			}
		}
		else if(strexpression[i]==' ')
		{
			if(state==waiting)
				;
			else if(state==word)
			{
				state=waiting;
				if(dealWord(order)==1)
				{
					error==undefinedword;
					errorlocal=i-order.length();
					return;
				}
				order="";
			}
			else if(state==number)
			{
				state=waiting;
				dealNumber(order);
				order="";	
			}
			else if(state==complexnumber)
			{
				state=waiting;
				dealComplex();
			}
		}
		else
		{
			error=invalidchar;
			errorlocal=i;
			return;
		}
	}
	if(state==number)
	{
		dealNumber(order);
		state=waiting;
		order="";
	}
	else if(state==word)
	{
		state=waiting;
		if(dealWord(order)==1)
		{
			error==undefinedword;
			errorlocal=len-1-order.length();
				return;
		}
		order="";
	}
	return;
}


list<int> Anal::getResult()
{
	return listexpression;
}


int Anal::dealWord(string word)
{
	int wordcode;
	if(word=="dig")
		wordcode=-6;
	else if(word=="arg")
		wordcode=-7;
	else return 1;
	return 0;
}
//put it into list

void Anal::dealNumber(string number)
{
	listexpression.insert(listexpression.end(),stol(number));
	return;
}


void Anal::dealComplex()
{
	listexpression.insert(listexpression.end(),I);
	return;
}


void Anal::dealSymbol(char symbol)
{
	int symbolcode;
	switch(symbol)
	{
	case '+':
		symbolcode=add;
		break;
	case '-':
		symbolcode=subtract;
		break;
	case '*':
		symbolcode=multiply;
		break;
	case '/':
		symbolcode=divide;
		break;
	case '(':
		symbolcode=leftbracket;
		break;
	case ')':
		symbolcode=rightbracket;
		break;
	case '|':
		symbolcode=membrane;
		break;
	case '^':
		symbolcode=power;
		break;
	}
	listexpression.insert(listexpression.end(),symbolcode);
	return;
}

