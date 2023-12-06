#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <variable_name> <value>\n", argv[0]);
        return 1;
    }

    const char *variable_name = argv[1];
    const char *value = argv[2];

    // Set environment variable with the specified value.
    if (setenv(variable_name, value, 1) != 0) {
        perror("setenv");
        return 1;
    }

    // Get the value of the environment variable and print it along with the name.
    char *env_value = getenv(variable_name);
    if (env_value != NULL) {
        printf("Environment variable %s: %s\n", variable_name, env_value);
    } else {
        printf("Environment variable %s not found\n", variable_name);
    }

    return 0;
}

