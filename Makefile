CC = gcc
CFLAG = -Werror -Wall -g
LIBS = 
EXE = run_tests
OBJ = 

${EXE}: dyn_str_tests.o dyn_str.o
	${CC} ${CFLAG} dyn_str_tests.o dyn_str.o -o ${EXE} ${LIBS}

dyn_str_tests.o: dyn_str_tests.c dyn_str.h
	${CC} -c dyn_str_tests.c

dyn_str.o: dyn_str.c dyn_str.h
	${CC} -c dyn_str.c

clean:
	rm *.o ${EXE}
