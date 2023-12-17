#include "../include/fractol.h"

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t  i;

        i = 0;
        while ((s1[i] || s2[i]) && i < n)
        {
                if (s1[i] != s2[i])
                        return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
                else
                        i++;
        }
        return (0);
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}

//double	generate_random_c(void)
//{
//	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
//}

