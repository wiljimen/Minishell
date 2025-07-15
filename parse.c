#include "minishell.h"

int header()
{
    char *input;  // puntero para guardar lo que se escribe

    while (1)
    {
        input = readline("minishell> "); // muestra "minishell> " y espera input

        if (!input) // si el usuario pulsa Ctrl+D (EOF), salimos
            break;

        if (strcmp(input, "exit") == 0) // si el usuario escribe "exit", salimos
        {
            free(input);  
            break;
        }

        if (*input) // si la línea no está vacía (no es solo Enter)
            add_history(input); // guarda el comando en el historial

        free(input);
    }
    return (0);
}

int main()
{
    header();
    return (0);
}