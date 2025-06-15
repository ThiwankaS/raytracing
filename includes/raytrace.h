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

# define WIDTH 1000
# define HEIGHT 900
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

typedef struct s_state
{
	t_mlx *mlx;
	t_circle *circle;
	t_circle *shadow_circle;
	int drag;
	int offset_x;
	int offset_y;
} t_state;

void draw_circle(t_mlx *mlx, t_circle *c);

int close_window(t_mlx *mlx);
void clear_image(t_mlx *mlx);
void put_pixel(t_mlx *mlx, int x, int y, int color);
void draw_and_refresh(t_state *state);

int on_mouse_press(int button, int x, int y, t_state *state);
int on_mouse_release(int button, int x, int y, t_state *state);
int on_mouse_move(int x, int y, t_state *state);

#endif
