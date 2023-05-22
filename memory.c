#include "main.h"



char **_realloc(char **ptr, size_t size)
{
        int len;
        char    **save;

        len = 0;
        if (ptr == NULL)
        {
                save = malloc(sizeof(char *) * 2);
                save[0] = NULL;
                save[1] = NULL;
                return (save);
        }

        save = malloc(size);
        while (ptr[len])
        {
                save[len] = _strdup(ptr[len]);
                free(ptr[len]);
                len++;
        }
        free(ptr);
        save[len++] = NULL;
        save[len] = NULL;
        return (save);
}

/**
 * free_array - free an array of pointers
 * @array: array of pointers
 * Return: void
 */

void free_array(char **array)
{
        int i;

        if (!array)
                return;

        for (i = 0; array[i]; i++)
                free(array[i]);

        free(array);
}
