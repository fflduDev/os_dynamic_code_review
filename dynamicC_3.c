#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	// Allocate memory on the heap
    	int *ptr = malloc(sizeof(int));
    	*ptr = 12345;
    	printf("Parent: malloc'd value %d at %p\n\n", *ptr, (void*)ptr);
	pid_t pid = fork();

	if (pid == 0) {
		// Child: show the copy, then exec (obliterates heap)
		printf("Child: same address %p, same value %d (copy)\n", (void*)ptr, *ptr);
		printf("Child: calling exec — heap is about to vanish...\n\n");
		execlp("ls", "ls", NULL);
		perror("exec failed");
		exit(1);
    	}

	// Parent: heap untouched
    	wait(NULL);
    	printf("\nParent: value still %d at %p — exec only hit the child\n", *ptr, (void*)ptr);
    	free(ptr);
    	return 0;
}