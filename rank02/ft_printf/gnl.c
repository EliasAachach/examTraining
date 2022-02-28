#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int     ft_strlen(char *str)
{
    int i = 0;
	if (str)
	{
    	while (str[i] != '\0')
    	    i++;
	}
    return i;
}
char *copy(char *str, int ret)
{
    char *line;
    int i = 0;
    line = malloc(ret + 1);
    while (i < ret)
    {
        line[i] = str[i];
        if (line[i] == '\n')
        {
            line[i + 1] = '\0';
            return (line);
        }
        i++;
    }
    line[i] = '\0';
    return(line);
}
void    fill_zero(char *str)
{
    int i = 0;
    while (i < BUFFER_SIZE)
        str[i++] = '\0';
}
void    ft_strncpy(char *str1, char *str2, int len)
{
    int i = 0;
    while (i < len)
    {
        str1[i] = str2[i];
        i++;
    }
}
char *ft_strjoin(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int len1 = 0;
    int len2 = 0;
    if (str1)
        len1 = ft_strlen(str1);
    if (str2)
        len2 = ft_strlen(str2);
    char *line = malloc(len1 + len2 + 1);
    while (i < len1)
    {
        line[i] = str1[i];
        i++;
    }
    while(j < len2)
    {
        line[i + j] = str2[j];
        j++;
    }
    if (str1)
        free(str1);
    if (str2)
        free(str2);
    line[i + j] = '\0';
    return line;
}
char    *get_next_line(int fd)
{
    int rd;
    int len;
    char *line;
    char *tmp = NULL;
    static char buf[BUFFER_SIZE];
    static int  rest = 0;
    if (rest == 0)
    {
        fill_zero(buf);
        if ((rd = read(fd, buf, BUFFER_SIZE)) < 1)
            return tmp;
        line = copy(buf, rd);
        len = ft_strlen(line);
        rest = rd - len;
        ft_strncpy(buf, buf + len, rest);
        line = ft_strjoin(tmp, line);
        return line;
    }
    if (rest != 0)
    {
        tmp = copy(buf, rest);
        len = ft_strlen(tmp);
        rest = rest - len;
        ft_strncpy(buf, buf + len, rest);
    }
    return tmp;
}

int main()
{
    char *line;
	int fd = open("ft_printf.c", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        write(1, line, ft_strlen(line));
        // write(1, "\n", 1);
        free(line);
        line = NULL;
        line = get_next_line(fd);
    }
    if (line == NULL)
    {
        write(1, line, ft_strlen(line));
        write(1, "\n", 1);
        free(line);
        line = NULL;
    }
}