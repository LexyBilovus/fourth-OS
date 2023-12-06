#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];
    struct utsname sys_info;

    // Get the hostname of the computer
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("Error getting hostname");
        return 1;
    }

    // Get additional information about the computer using uname
    if (uname(&sys_info) == 0) {
        printf("Operating System: %s %s\n", sys_info.sysname, sys_info.release);
        printf("Architecture: %s\n", sys_info.machine);
        printf("Kernel Version: %s\n", sys_info.version);
        printf("Computer Description: %s\n", sys_info.nodename);
    } else {
        perror("Error getting system information");
        return 1;
    }

    return 0;
}
