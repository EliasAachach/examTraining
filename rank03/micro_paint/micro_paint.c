/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:27:53 by elaachac          #+#    #+#             */
/*   Updated: 2022/01/24 17:21:52 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background;
}				t_zone;

typedef struct	s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
	struct s_shape	*next;
}				t_shape;

int	ft_strlen(char **str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	check_zone(t_zone *zone)
{
	if ((zone->height > 0 && zone->height <= 300) || (zone->width > 0 && zone->width <= 300))
		return (0);
	return (1);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int scan_ret= 0;

	if ((scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
		return (0);
	if (check_zone(zone) == 0)
		return (0);
	return (1);
}

// free char* et close file avant chaque putstr d'erreur
int	main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;

	zone.width = 0;
	zone.height =0;
	zone.background = 0;
	if (argc == 2)
	{
		if (!(file = fopen(argv[1], "r")))
			ft_putstr("Error : argument\n");
		// prendre les infos
		if (!(get_zone(file, &zone)))
			ft_putstr("Error : corrupted file\n");
		// remplir le char *
		// print le char *
	}
	else
		ft_putstr("Error : argument\n");
	return (1);
}
