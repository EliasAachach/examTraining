#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdarg.h>

int	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_printf(char *str, ...)
{
	size_t	i = 0;
	size_t	total_len = 0;
	va_list args;

	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] && str[i + 1] == 's')
			{
				
			}
			else if (str[i + 1] && str[i + 1] == 'd')
			{
				
			}
			else if (str[i + 1] && str[i + 1] == 'x')
			{
				
			}
		}
		else
		{
			total_len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
}

// int	main()
// {
// 	printf("mon printf : >%d<\n", ft_printf("", ));
// 	printf("vrai printf : >%d<\n", printf("", ));
// }
