CC = gcc
CFLAGS = -Werror -Wall -std=c99 -g
LIBS =
OBJ_FILES = dyn_str_tests.o dyn_str.o
TARGET = dyn_str_tests

${TARGET}: ${OBJ_FILES}
	${CC} ${CFLAGS} ${LIBS} ${OBJ_FILES} -o ${TARGET}

dyn_str_tests.o: dyn_str_tests.c dyn_str.h
	${CC} ${CFLAGS} -c dyn_str_tests.c

dyn_str.o: dyn_str.c dyn_str.h
	${CC} ${CFLAGS} -c dyn_str.c

run:
	make && valgrind --leak-check=full ./${TARGET}

clean:
	rm -f ${OBJ_FILES} ${TARGET} *~
