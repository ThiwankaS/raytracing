#include "../includes/raytrace.h"

int on_mouse_press(int button, int x, int y, t_state *state)
{
	double r = state->circle->r;
	double dx = x - state->circle->x;
	double dy = y - state->circle->y;
	double radius_squared = pow(r, 2);
	if(button == 1)
	{
		double distance_squared = pow(dx, 2) + pow(dy, 2);
		if(distance_squared <= radius_squared)
		{
			state->drag = 1;
			state->offset_x = dx;
			state->offset_y = dy;
		}
		return (1);
	}
	return (0);
}

int on_mouse_release(int button, int x, int y, t_state *state)
{
	(void)x;
	(void)y;
	if(button == 1)
	{
		state->drag = 0;
		return (1);
	}
	return (0);
}

int on_mouse_move(int x, int y, t_state *state)
{
	if(state->drag)
	{
		state->circle->x = x - state->offset_x;
		state->circle->y = y - state->offset_y;
		draw_and_refresh(state);
		return (1);
	}
	return (0);
}
