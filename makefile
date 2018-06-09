myCalculator:Main.o Anal.o Calc.o User.o
	g++ -o myCalculator -g Main.o Anal.o Calc.o User.o
Main.o:Main.c
	g++ -c -o Main.o Main.c
Anal.o:Anal.c
	g++ -c -o Anal.o Anal.c
Calc.o:Calc.c
	g++ -c -o Calc.o Calc.c
User.o:User.c
	g++ -c -o User.o User.c
clean:
	rm *.o
	rm myCalculator
