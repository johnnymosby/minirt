/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/17 13:50:23 by aguilmea         ###   ########.fr       */
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

#define ERR_MEMORY_ALLOCATION	-1
#define ERR_MLX_FUNCTION		-2



static void	set_controls(t_controls *controls, t_scene *scene)
{
	controls->scene = scene;
	controls->control_state = CAMERA;
	controls->shape_in_control = NULL;
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
	else if (keycode == KEY_L)
	{
		if (controls->control_state != LIGHT)
			controls->control_state = LIGHT;
		else if (controls->control_state == LIGHT)
			controls->control_state = CAMERA;
	}
//	else if (keycode == KEY_ESC)
//		exit(0);
	return (0);
}

static int	quit_scene(t_scene *scene, int err_code)
{
	if (scene && scene->canvas && scene->canvas->win)
	{
		if (scene->canvas->win->menu.img_ptr != NULL)
			mlx_destroy_image(scene->canvas->win->mlx_ptr, scene->canvas->win->menu.img_ptr);
		if (scene->canvas->win->pct.img_ptr)
			mlx_destroy_image(scene->canvas->win->mlx_ptr, scene->canvas->win->pct.img_ptr);
		if (scene->canvas->win->win_ptr)
			mlx_destroy_window(scene->canvas->win->mlx_ptr, scene->canvas->win->win_ptr);
		if (scene->canvas->win->mlx_ptr)
		{
			mlx_destroy_display(scene->canvas->win->mlx_ptr);
			free(scene->canvas->win->mlx_ptr);
		}
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

static void	set_scene(t_scene *scene, t_world *world, t_win *window)
{
	ft_bzero(scene, sizeof(t_scene));
	ft_bzero(world, sizeof(t_world));
	ft_bzero(window, sizeof(t_win));
	scene->world = world;
	scene->canvas = canvas(PCT_WIDTH, WIN_HEIGHT);
	scene->canvas->win = window;
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_win		win;
	t_world		world;
	t_controls	controls;
	int			ret;

	set_scene(&scene, &world, &win);
	set_controls(&controls, &scene);
	if (argc != 2)
		return(quit_scene(NULL, ERR_NB_ARGUMENTS));
	ret = parser(argv[1], &scene);
	if (ret != 0)
		return(quit_scene(&scene, ret));
	if (render(&scene) == false)
		return(quit_scene(&scene, ERR_MEMORY_ALLOCATION));
	if (initialise_mlx(&win) == false)
		return(quit_scene(&scene, ERR_MLX_FUNCTION));
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	catch_close_hooks(scene.canvas->win);
	mlx_key_hook(win.win_ptr, pressed_key, &controls);
	mlx_mouse_hook(win.win_ptr, mouse_hook, &controls);
	mlx_loop(win.mlx_ptr);
	return(quit_scene(&scene, 0));
}
