/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/23 18:38:45 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "colors.h"
#include "canvas.h"
#include "shapes.h"

#define ERR_MEMORY_ALLOCATION	-1
#define ERR_MLX_FUNCTION		-2

static void	render_sphere(t_canvas *c)
{
	t_shape	s;
	t_ray	r;
	t_tuple	origin;
	int		y;
	int		x;
	double	world_y;
	double	world_x;
	double	wall_z;
	t_tuple	position;
	t_tuple pos_minus_origin;
	t_tuple	normalized;
	t_hit	*xs;
	t_color		red;

	red = color(1, 0, 0);
	wall_z = 1000;
	origin = point(0, 0, -5);
	s = create_sphere();
	y = 0;
	while (y < WIN_HEIGHT)
	{
		world_y = WIN_HEIGHT / 2 - y;
		x = 0;
		while (x < PCT_WIDTH)
		{
			world_x = -1 * PCT_WIDTH / 2 + x;
			// (void);
			// (void);
			// (void);
			position = point(world_x, world_y, wall_z);
			pos_minus_origin = substract_tuples(&position, &origin);
			normalized = normalize(&pos_minus_origin);
			r = ray(&origin, &normalized);
			xs = NULL;
			intersect(&s, &r, &xs);
			if (hit(xs, false) != NULL)
				write_pixel(c, x, y, red);
			x++;
		}
		y++;
	}

}

int	main(void)
{
	t_canvas	*c;
	t_win		win;
	

	if (initialise_mlx(&win) == false)
	{	
		free_canvas(c);
		return (ERR_MLX_FUNCTION);
	}
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