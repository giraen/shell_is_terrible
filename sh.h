#ifndef SH_H
#define SH_H

#define BUFFER_SIZE 256

#define RST "\x1b[0m"
#define RED "\x1b[31m"
#define GRN "\x1b[32m"
#define YLW "\x1b[33m"
#define BLE "\x1b[34m"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h> // Linux only, use direct.h
#include <direct.h>
#include <time.h>

typedef struct s_builtin {
    const char *builtin_name;
    void (*func)(char **);
} t_builtin;

void print_banner();
char* create_prompt();

#endif