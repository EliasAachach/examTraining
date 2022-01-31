#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int width, height;
char mod, bg, fig_bg;
char *back;
float x, y, fig_w, fig_h;


int		check_pixel(float i, float j)
{
	if (i < x || j < y || i > (x + width) || j > (y + height)) //in
		return (0);
	else if (i - x < 1 || j - y < 1 || (x + width) - i < 1 || (y + height) - j < 1) //border
		return (1);
	return (2); //out
}

void	draw()
{
	int i, j = 0, check = 0;

	while(j < height)
	{
		i = 0;
		while(i < width)
		{
			check = check_pixel(i, j);
			if (check == 1 || (check == 2 && mod == 'R'))
				 back[(j * width) + i] = fig_bg;
			i++;
		}
		j++;
	}
}

void	print()
{
	int i = -1;

	while (++i < height)
	{
		write(1, (back + i * width), width);
		write(1, "\n", 1);
	}
}

int	parser(FILE *file)
{
	int result;
	int i = 0;

	if (fscanf(file, "%d %d %c\n", &width, &height, &bg) != 3)
		return (1);
	if (width <= 0 || width > 300 || height <= 0 || height > 300)
		return (1);
	back = malloc(width * height);
	while(i < width * height)
		back[i++] = bg;
	while ((result = fscanf(file, "%c %f %f %f %f %c\n", &mod, &x, &y, &fig_w, &fig_h, &fig_bg)) == 6)
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
		return (1);
	}
	if (!(file = fopen(argv[1], "r")) || parser(file))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	free(back);
	fclose(file);
	return (0);
}
