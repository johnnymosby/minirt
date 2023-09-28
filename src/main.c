/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/28 19:23:18 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "colors.h"
#include "canvas.h"
#include "shapes.h"
#include "light.h"
#include "world.h"

#define ERR_MEMORY_ALLOCATION	-1
#define ERR_MLX_FUNCTION		-2

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
	t_tuple	light_position = point(-10, 10, -10);
	t_color light_color = color(1, 1, 1);
	t_hit	*h;
	t_tuple pos;
	t_tuple normal;
	t_tuple eye;
	t_color col;
	
	wall_z = 1000;
	origin = point(0, 0, -5);

	w->shape = ft_calloc(1, sizeof(t_shape));
	w->shape[0] = create_sphere();
	w->shape[0].material.color = color(1, 0.2, 1);

	w->lightning.light = ft_calloc(1, sizeof(t_light));

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
			w->xs = NULL;
			intersect(w->shape, &r, &w->xs);
			h = hit(w->xs, false);
			if (h != NULL)
			{
				pos = position(&r, h->t);
				normal = normal_at_sphere(h->obj, &pos);
				eye = negate_tuple(&r.direction);
				w->lightning.material = &h->obj->material;
				*w->lightning.light = point_light(&light_color, &light_position);
				w->lightning.point = &pos;
				w->lightning.eyev = &eye;
				w->lightning.normalv = &normal;
				col = lightning(&w->lightning);
				write_pixel(c, x, y, col);
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

	c = canvas(PCT_WIDTH, WIN_HEIGHT);
	if (c == NULL)
		return (ERR_MEMORY_ALLOCATION);
	if (initialise_mlx(&win) == false)
	{
		free_canvas(c);
		return (ERR_MLX_FUNCTION);
	}
	render_sphere(&w, c);
	catch_mlx_hooks(&win);
	canvas_to_mlx_image(c, win.pct.addr);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	mlx_loop(win.mlx_ptr);
	free_canvas(c);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	return (0);
}

// int	main(void)
// {
// 	t_tuple	p = point(0, 0, -5);
// 	t_tuple	v = vector(0, 0, 1);
// 	t_ray r = ray(&p, &v);
// 	t_shape sph = create_sphere();
// 	t_hit xs = intersect_sphere(&sph, &r);
// }