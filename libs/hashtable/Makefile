output: test.o hashtable.o
	clang test.o hashtable.o -o test

hashtable.o: hashtable.c hashtable.h
	clang -c hashtable.c

test.o: test.c
	clang -c test.c

clean:
	rm *.o test

