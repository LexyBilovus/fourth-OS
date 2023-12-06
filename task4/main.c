#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main() {

    uid_t user_id = getuid();
    struct passwd *user_info_by_uid;

    user_info_by_uid = getpwuid(user_id);
    if (user_info_by_uid == NULL) {
        perror("getpwuid");
        exit(EXIT_FAILURE);
    }

    printf("User information for UID %d:\n", user_id);
    printf("Username: %s\n", user_info_by_uid->pw_name);
    printf("Full name: %s\n", user_info_by_uid->pw_gecos);
    printf("Home directory: %s\n", user_info_by_uid->pw_dir);
    printf("\n");

    const char *username = "root";
    struct passwd *user_info_by_name;

    user_info_by_name = getpwnam(username);
    if (user_info_by_name == NULL) {
        perror("getpwnam");
        exit(EXIT_FAILURE);
    }

    printf("User information for username '%s':\n", username);
    printf("UID: %d\n", user_info_by_name->pw_uid);
    printf("Full name: %s\n", user_info_by_name->pw_gecos);
    printf("Home directory: %s\n", user_info_by_name->pw_dir);

    return 0;
}

