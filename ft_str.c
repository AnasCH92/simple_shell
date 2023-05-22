#include "main.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}


char **ft_realloc(char **ptr, size_t size)
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
    while(ptr[len])
    {
        save[len] = ft_strdup(ptr[len]);
        free(ptr[len]);
        len++;
    }
    free(ptr);
    save[len++] = NULL;
    save[len] = NULL;
    return (save);
}