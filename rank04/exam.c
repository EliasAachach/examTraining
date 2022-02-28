#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_print(char *str)
{
    write (2, str, ft_strlen(str));
}

//int    i = 0;

void    ft_cd(char **av, int i)
{
    if (i != 2)
        ft_print("error: cd: bad arguments\n");
    else if (chdir(av[1]) != 0)
    {
        ft_print("error: cd: cannot change directory to ");
        ft_print(av[1]);
        ft_print("\n");
    }
}

int    main(int ac, char **av, char **env)
{
    int    tmp;
    int pid;
    int ret;
    int fd[2];
    int i;

    (void)ac;
    tmp = dup(STDIN_FILENO); // copier le stdin dans tmp (à refaire à chaque fois qu'il y aura pipe ou 😉
    i = 0;
    while (av[i] && av[i + 1])
    {
        av = &av[i + 1];
    //    printf("av %s avi %s\n", *av, av[i]);
        i = 0; // reinitialiser i à 0 pour pouvoir ensuite l'incrémenter et trouver sa nouvelle position
        while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
            i++;
        if (av[0] && strcmp(av[0], "cd") == 0)
            ft_cd(av, i);
        else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
        {
            dup2(tmp, STDIN_FILENO);
            pid = fork();
            if (pid == 0)
            {
                av[i] = NULL;
                close (tmp);
                if (execve(av[0], av, env) != 0)
                {
                    ft_print("error: cannot execute ");
                    ft_print(av[0]);
                    ft_print("\n");
                    return (1);
                }
            }
            else
            {
                close (tmp);
                waitpid(-1, &ret, 0);
                tmp = dup(STDIN_FILENO);
            }
        }
        else if (i != 0 && strcmp(av[i], "|") == 0)
        {
            //printf("av0  %s avi %d %s\n", av[0], i, av[i]);
            pipe(fd);
            pid = fork();
            if (pid == 0)
            {
                av[i] = NULL;
                dup2(tmp, STDIN_FILENO);
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
                close(tmp);
                if (execve(av[0], av, env) != 0)
                {
                    ft_print("error: cannot execute ");
                    ft_print(av[0]);
                    ft_print("\n");
                    return (1);
                }
            }
            else
            {
                close(fd[1]);
                close(tmp);
                waitpid(-1, &ret, 0);
                tmp = dup(fd[0]);
                close(fd[0]);
            }
        }

    }
    close (tmp);
    return (0);
}