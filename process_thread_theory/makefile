CC:=gcc

virtual_memory: virtual_memory_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm $@

execve_invalid_path: execve_invalid_path.c
	-$(CC) -o $@ $^
	-./$@
	-rm $@

process_group_block: process_group_block_test.c
	-$(CC) -o $@ $^
