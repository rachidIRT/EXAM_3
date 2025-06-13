#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1

#endif

char    *ft_strdup(char *src)
{

    char dest = malloc(strlen(src) + 1);
    int i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char line[70000];
    static int b_pos = 0;
    static int b_read = 0;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    while (42)
    {
        if (b_pos >= b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if (b_read <= 0)
                break;
        }
        line[i++] = buffer[b_pos];
        if (buffer[b_pos - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return ft_strdup(line);
}