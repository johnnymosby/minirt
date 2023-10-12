/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:00:25 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 16:20:26 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

static void	rerender(t_scene *scene)
{
	size_t		canvas_size;
	t_canvas	*canvas;

	canvas = scene->canvas;
	canvas_size = canvas->width * canvas->height * sizeof(t_color);
	ft_bzero(canvas->pixels, canvas_size);
	set_size_values(&scene->camera);
	render(scene);
	canvas_to_mlx_image(canvas, canvas->win->pct.addr);
	mlx_put_image_to_window(canvas->win->mlx_ptr, canvas->win->win_ptr,
		canvas->win->pct.img_ptr, 0, 0);
}

void	change_camera_zoom(int keycode, t_scene *scene)
{
	if (keycode == KEY_ZOOM_IN && scene->camera.field_of_view > -2.85)
	{
		scene->camera.field_of_view /= 1.1;
		rerender(scene);
	}
	else if (keycode == KEY_ZOOM_OUT
		&& scene->camera.field_of_view < 2.85)
	{
		scene->camera.field_of_view *= 1.1;
		rerender(scene);
	}
}

static t_shape	*find_clicked_shape(t_controls *controls, int x, int y)
{
	t_ray		r;
	t_camera	*c;
	t_hit		*hit;

	c = &controls->scene->camera;
	r = ray_for_pixel(c, x, y);
	hit = intersect_world(controls->scene->world, &r);
	while (hit && hit->t < 0)
		hit = hit->left;
	if (hit)
		return (hit->obj);
	else
		return (NULL);
}

static void	reset_to_default(t_controls *controls)
{
	if (controls->shape_in_control != NULL)
	{
		controls->shape_in_control->material.color
			= controls->shape_in_control->material.original_color;
		controls->shape_in_control = NULL;
		controls->state = DEFAULT;
	}
}

void	respond_to_left_click(t_controls *controls, int x, int y)
{
	t_shape	*shape;

	shape = find_clicked_shape(controls, x, y);
	if (shape != NULL && shape != controls->shape_in_control)
	{
		reset_to_default(controls);
		controls->shape_in_control = shape;
		controls->shape_in_control->material.original_color
			= controls->shape_in_control->material.color;
		controls->shape_in_control->material.color = color(1, 0, 0);
		controls->state = SHAPE_CHANGE;
	}
	else
	{
		reset_to_default(controls);
	}
	rerender(controls->scene);
}

void	respond_to_right_click(t_controls *controls)
{
	if (controls->shape_in_control != NULL)
	{
		reset_to_default(controls);
		rerender(controls->scene);
	}
	controls->state = DEFAULT;
}
