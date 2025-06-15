#ifndef RAYTRACE_H
# define RAYTRACE_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_libft/libft.h"
# include "../ft_libft/ft_printf.h"
# include "../ft_libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define EVENT_CLOSE 17
# define MASK_NO_EVENT 0L
typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	char *data;
	int  bpp;
	int  size_line;
	int  endian;
} t_mlx;

typedef struct s_pixel
{
	int	x;
	int y;
	int color;
} t_pixel;

typedef struct s_circle
{
	double x;
	double y;
	double r;
	int color;
} t_circle;

#endif
