#include "../includes/raytrace.h"

int main(void)
{
	t_mlx mlx;
	t_state state;
	t_circle circle = {300, 300 , 80, 0xFFA500 };
	t_circle shadow_circle = {600, 500 , 120, 0x00FFF0};

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Raytracing");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
	state.mlx = &mlx;
	state.circle = &circle;
	state.shadow_circle = &shadow_circle;
	state.drag = 0;
	state.offset_x = 0;
	state.offset_y = 0;
	draw_and_refresh(&state);
	mlx_hook(mlx.win, EVENT_CLOSE, MASK_NO_EVENT, close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, on_mouse_press, &state);
	mlx_hook(mlx.win, 4, 1L << 2, on_mouse_press, &state);
	mlx_hook(mlx.win, 5, 1L << 3, on_mouse_release, &state);
	mlx_hook(mlx.win, 6, 1L << 6, on_mouse_move, &state);
	mlx_loop(mlx.mlx);
	return (0);
}
