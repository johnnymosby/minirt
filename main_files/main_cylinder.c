/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/18 13:26:46 by aguilmea         ###   ########.fr       */
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

#define ERR_MEMORY_ALLOCATION	-1
#define ERR_MLX_FUNCTION		-2


static void	parse_scene3(t_world *w)
{
	t_tuple	light_position;
	t_color	light_color;

	light_position = point(-10, 10, -10);
	light_color = color(1, 1, 1);
	w->shape = ft_calloc(1, sizeof(t_shape));
	w->shape[0] = create_cylinder();
	w->shape[0].material.color = color(1, 0.2, 1);
	w->nb_shapes = 1;
	w->nb_lights = 1;
	w->lights = ft_calloc(1, sizeof(t_light));
	w->lights[0] = point_light(&light_color, &light_position);
}

static t_camera	set_camera(void)
{
	t_camera	cam;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	cam = camera(PCT_WIDTH, WIN_HEIGHT, M_PI / 3);
	from = point(0, 1, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	cam.transform = view_transform(&from, &to, &up);
	cam.inverse = inverse(&cam.transform);
	cam.original_transform = cam.transform;
	return (cam);
}

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
static int	quit_scene(t_scene *scene, int err_code)
{
	if (scene && scene->canvas && scene->canvas->win)
	{
		if (scene->canvas->win->menu.img_ptr != NULL)
			mlx_destroy_image(scene->canvas->win->mlx_ptr, scene->canvas->win->menu.img_ptr);
		if (scene->canvas->win->pct.img_ptr != NULL)
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

int	main(void)
{
	t_win		win;
	t_world		w;
	t_scene		scene;
	t_controls	controls;

	set_controls(&controls, &scene);
	scene.canvas = NULL;
	scene.camera = set_camera();
	parse_scene3(&w);
	scene.world = &w;
	if (render(&scene) == false)
		return (ERR_MEMORY_ALLOCATION);
	w.lightning.material = ft_calloc(1, sizeof(t_material));
	if (initialise_mlx(&win) == false)
		return(quit_scene(&scene, ERR_MLX_FUNCTION));
	scene.canvas->win = &win;
	canvas_to_mlx_image(scene.canvas, win.pct.addr);
	render_menu(scene.canvas->win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	catch_close_hooks(&win);
	mlx_key_hook(win.win_ptr, pressed_key, &controls);
	mlx_mouse_hook(win.win_ptr, mouse_hook, &controls);
	mlx_loop(win.mlx_ptr);
	return(quit_scene(&scene, 0));
}
