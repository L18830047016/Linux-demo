CC:=gcc

create: create_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

terminate: terminate_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@