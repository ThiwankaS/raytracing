#include "../includes/raytrace.h"

void generate_rays(t_circle *circle, t_ray *rays)
{
	for(int i = 0; i < NUMBER_OF_RAYS; i++)
	{
		rays[i].x_start = circle->x;
		rays[i].y_start = circle->y;
		double angle = (double)i / NUMBER_OF_RAYS * 2 * M_PI;
		rays[i].angle = angle;
	}
}

void draw_rays(t_state *state, int color)
{
	double radius_squared = pow(state->shadow_circle->r, 2);
	double cx = state->shadow_circle->x;
	double cy = state->shadow_circle->y;
	double distance_square;
	for(int i = 0; i < NUMBER_OF_RAYS; i++)
	{
		t_ray ray = state->rays[i];
		int end_of_screen = 0;
		int at_obstacle = 0;
		double x_draw = ray.x_start;
		double y_draw = ray.y_start;
		double step = 1;
		while(!end_of_screen && !at_obstacle)
		{
			x_draw += step * cos(ray.angle);
			y_draw += step * sin(ray.angle);
			if(x_draw < 0 || x_draw > WIDTH || y_draw < 0 || y_draw > HEIGHT)
				end_of_screen = 1;
			distance_square = pow(x_draw - cx, 2) + pow(y_draw - cy, 2);
			if(distance_square < radius_squared)
				at_obstacle = 1;
			put_pixel(state->mlx, (int)x_draw, (int)y_draw, color);
		}
	}
}
