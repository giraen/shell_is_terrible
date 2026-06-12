#ifndef SH_H
#define SH_H

#define BUFFER_SIZE 256

#define RST "\x1b[0m"
#define RED "\x1b[38;2;237;135;150m"
#define PROMPT_COLOR "\x1b[38;2;198;160;246m"
#define CWD_COLOR "\x1b[38;2;63;185;80m"
#define BG_COLOR "\x1b[38;2;36;39;58m"
#define FG_COLOR "\x1b[38;2;202;211;245m"

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