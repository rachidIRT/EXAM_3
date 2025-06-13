#include <unistd.h>
#include <stdio.h>

char ft_strcmp(char *s1, char *s2, int len)
{
    int i = 0;
    while(i < len && s1[i] == s2[i])
        i++;
        if (i == len)
            return (1);
        return (0);
}