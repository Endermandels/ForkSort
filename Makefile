# Fork Sort
# Elijah Delavar
# main.c mergeSort.c mergeSort.h Makefile

EXEC = forksort
OBJS = main.o mergeSort.o
CCFLAGS = gcc -Wall -std=gnu11 --pedantic
CACHE = .cache

${EXEC}: ${OBJS}
	${CCFLAGS} -o ${EXEC} ${OBJS}
	make cache

# if the cache does not exist, create it
cache: | ${CACHE}
	mv ${OBJS} ${EXEC} ${CACHE}

# $@ refers to the name of this command, ${CACHE}
# -p creates the directory if it doesn't exist
#	and does not return an error if it does exist
${CACHE}:
	mkdir -p $@

main.o: main.c
	${CCFLAGS} -c main.c

mergeSort.o: mergeSort.c
	${CCFLAGS} -c mergeSort.c

run: ${EXEC}
	./${CACHE}/${EXEC}

runv: ${EXEC}
	valgrind ./${CACHE}/${EXEC}
