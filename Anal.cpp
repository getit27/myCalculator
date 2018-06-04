#include"Anal.h"

Anal::void printerror()
{

}


Anal::Anal(string expression)
{
	strexpression=expression;
}


Anal::~Anal()
{

}


Anal::void analexpression()
{
	int state=0;//0:wait for new order1:number2:word
	const int waiting=0;
	const int number=1;
	const int word=2;
	const int complexnumber=3;
	string order;

	int len=strexpression.size();
	error=NULL;
	for(int i=0;i<len;i++)
	{
		if(strexpression[i]=='+'||strexpression[i]=='-'||strexpression[i]=='*'||strexpression[i]=='/'||strexpression[i]=='('||strexpression[i]==')'||strexpression[i]=='^'||strexpression[i]=='|')
		{

		}
		else if(isdigit(strexpression[i]))
		{
			if(state==waiting)
			{
			
			}
			else if(state==number)
			{

			}
			else
			{
				error=unexpectednumber;
				errorlocal=i;
				return;
			}
		}
		else if(isahpha(strexpression[i]))
		{
			if(state==waiting)
			{
				state=word;
				order="";
				order+=strexpression[i];

			}
			else if(state==word)
			{
				orser+=strexpression[i];
			}
			else if(state==number)
			{
				if(strexpression[i]=='i')
				{
					state=complexnumber;
					//
				}
				else
				{
					error=unexpectedalpha;
					errorlocal=i;
					return;
				}
			}
		}
		else if(strexpression[i]==' ')
		{
			if(state==waiting)
				;
			else if(state==word)
			{
				state=waiting;
				dealWord(order);
				order="";
			}
			else if(state==number)
			{
		
			}
		}
		else
		{
			error=invalidchar;
			errorlocal=i;
			return;
		}

}


Anal::list<int> getResult()
{
	return listexpression;
}


Anal::void dealWord(string word)
{

}
//put it into list

Anal::void dealNumber(string number)
{

}


Anal::void dealComplex(string)
{

}


Anal::void dealSymbol(char symbol)
{

}
