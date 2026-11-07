 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    
    // Get input from user
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    // Remove newline if present
    input[strcspn(input, "\n")] = 0;
    
    // Calculate size needed
    int len = strlen(input);
    
    // Allocate memory for reversed string
    char *reversed = (char *)malloc(len + 1);
    
    // Check if malloc succeeded
    if (reversed == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Reverse the string
    for (int i = 0; i < len; i++) {
        reversed[i] = input[len - 1 - i];
    }
    reversed[len] = '\0';  // Null terminate
    
    // Print results
    printf("Original: %s\n", input);
    printf("Reversed: %s\n", reversed);
    
    // Free allocated memory
    free(reversed);
    
    return 0;
}