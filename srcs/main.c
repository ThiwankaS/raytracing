#include "../includes/raytrace.h"

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;

	dst = mlx->data + ((y * mlx->size_line) + (x * (mlx->bpp / 8)));
	*(unsigned int *)dst = color;
}

void draw_circle(t_mlx *mlx, t_circle *c)
{
	double radius_squared = pow(c->r, 2);
	for(double x = (c->x - c->r); x < (c->x + c->r); x++)
	{
		for(double y = (c->y - c->r); y < (c->y + c->r);y++)
		{
			double distance_sqaured = pow(x - c->x, 2) + pow(y - c->y, 2);

			if(distance_sqaured < radius_squared)
			{
				put_pixel(mlx, (int)x, (int)y, c->color);
			}
		}
	}
}

int main(void)
{
	t_mlx mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Raytracing");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);

	t_circle circle = {100, 100 , 80, 0x00FF00};

	draw_circle(&mlx, &circle);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, EVENT_CLOSE, MASK_NO_EVENT, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
