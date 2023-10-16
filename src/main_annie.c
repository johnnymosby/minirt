/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/16 12:05:19 by aguilmea         ###   ########.fr       */
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
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

static void	quit_scene(t_scene *scene)
{
	if (scene->canvas->win->menu.img_ptr)
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
	if (scene->canvas)
		free_canvas(scene->canvas);
	if (scene->world->lightning.material)
		free (scene->world->lightning.material);
	if (scene->world->lights)
		free(scene->world->lights);
	if (scene->world->shape)
		free(scene->world->shape);
}

int	main(void)
{
	t_win		win;
	t_world		w;
	t_scene		scene;
	t_controls	controls;

	set_controls(&controls, &scene);
	scene.world = &w;
	scene.canvas = canvas(PCT_WIDTH, WIN_HEIGHT);
	scene.canvas->win = &win;
	if (parser("testfiles/full_files/subject_only_one_sphere.rt", &scene) == false)
		return (false);
	if (render(&scene) == false)
		return (ERR_MEMORY_ALLOCATION);
	if (initialise_mlx(&win) == false)
	{
		quit_scene(&scene);
		return (ERR_MLX_FUNCTION);
	}
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	catch_close_hooks(scene.canvas->win);
	//mlx_key_hook(win.win_ptr, pressed_key, &controls);
	//mlx_mouse_hook(win.win_ptr, mouse_hook, &controls);
	mlx_loop(win.mlx_ptr);
	quit_scene(&scene);
	return (0);
}
