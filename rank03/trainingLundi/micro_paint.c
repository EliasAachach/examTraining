#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *back;
char bg, mod, fig_bg;
int	width_bg, height_bg;
float width_fig, height_fig, x, y;

int		checker(float i, float j)
{
	if (i < x || j < y || i > (x + width_fig) || j > (y + height_fig))
		return (0);
	if (i - x < 1 || j - y < 1 ||(x + width_fig) - i < 1 || (y + height_fig) - j < 1)
		return (1);
	return (2);
}

void	draw()
{
	int check = 0;
	int i = 0;;
	int j = 0;;
	while(j < height_bg)
	{
		i = 0;
		while(i < width_bg)
		{
			check = checker(i, j);
			if (check == 1 || (check == 2 && mod == 'R'))
				back[j * width_bg + i] = fig_bg;
			i++;
		}
		j++;
	}
}

void	print()
{
	int i = -1;
	while (++i < height_bg)
	{
		write(1, back + (i * width_bg), width_bg);
		write(1, "\n", 1);
	}
}

int parser(FILE *file)
{
	int i = 0;
	int result = 0;
	if (fscanf(file, "%d %d %c\n", &width_bg, &height_bg, &bg) != 3)
		return (1);
	if (width_bg < 0 || height_bg < 0 || width_bg > 300 || height_bg > 300)
		return (1);
	back = malloc(width_bg * height_bg);
	while (i < width_bg * height_bg)
		back[i++] = bg;
	while((result = fscanf(file, "%c %f %f %f %f %c\n", &mod, &x, &y, &width_fig, &height_fig, &fig_bg)) == 6)
	{
		if (mod != 'r' && mod != 'R')
			return (1);
		draw();
	}
	if (result == EOF)
	{
		print();
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return(1);
	}
	if (!(file = fopen(argv[1], "r")) || parser(file))
	{
		write(1, "Error: Operation file corrupted\n", 33);
		return (1);
	}
	free(back);
	return (0);
}
