#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <environment_variable_name>\n", argv[0]);
        return 1;
    }

    const char *env_name = argv[1];
    char *env_value = getenv(env_name);

    if (env_value == NULL) {
        printf("Environment variable with name \"%s\" does not exist.\n", env_name);
    } else if (env_value[0] == '\0') {
        printf("Environment variable with name \"%s\" exists, but its value is not set.\n", env_name);
    } else {
        printf("Environment variable \"%s\" has the value: %s\n", env_name, env_value);
    }

    return 0;
}

