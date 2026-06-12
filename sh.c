#include "sh.h"
#include "wrapper.h"

// Return a prompt of format: [cwd] $
char* create_prompt() {
    // Get cwd
    char buffer[BUFFER_SIZE];
    char* cwd = getcwd(buffer, BUFFER_SIZE);

    if(cwd == NULL) {
        return NULL;
    }

    // Allocate size for the cwd and the '$>' prompt
    size_t prompt_size = strlen(cwd) + 14;
    char* p = calloc(prompt_size, 1);

    // Combine them
    strcat(p, BLE);
    strcat(p, cwd);
    strcat(p, RST);
    strcat(p, " $> ");

    return p;
}

void print_banner() {
    system("cls");
    
    time_t today = time(NULL);
    struct tm *tm = localtime(&today);
    char date_today[12];
    strftime(date_today, sizeof(date_today), "%d %b %Y", tm);

    printf(
"███████╗██╗  ██╗███████╗██╗     ██╗         ██╗███████╗\n"
"██╔════╝██║  ██║██╔════╝██║     ██║         ██║██╔════╝\n"
"███████╗███████║█████╗  ██║     ██║         ██║███████╗\n"
"╚════██║██╔══██║██╔══╝  ██║     ██║         ██║╚════██║\n"
"███████║██║  ██║███████╗███████╗███████╗    ██║███████║\n"
"╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝    ╚═╝╚══════╝\n"
                                                            
"████████╗███████╗██████╗ ██████╗ ██╗██████╗ ██╗     ███████╗\n"
"╚══██╔══╝██╔════╝██╔══██╗██╔══██╗██║██╔══██╗██║     ██╔════╝\n"
"   ██║   █████╗  ██████╔╝██████╔╝██║██████╔╝██║     █████╗\n"
"   ██║   ██╔══╝  ██╔══██╗██╔══██╗██║██╔══██╗██║     ██╔══╝\n"
"   ██║   ███████╗██║  ██║██║  ██║██║██████╔╝███████╗███████╗\n"
"   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═════╝ ╚══════╝╚══════╝\n"
    );
    printf("%s\n", date_today);
    printf("| SHit by giraen |\n\n");
}