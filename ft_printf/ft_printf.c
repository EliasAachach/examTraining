#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_strlen(char *str)
{
	int i = 0;

		while (str[i])
			i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, "(null)", 6));
}

int		nbr_len(unsigned int nbr, int base)
{
	unsigned int		n = nbr;
	int nbr_len = 0;

	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		nbr_len++;
	}
	if (nbr < 0)
		nbr_len ++;
	return (nbr_len);
}

int	ft_putnbr(int nbr)
{
	unsigned int unbr = 0;
	int len = 0;

	if (nbr < 0)
	{
		ft_putchar('-');
		len++;
		unbr = -nbr;
	}
	else
		unbr = nbr;
	len += nbr_len(unbr, 10);
	if (unbr > 10)
	{
		ft_putnbr(unbr / 10);
	}
	ft_putchar((unbr % 10) + '0');
	return (len);
}

int	manage_x(unsigned int nbr)
{
	 
}

int	ft_printf(char *str, ...)
{
	int	i = 0;
	int	total_len = 0;
	va_list args;
	
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] && str[i + 1] == 's')
			{
				total_len += ft_putstr(va_arg(args, char *));
				i++;
			}
			else if (str[i + 1] == 'd')
			{
				total_len += ft_putnbr(va_arg(args, int));
				i++;
			}
			else if (str[i + 1] == 'x')
			{
				total_len += manage_x(va_arg(args,unsigned int));
				i++;
			}
			else
				i++;
		}
		else
		{
			total_len += ft_putchar(str[i]);
		}
		i++;
	}
	va_end (args);
	return (total_len);
}

int main()
{
	char *str = NULL;

	printf("ret : %d\n", ft_printf("%d %d\n", -42, INT_MIN));
	printf("real : %d\n", printf("%d %d\n", -42, INT_MIN));
	// printf("ret == %i\n", ft_printf("coucou\n"));
	// printf("printf == %i\n", printf("coucou\n"));
	// printf("hexa == %i\n", ft_printf("%x\n", INT_MAX));
	// printf("Xprintf == %i\n", printf("%x\n", INT_MAX));
	// printf("int == %i\n", ft_printf("%d\n", INT_MIN));
	// printf("Iprintf == %i\n", printf("%d\n", INT_MIN));
	printf("string == %i\n", ft_printf("%s\n", "salut"));
	printf("Sprintf == %i\n", printf("%s\n", "salut"));
	printf("strNULL == %i\n", ft_printf("%s\n", str));
	printf("SNULLprintf == %i\n", printf("%s\n", str));
	// printf("monprintf == %i\n", ft_printf(".%s%d%s%x.\n","en int 42 = ", 42, "en hexa 42 = ", 42));
	// printf("VraIprintf == %i\n", printf(".%s%d%s%x.\n","en int 42 = ", 42, "en hexa 42 = ", 42));
}
