# Makefile


all: exit_asm hello compare

exit_asm: exit_asm.o
	gcc -o exit_asm exit_asm.o

exit_asm.o: exit_asm.s
	as -o exit_asm.o exit_asm.s

hello: hello.o
	gcc -o hello hello.o

hello.o: hello.s
	as -o hello.o hello.s

compare: compare.o
	gcc -o compare compare.o

compare.o: compare.s
	as -o compare.o compare.s

submit:
	tar -czvf code_P2_FSE.tar.gz README Makefile exit_asm.s hello.s compare.s

clean:
	rm -vf exit_asm *.o
