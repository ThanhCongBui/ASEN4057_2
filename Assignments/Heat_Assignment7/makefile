all:
	gcc -c BC.c BC.h
	gcc -c Build_LHS.c Build_LHS.h
	gcc -c Build_RHS.c Build_RHS.h
	gcc -c Output.c Output.h
	gcc -c Source.c Source.h
	gcc -c Conductivity.c Conductivity.h
	gcc -o heat_solve main.c Build_LHS.o Build_RHS.o BC.o Source.o Conductivity.o Output.o -lm -llapacke -llapack -lblas -lgfortran

clean:
	rm main.o BC.o Build_LHS.o Build_RHS.o Conductivity.o Output.o Source.o heat_solve
