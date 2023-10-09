/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/09 16:17:29 by rbasyrov         ###   ########.fr       */
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




/* static t_matrix	set_transform_for_second_scene_wall(bool is_left_wall)
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


static void	parse_scene2(t_world *w)
{
	t_matrix m_transform;
	w->shape = ft_calloc(6, sizeof(t_shape));
	w->nb_shapes = 6;
	// floor
	w->shape[0] = create_sphere();
	m_transform = scaling(10, 0.01, 10);
	set_transform(w->shape + 0, &m_transform);
	w->shape[0].material.color = color(1, 0.9, 0.9);
	w->shape[0].material.specular = 0;
	// left wall
	w->shape[1] = create_sphere();
	m_transform = set_transform_for_second_scene_wall(true);
	set_transform(w->shape + 1, &m_transform);
	w->shape[1].material = w->shape[0].material;
	// right wall
	w->shape[2] = create_sphere();
	m_transform = set_transform_for_second_scene_wall(false);
	set_transform(w->shape + 2, &m_transform);
	w->shape[2].material = w->shape[0].material;
	// middle
	w->shape[3] = create_sphere();
	m_transform = translation(-0.5, 1, 0.5);
	set_transform(w->shape + 3, &m_transform);
	w->shape[3].material.color = color(0.1, 1, 0.5);
	w->shape[3].material.diffuse = 0.7;
	w->shape[3].material.specular = 0.3;
	// right
	w->shape[4] = create_sphere();
	m_transform = set_right_sphere();
	set_transform(w->shape + 4, &m_transform);
	w->shape[4].material.color = color(0.5, 1, 0.1);
	w->shape[4].material.diffuse = 0.7;
	w->shape[4].material.specular = 0.3;
	// left
	w->shape[5] = create_sphere();
	m_transform = set_left_sphere();
	set_transform(w->shape + 5, &m_transform);
	w->shape[5].material.color = color(1, 0.8, 0.1);
	w->shape[5].material.diffuse = 0.7;
	w->shape[5].material.specular = 0.3;
	w->lights = ft_calloc(1, sizeof(t_light));
	w->nb_lights = 1;
	t_tuple	light_position;
	t_color	light_color;

	light_position = point(-10, 10, -10);
	light_color = color(1, 1, 1);
	w->lights[0] = point_light(&light_color, &light_position);
} */


/* 
int	main(void)
{
	t_canvas	*c;
	t_win		win;
	t_world		w;
	t_camera	cam;

	w.xs = NULL;
	w = default_world();
	// parse_scene2(&w);
	cam = set_camera();
	c = render(&cam, &w);
	if (c == NULL)
		return (ERR_MEMORY_ALLOCATION);
	if (initialise_mlx(&win) == false)
	{
		free_canvas(c);
		free(w.lights);
		free(w.shape);
		return (ERR_MLX_FUNCTION);
	}
	// render_sphere(&w, c);
	catch_mlx_hooks(&win);
	canvas_to_mlx_image(c, win.pct.addr);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	mlx_loop(win.mlx_ptr);
	free_canvas(c);
	free(w.lights);
	free(w.shape);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	return (0);
} */
static void	parse_scene(t_world *w)
{
	t_tuple	light_position;
	t_color	light_color;

	light_position = point(-10, 10, -10);
	light_color = color(1, 1, 1);
	w->shape = ft_calloc(1, sizeof(t_shape));
	w->shape[0] = create_sphere();
	w->shape[0].material.color = color(1, 0.2, 1);
	w->nb_shapes = 1;
	w->nb_lights = 1;
	w->lights = ft_calloc(1, sizeof(t_light));
	w->lights[0] = point_light(&light_color, &light_position);
}
/* static t_camera	set_camera(void)
{
	t_camera	cam;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	from = point(0, 0, -15);
	to = point(0, 0, 0);
	up = vector(0, 0, -1);
	cam = camera(PCT_WIDTH, WIN_HEIGHT, M_PI*100);
	cam.transform = view_transform(&from, &to, &up);
	set_transform_in_camera(&cam, &cam.transform);
	return (cam);
} */
static void	render_sphere(t_world *w, t_canvas *c)
{
	t_ray	r;
	t_tuple	origin;
	int		y;
	int		x;
	double	world_y;
	double	world_x;
	double	wall_z;
	t_tuple	positioned;
	t_tuple pos_minus_origin;
	t_tuple	normalized;
	t_hit	*h;
	t_tuple pos;
	t_tuple normal;
	t_tuple eye;
	wall_z = 100;
	origin = point(0, 0, -5);
	// t_camera	cam = set_camera();

	// r = ray_for_pixel(&cam, 0,0);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		world_y = WIN_HEIGHT / 2 - y;
		x = 0;
		while (x < PCT_WIDTH)
		{
			world_x = -1 * PCT_WIDTH / 2 + x;
			positioned = point(world_x, world_y, wall_z);
			pos_minus_origin = substract_tuples(&positioned, &origin);
			normalized = normalize(&pos_minus_origin);
			r = ray(&origin, &normalized);
			// r = ray_for_pixel(&cam, x, y);
			w->xs = NULL;
			intersect(w->shape, &r, &w->xs);
			h = hit(w->xs, true);
			if (h != NULL)
			{
				pos = position(&r, h->t);
				normal = normal_at_sphere(h->obj, &pos);
				eye = negate_tuple(&r.direction);
				// t_comp comps = prepare_computations(h, &r);
				// w->lightning.light = w->lights;
				// w->lightning.material = &comps.object.material;
				// w->lightning.point = &comps.point;
				// w->lightning.eyev = &comps.eyev;
				// w->lightning.normalv = &comps.normalv;
				// write_pixel(c, x, y, shade_hit(w, &comps));
				// write_pixel(c, x, y, lightning(&w->lightning));
				write_pixel(c, x, y, color_at(w, &r));
			}
			x++;
		}
		y++;
	}
}

int	main(void)
{
	t_canvas	*c;
	t_win		win;
	t_world		w;

	w.xs = NULL;
	// w = default_world();
	parse_scene(&w);
	c = canvas(PCT_WIDTH, WIN_HEIGHT);
	// c = render(&cam, &w);
	if (c == NULL)
		return (ERR_MEMORY_ALLOCATION);
	if (initialise_mlx(&win) == false)
	{
		free_canvas(c);
		free(w.lights);
		free(w.shape);
		return (ERR_MLX_FUNCTION);
	}
	render_sphere(&w, c);
	catch_mlx_hooks(&win);
	canvas_to_mlx_image(c, win.pct.addr);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	mlx_loop(win.mlx_ptr);
	free_canvas(c);
	free(w.lights);
	free(w.shape);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	return (0);
}