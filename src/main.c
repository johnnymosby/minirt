/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/24 13:11:02 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "colors.h"
#include "canvas.h"
#include "shapes.h"
#include "light.h"
#include "world.h"
#include "camera.h"
#include "computations.h"
#include "math.h"
#include "parser.h"
#include "errors.h"

static void	set_start(t_controls *controls, t_scene *scene, t_world *world)
{
	ft_bzero(world, sizeof(t_world));
	controls->scene = scene;
	controls->control_state = CAMERA;
	controls->shape_in_control = NULL;
	scene->canvas = NULL;
	scene->world = world;
}

int	pressed_key(int keycode, t_controls *controls)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_SPACE || keycode == KEY_CTRL)
	{
		if (controls->control_state == CAMERA)
			translate_camera(keycode, controls);
		else if (controls->control_state == SHAPE)
			translate_shape(keycode, controls);
		else if (controls->control_state == LIGHT)
			translate_light(keycode, controls);
	}
	else if (keycode == KEY_Q || keycode == KEY_E || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT || keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (controls->control_state == CAMERA)
			rotate_camera(keycode, controls);
		else if (controls->control_state == SHAPE)
			rotate_shape(keycode, controls);
	}
	else if (keycode == KEY_L && controls->control_state != LIGHT)
		controls->control_state = LIGHT;
	else if (keycode == KEY_L && controls->control_state == LIGHT)
		controls->control_state = CAMERA;
	return (0);
}

static int	quit_scene(t_scene *scene, int err_code)
{
	t_win	*win;

	win = NULL;
	if (scene && scene->canvas)
		win = scene->canvas->win;
	if (scene && scene->canvas && win && win->menu.img_ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, win->menu.img_ptr);
	if (scene && scene->canvas && win && win->pct.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->pct.img_ptr);
	if (scene && scene->canvas && win && win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (scene && scene->canvas && win && win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
	}
	if (scene && scene->canvas)
		free_canvas(scene->canvas);
	if (scene && scene->world && scene->world->lightning.material)
		free (scene->world->lightning.material);
	if (scene && scene->world && scene->world->lights)
		free(scene->world->lights);
	if (scene && scene->world && scene->world->shape)
		free(scene->world->shape);
	return (err_code);
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_win		win;
	t_world		world;
	t_controls	controls;

	if (argc != 2)
		return (print_error(NULL, -1, ERR_NB_ARGUMENTS, 0));
	set_start(&controls, &scene, &world);
	if (parser(argv[1], &scene) != 0)
		return (quit_scene(&scene, -1));
	if (render(&scene) == false)
		return (quit_scene(&scene, -1));
	if (initialise_mlx(&scene, &win) != 0)
		return (quit_scene(&scene, -1));
	canvas_to_mlx_image(scene.canvas, scene.canvas->win->pct.addr);
	render_menu(scene.canvas->win);
	mlx_put_image_to_window(scene.canvas->win->mlx_ptr,
		scene.canvas->win->win_ptr, scene.canvas->win->pct.img_ptr, 0, 0);
	catch_close_hooks(scene.canvas->win);
	mlx_key_hook(scene.canvas->win->win_ptr, pressed_key, &controls);
	mlx_mouse_hook(scene.canvas->win->win_ptr, mouse_hook, &controls);
	mlx_loop(scene.canvas->win->mlx_ptr);
	return (quit_scene(&scene, 0));
}
