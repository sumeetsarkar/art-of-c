output: test.o mylib.o
	clang test.c mylib.c -o test

test.o: test.c
	clang -c test.c

mylib.o: mylib.c mylib.h
	clang -c mylib.c

clean:
	rm test *.o

