#include "../minishell.h"

void    built_cd(char **cmd)
{
    if (cmd[1] == NULL)
        chdir(getenv("HOME"));
    else if(cmd[1] != 0)
        perror("cd");
}

int main(int argc, char **argv)
{
    char cwd[1024];

    built_cd(argv);
    if(getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Directorio actual: %s\n", cwd);
    return (0);
}
// Probando, hay que verificar todas las opciones, directorio anterior con .. y con -, directorio actual.