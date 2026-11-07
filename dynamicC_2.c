#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int *ptr;
    
    // Allocate memory for one integer
    ptr = (int *)malloc(sizeof(int));
    
    // Store the value 100
    *ptr = 100;
    
    // Print address and value before forking
    printf("Before fork - Address: %p, Value: %d\n", (void *)ptr, *ptr);
    
    // Fork a child process
    int pid = fork();
    
    if (pid == 0) {
        // CHILD PROCESS
        
        // Change the value to 200
        *ptr = 200;
        
        // Print address and value in child
        printf("CHILD - Address: %p, Value: %d\n", (void *)ptr, *ptr);
        
        // Free the memory in child
        free(ptr);
        
    } else {
        // PARENT PROCESS
        
        // Wait for child to finish
        wait(NULL);
        
        // Print address and value in parent
        printf("PARENT - Address: %p, Value: %d\n", (void *)ptr, *ptr);
        
        // Free the memory in parent
        free(ptr);
    }
    
    return 0;
}