/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:09:29 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/09 16:13:01 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static double	to_world_coordinate(t_camera *camera, double coordinate,
	bool is_x)
{
	double	offset;
	double	result;

	offset = (0.5 + coordinate) * camera->pixel_size;
	if (is_x == true)
		result = camera->half_width - offset;
	else
		result = camera->half_height - offset;
	return (result);
}

static void	calculate_pixel_point(t_camera *camera, t_tuple *pixel,
					double world_x, double world_y)
{
	t_tuple	p;

	p = point(world_x, world_y, -1);
	*pixel = multiply_matrix_by_tuple(&camera->inverse, &p);
}

static void	calculate_origin_point(t_camera *camera, t_tuple *origin)
{
	t_tuple	p;

	p = point(0, 0, 0);
	*origin = multiply_matrix_by_tuple(&camera->inverse, &p);
}

static void	calculate_direction(t_tuple *pixel, t_tuple *origin,
			t_tuple *direction)
{
	t_tuple	difference;

	difference = substract_tuples(pixel, origin);
	*direction = normalize(&difference);
}

t_ray	ray_for_pixel(t_camera *camera, int px, int py)
{
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	world_x = to_world_coordinate(camera, px, true);
	world_y = to_world_coordinate(camera, py, false);
	calculate_pixel_point(camera, &pixel, world_x, world_y);
	calculate_origin_point(camera, &origin);
	calculate_direction(&pixel, &origin, &direction);
	return (ray(&origin, &direction));
}
