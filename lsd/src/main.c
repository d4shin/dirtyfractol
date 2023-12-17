#include "../include/fractol.h"

int	draw_fractal(t_fractal *fractal, char *type)
{
	if (ft_strncmp(type, "mandelbrot", 11) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(type, "julia", 6) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = 0.05;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp(type, "burningship", 12) == 0)
		draw_burning_ship(fractal);
	else
	{
		write(1, "Available types: mandelbrot, julia, burningship\n", 48);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

void    ft_params(t_fractal *fractal, char **argv)
{
		fractal->cx = ft_atof(argv[2], 0);
        	fractal->cy = ft_atof(argv[3], 0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc != 2 && (argc != 4 || ft_strncmp(argv[1], "julia", 6) != 0))
	{
		write(1, "Usage: ./fractol <type>\n", 24);
		write(1, "Available types: mandelbrot, julia, burningship\n", 48);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	if(argc == 4)
		ft_params(fractal, argv);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}

