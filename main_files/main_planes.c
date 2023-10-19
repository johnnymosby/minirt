/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_planes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/19 19:31:36 by aguilmea         ###   ########.fr       */
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

static t_matrix	set_transform_for_second_scene_wall(bool is_left_wall)
{
	t_matrix	m_translated;
	t_matrix	m_rotated_y;
	t_matrix	m_rotated_x;
	t_matrix	m_scaled;
	t_matrix	result;

	m_translated = translation(0, 0, 5);
	if (is_left_wall)
		m_rotated_y = rotation_y(-M_PI_4);
	else
		m_rotated_y = rotation_y(M_PI_4);
	m_rotated_x = rotation_x(M_PI_2);
	m_scaled = scaling(10, 0.01, 10);
	result = multiply_matrices(&m_translated, &m_rotated_y);
	result = multiply_matrices(&result, &m_rotated_x);
	result = multiply_matrices(&result, &m_scaled);
	return (result);
}

static t_matrix	set_right_sphere(void)
{
	t_matrix	m_translated;
	t_matrix	m_scaled;
	t_matrix	result;

	m_translated = translation(1.5, 0.5, -0.5);
	m_scaled = scaling(0.5, 0.5, 0.5);
	result = multiply_matrices(&m_translated, &m_scaled);
	return (result);
}

static t_matrix	set_left_sphere(void)
{
	t_matrix	m_translated;
	t_matrix	m_scaled;
	t_matrix	result;

	m_translated = translation(-1.5, 0.33, -0.75);
	m_scaled = scaling(0.33, 0.33, 0.33);
	result = multiply_matrices(&m_translated, &m_scaled);
	return (result);
}

void	fake_parser(t_scene *scene)
{
	t_matrix m_transform;
	
	//shapes
	scene->world->shape = ft_calloc(6, sizeof(t_shape));
	scene->world->nb_shapes = 6;
	
		//shape[0] = plane
	scene->world->shape[0] = create_plane();
	scene->world->shape[0].transform = scaling(10.00, 0.01, 10.0);
	scene->world->shape[0].material.color = color(1, 0.9, 0.9);

		//shape[1] = plane
	scene->world->shape[1] = create_plane();
	m_transform = set_transform_for_second_scene_wall(true);
	set_transform(scene->world->shape + 1, &m_transform);
	scene->world->shape[1].material = scene->world->shape[0].material;

		//shape[2] = plane
	scene->world->shape[2] = create_plane();
	scene->world->shape[2] = create_sphere();
	m_transform = set_transform_for_second_scene_wall(false);
	set_transform(scene->world->shape + 2, &m_transform);
	scene->world->shape[2].material = scene->world->shape[0].material;

		//shape[3] = sphere
	scene->world->shape[3] = create_sphere();
	m_transform = translation(-0.5, 1, 0.5);
	set_transform(scene->world->shape + 3, &m_transform);
	scene->world->shape[3].material.color = color(0.1, 1, 0.5);
	scene->world->shape[3].material.diffuse = 0.7;
	scene->world->shape[3].material.specular = 0.3;

			//shape[4] = sphere
	scene->world->shape[4] = create_sphere();
	m_transform = set_right_sphere();
	set_transform(scene->world->shape + 4, &m_transform);
	scene->world->shape[4].material.color = color(0.5, 1, 0.1);
	scene->world->shape[4].material.diffuse = 0.7;
	scene->world->shape[4].material.specular = 0.3;

			//shape[5] = sphere
	scene->world->shape[5] = create_sphere();
	m_transform = set_left_sphere();
	set_transform(scene->world->shape + 5, &m_transform);
	scene->world->shape[5].material.color = color(1, 0.8, 0.1);
	scene->world->shape[5].material.diffuse = 0.7;
	scene->world->shape[5].material.specular = 0.3;

	//lights
	t_tuple	light_position;
	t_color	light_color;
	light_position = point(-10, 10, -10);
	light_color = color(1, 1, 1);
	scene->world->lights = ft_calloc(1, sizeof(t_light));
	scene->world->nb_lights = 1;
	scene->world->lights[0] = point_light(&light_color, &light_position);
	
	//camera
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	scene->camera = camera(PCT_WIDTH, WIN_HEIGHT, M_PI / 3);
	from = point(0, 1, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	scene->camera.transform = view_transform(&from, &to, &up);
	scene->camera.inverse = inverse(&scene->camera.transform);
	scene->camera.original_transform = scene->camera.transform;
	
	//camera
	scene->world->lightning.material = ft_calloc(1, sizeof(t_material));
}
int	main(int argc, char **argv)
{
	t_scene		scene;
	t_win		win;
	t_world		world;
	t_controls	controls;

	(void) argv;
	(void) argc;
	set_controls(&controls, &scene);
	scene.canvas = NULL;
	scene.world = &world;
	fake_parser(&scene);
	if (render(&scene) == false)
		return(quit_scene(&scene, ERR_MEMORY_ALLOCATION));
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
