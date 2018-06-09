#include"User.h"
#include"Anal.h"

void ui()
{
	initscr();
	noecho();
	keypad(curscr,1);
	printWelcome();
	do
	{
		int i=0;
		int c;
		string expression;
		printf("enter your expression,'q(uit)' to quit:\n");
		while((c=getch())!='\r')
		{
			if(c==KEY_UP||c==KEY_DOWN||c==KEY_LEFT||c==KEY_RIGHT)
			{
//
			}
			else
			{
				addch(c);
				expression[i]=c;
			}
			i++;
		}
		expression[i]='\0';
		Anal analex(expression);
		analex.analExpression();
//
	}while(1);
	endwin();
}


void printWelcome()
{
	printf("///////////////////////////\n");
	printf("welcome to use myCalculator\n");
	printf("//designed by Kaitian Guo//\n");
	printf("///////////////////////////\n\n");
	return;
}
