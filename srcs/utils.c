#include "../includes/raytrace.h"

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void clear_image(t_mlx *mlx)
{
	ft_memset(mlx->data, 0, HEIGHT * mlx->size_line);
}

void put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;

	dst = mlx->data + ((y * mlx->size_line) + (x * (mlx->bpp / 8)));
	*(unsigned int *)dst = color;
}

void draw_and_refresh(t_state *state)
{
	clear_image(state->mlx);
	draw_circle(state->mlx, state->shadow_circle);
	draw_circle(state->mlx, state->circle);
	generate_rays(state->circle, state->rays);
	draw_rays(state, 0xFFFFFF);
	mlx_put_image_to_window(state->mlx->mlx, state->mlx->win, state->mlx->img, 0, 0);
}
