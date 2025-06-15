#include "../includes/raytrace.h"

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
