#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_print(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_cd(char **argv, int i)
{
	if (i !=2)
	{
		ft_print("error: cd: bad arguments\n");
	}
	else if (chdir(argv[1]) != 0)
	{
		ft_print("error: cd: cannot change directory to ");
		ft_print(argv[1]);
		ft_print("\n");
	}
}

int	main(int argc, char **argv, char **env)
{
	int i = 0;
	int	fd[2];
	int tmp;
	int pid;
	int ret;
	(void)argc;
	tmp = dup(STDIN_FILENO);
	while (argv[i] && argv[i+1])
	{
		argv = &argv[i+1];
		i = 0;
		while(argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		if (argv[0] && strcmp(argv[0], "cd") == 0)
			ft_cd(argv, i);
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			dup2(tmp, STDIN_FILENO);
			pid = fork();
			if (pid == 0)
			{
				argv[i] = NULL;
				close(tmp);
				if (execve(argv[0], argv, env) != 0)
				{
					ft_print("error: cannot execute ");
					ft_print(argv[0]);
					ft_print("\n");
					return (1);
				}
			}
			else
			{
				close(tmp);
				waitpid(-1, &ret, 0);
				tmp = dup(STDIN_FILENO);
			}
		}
		else if (i!=0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				argv[i] = NULL;
				dup2(fd[1], STDOUT_FILENO);
				dup2(tmp, STDIN_FILENO);
				close(fd[1]);
				close(fd[0]);
				close(tmp);
				if(execve(argv[0], argv, env) != 0)
				{
					ft_print("error: cannot execute ");
					ft_print(argv[0]);
					ft_print("\n");
				}
			}
			else
			{
				close(tmp);
				close(fd[1]);
				waitpid(-1, &ret, 0);
				tmp = dup(fd[0]);
			}
		}
	}
		close(tmp);
		return (0);
}
