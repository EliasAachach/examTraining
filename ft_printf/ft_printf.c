#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
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
	if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (write(1, "(null)", 6));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr(int nbr)
{
	static int len;
	unsigned int unbr = 0;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		unbr = -nbr;
	}
	else
		unbr = nbr;
	if (unbr >= 10)
		ft_putnbr (unbr / 10);
	len += ft_putchar((unbr % 10 + '0'));
	return (len);
}

int		nbrlen_hex(unsigned int nbr)
{
	unsigned int		n = nbr;
	int nbr_len = 0;

	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		nbr_len++;
	}
	if (nbr < 0)
		nbr_len ++;
	return (nbr_len);
}

int		manage_x(unsigned int nbr)
{
	int	nbr_len = 0;
	unsigned int	tmp = 0;
	unsigned int	q = 0;
	unsigned int	r = 0;
	char	*nbr_final;
	char	*base = "0123456789abcdef";

	nbr_len = nbrlen_hex(nbr);
	nbr_final = (char *)malloc(sizeof(char) * nbr_len + 1);
	nbr_final[nbr_len] = '\0';
	nbr_len--;
	if (nbr < 16)
		nbr_final[nbr_len] = base[nbr];
	else
	{
		q = nbr / 16;
		r = nbr % 16;
		nbr_final[nbr_len] = base[r];
		nbr_len--;
		while (q >= 16)
		{
			tmp = q;
			q = tmp / 16;
			r = tmp % 16;
			nbr_final[nbr_len] = base[r];
			nbr_len--;
		}
		nbr_final[nbr_len] = base[q];
		nbr_len--;
	}
	nbr_len = ft_putstr(nbr_final);
	free(nbr_final);
	return (nbr_len);
}

int		ft_printf(char *str, ...)
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
			else if (str[i + 1] && str[i + 1] == 'd')
			{
				total_len += ft_putnbr(va_arg(args, int));
				i++;
			}
			else if (str[i + 1] && str[i + 1] == 'x')
			{
				total_len += manage_x(va_arg(args, unsigned int));
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
	va_end(args);
	return (total_len);
}

int main()
{
	char *str = NULL;

	printf("ret == %i\n", ft_printf("coucou\n"));
	printf("printf == %i\n", printf("coucou\n"));
	printf("hexa == %i\n", ft_printf("%x\n", 42));
	printf("Xprintf == %i\n", printf("%x\n", 42));
	printf("int == %i\n", ft_printf("%d\n", -42));
	printf("Iprintf == %i\n", printf("%d\n", -42));
	printf("string == %i\n", ft_printf("%s\n", "salut"));
	printf("Sprintf == %i\n", printf("%s\n", "salut"));
	printf("strNULL == %i\n", ft_printf("%s\n", str));
	printf("SNULLprintf == %i\n", printf("%s\n", str));
	printf("monprintf == %i\n", ft_printf(".%s%d%s%x.\n","en int 42 = ", 42, "en hexa 42 = ", 42));
	printf("VraIprintf == %i\n", printf(".%s%d%s%x.\n","en int 42 = ", 42, "en hexa 42 = ", 42));
	//merci lucrece pour le main
}
