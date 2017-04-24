all:
	gcc main.c BC.c BC.h Build_LHS.c Build_LHS.h Build_RHS.c Build_RHS.h Conductivity.c Conductivity.h Output.c Output.h Source.c Source.h -llapacke -llapack -lblas -lgfortran -o heat_solve

clean:
	rm main.o BC.o Build_LHS.o Build_RHS.o Conductivity.o Output.o Source.o heat_solve
