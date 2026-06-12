#include <windows.h>
#include "sh.h"
#include "wrapper.h"
#include "builtin.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <process.h>

#define DELIM "\n\t \v\f\r"

t_builtin g_builtins[] = {
    {"cd", builtin_cd},
    {"exit", builtin_exit},
    {"banner", builtin_banner}
};

char **parse_input(char *input) {
    // Default input_size is 1MB
    int input_size = 1024;
    int position = 0;

    // Allocate memory for the tokens
    char **tokens = mem_alloc(input_size * sizeof(char*));

    // Tokenizes the input based on a delimiter of space
    char *token = strtok(input, DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;

    return tokens;
}

void execute_input(char **args) {
    if (args == NULL || args[0] == NULL) {
        return;
    }
    
    // Check if the command is a builtin command
    for (int i = 0; i < sizeof(g_builtins)/sizeof(t_builtin); i++) {
        if (strcmp(args[0], g_builtins[i].builtin_name) == 0) {
            g_builtins[i].func(args);
            return;
        }
    }

    intptr_t pid = _spawnvp(_P_WAIT, args[0], (const char * const *)args);
    if (pid == -1) {
        printf(RED"'%s' is not a recognized command.\n"RST, args[0]);
    }
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    print_banner();

    char *token;
    rl_bind_key('\t', rl_complete);
    using_history();
    while(1) {
        char *prompt_line = create_prompt();
        if (prompt_line == NULL) {
            printf(RED"An error has occured."RST);
        }
        char *input = readline(prompt_line);

        if (!input) {
            break;
        }

        add_history(input);

        char **args = parse_input(input);
        execute_input(args);

        free(input);
        free(prompt_line);
    }

    return 0;
}