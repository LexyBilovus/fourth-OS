#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Clear all variables from the environment if no variable name is specified
        if (clearenv() == 0) {
            printf("The environment has been cleared.\n");
        } else {
            perror("Error clearing the environment");
        }
    } else if (argc == 2) {
        // Remove the specified variable from the environment
        if (unsetenv(argv[1]) == 0) {
            printf("The variable '%s' has been removed from the environment.\n", argv[1]);
        } else {
            perror("Error removing the variable from the environment");
        }
    } else {
        printf("Try again: %s [variable_name]\n", argv[0]);
    }

    // Print the current environment
    extern char **environ;
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}
