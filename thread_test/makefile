CC:=gcc

create: create_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

terminate: terminate_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

pthread_detach: pthread_detach_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@