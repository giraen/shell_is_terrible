#include "builtin.h"
#include "sh.h"

void builtin_exit(char **args) {
    exit(0);
}

void builtin_banner(char **args) {
    print_banner();
}

void builtin_cd(char **args) {
    
}