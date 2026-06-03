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

pthread_cancel_deferred: pthread_cancel_deferred_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

pthread_cancel_async: pthread_cancel_async_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

pthread_cancel_disable: pthread_cancel_disable_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

race_condition: race_condition_test.c
	-$(CC) -o $@ $^
	-./$@

counter_mutex: counter_mutex_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@


rwlock_test_writer_unlock: rwlock_test_writer_unlock.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

rwlock: rwlock_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

rwlock_rw_alternate: rwlock_rw_alternate.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

rwlock_hungry_solved: rwlock_hungry_solved.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

condition_var: condition_var.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

condition_var_copy: condition_var_copy.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_sem_bin_thread: unnamed_sem_bin_thread.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_sem_bin_process_condition: unnamed_sem_bin_process_condition.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_sem_bin_process: unnamed_sem_bin_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_sem_count_thread: unnamed_sem_count_thread.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_sem_count_process: unnamed_sem_count_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

named_sem_bin: named_sem_bin.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@