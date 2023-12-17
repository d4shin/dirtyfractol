#include "../include/fractol.h"

double  ft_atof(char *str, double res)
{
        int     i;
        int     sign;
        int     divider;

        divider = 1;
        i = 0;
        sign = 1;
        res = 0;
        if (str[i] == '-')
        {
                sign = -1;
                i++;
        }
        while (str[i] && str[i] != '.')
                res = res * 10 + str[i++] - '0';
        if (str[i++] == '.')
        {
                while (str[i])
                {
                        res = res * 10 + str[i++] - '0';
                        divider *= 10;
                }
        }
        return (res * sign / divider);
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 72;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}
