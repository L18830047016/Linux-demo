CC:=gcc

create: create_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@