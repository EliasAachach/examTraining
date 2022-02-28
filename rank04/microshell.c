int	main(int argc, char **argv, char **env)
{
	int	ret;
	int	pid;
	int	tmp;
	int	fd[2];
	int	i;

	(void)argc;
	while(argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while(argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		
	}
}