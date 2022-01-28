#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int w, h;
char *draw;
char bg, f_bg, mod;
float x, y, radius;

int		check_pixel(float i, float j)
{
	float dist = sqrtf((i - x) * (i - x) + (j - y) * (j - y));

	if (dist <= radius)
	{
		if (radius - dist < 1)
			return (2);
		return (1);
	}
	return (0);
}

void	drawing()
{
	int i =0;
	int j = 0;
	int check = 0;

	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			check = check_pixel(i, j);
			if (check == 1 || (check == 2 && mod == 'C'))
				draw[(j * w) + i] = f_bg;
			i++;
		}
		j++;
	}
}

void	print_drawing()
{
	int i = 0;

	while (i < h)
	{
		write (1, draw + (i * w), w);
		write (1, "\n", 1);
		i++;
	}
}

int	parser(FILE *file)
{
	int i = 0, result;
	if (fscanf(file,"%d %d %c\n", &w, &h, &bg) != 3)
		return (1);
	if (w < 1 || w > 300 || h < 1 || h > 300)
		return (1);
	draw = malloc(h * w);
	while (i < w * h)
		draw[i++] = bg;
	while ((result = fscanf(file, "%c %f %f %f %c\n", &mod, &x, &y, &radius, &f_bg)) == 5)
	{
		if (radius <= 0 || (mod != 'c' && mod != 'C'))
			return (1);
		drawing();
	}
	if (result == EOF)
	{
		print_drawing();
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		write(1, "Error : argument\n", 17);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")) || parser(file))
	{
		write(1, "Error : Operation file corrupted\n", 32);
		return (1);
	}
	free(draw);
	fclose(file);
	return (0);
}
