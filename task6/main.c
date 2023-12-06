#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Вивести інформацію про поточне оточення
        print_environment();
    } else if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        // Вивести інформацію про роботу з програмою
        print_help();
    } else if (argc == 3 && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--info") == 0)) {
        // Вивести значення зазначеної змінної або повідомити, що її немає
        print_variable(argv[2]);
    } else if (argc == 4 && (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0)) {
        // Встановити значення змінної в оточенні і вивести його
        set_variable(argv[2], argv[3]);
    } else if (argc == 3 && (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--del") == 0)) {
        // Видалити змінну з оточення
        delete_variable(argv[2]);
    } else if (argc == 4 && strcmp(argv[1], "-a") == 0 && strcmp(argv[3], "-v") == 0) {
        // Набути нового значення для змінної і вивести його
        assign_variable(argv[2], argv[4]);
    } else if ((argc == 1 && strcmp(argv[1], "-c") == 0) || (strcmp(argv[1], "--clear") == 0)) {
        // Очистити оточення
        clear_environment();
    } else {
        // Неправильний формат команди, вивести допомогу
        print_help();
    }

    return 0;
}
void print_environment() {
    extern char **environ;
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}


void print_help() {
    printf("Usage: environ [options]\n");
    printf("Options:\n");
    printf("  -h, --help           Display this help message\n");
    printf("  -i, --info <variable> Display the value of the specified variable\n");
    printf("  -s, --set <variable=value> Set the value of the specified variable\n");
    printf("  -d, --del <variable> Delete the specified variable\n");
    printf("  -a, --assign <variable> --value <value> Assign a new value to the specified variable\n");
    printf("  -c, --clear          Clear the environment\n");
}

void print_variable(const char *variable) {
    char *value = getenv(variable);
    if (value) {
        printf("%s=%s\n", variable, value);
    } else {
        printf("Variable %s is not set.\n", variable);
    }
}

void set_variable(const char *variable, const char *value) {
    setenv(variable, value, 1);
    printf("%s=%s\n", variable, value);
}


void delete_variable(const char *variable) {
    unsetenv(variable);
}


void assign_variable(const char *variable, const char *value) {
    if (value) {
        setenv(variable, value, 1);
        printf("%s=%s\n", variable, value);
    } else {
        printf("No value specified for assignment.\n");
    }
}


void clear_environment() {
    clearenv();
}
