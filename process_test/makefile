CC:=gcc

system: system_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork: fork_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_fd_test: fork_fd_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

erlou: erlou.c
	-$(CC) -o $@ $^

execve: execve_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

fork_execve: fork_execve_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

waitpid: waitpid_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

pstree: pstree_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

erlou_block: erlou_block.c
	-$(CC) -o $@ $^

orphan_process: orphan_process_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

perror: perror_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

errorno: errorno_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

process: process_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_pipe: unnamed_pipe_test.c
	-$(CC) -o $@ $^
	-./$@ "Hello, World!"
	-rm ./$@

fifo_write: fifo_write.c
	-$(CC) -o $@ $^

fifo_read: fifo_read.c
	-$(CC) -o $@ $^

shared_memory: shared_memory.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

shared_memory_block: shared_memory_block.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

father_son_mq: father_son_mq_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

producer: producer.c
	-$(CC) -o $@ $^
	
consumer: consumer.c
	-$(CC) -o $@ $^


signal: signal_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@