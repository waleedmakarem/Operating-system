#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <new_root_directory>\n", argv[0]);
        return 1;
    }
    const char *new_root = argv[1];
    if (chroot(new_root) != 0) {
        fprintf(stderr, "chroot() failed: %s\n", strerror(errno));
    return 1;
}
if(chdir("/")!=0){
    fprintf(stderr, "chdir() failed: %s\n", strerror(errno));
    return 1;
}
char *command[]={"/bin/bash", Null};
execv(command[0], command);
fprintf(stderr, "execv() failed: %s\n", strerror(errno));
return 1;
