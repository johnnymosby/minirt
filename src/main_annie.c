/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/14 20:02:15 by aguilmea         ###   ########.fr       */
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


int	main(void)
{
	t_win		win;
	t_world		w;
	t_scene		scene;

	scene.canvas = NULL;
	if (parser("testfiles/full_files/subject_only_one_sphere.rt", &w, &scene.camera) == false)
		return (false);
	scene.world = &w;
	if (render(&scene) == false)
		return (ERR_MEMORY_ALLOCATION);
	if (initialise_mlx(&win) == false)
	{
		free_canvas(scene.canvas);
		free(w.lights);
		free(w.shape);
		return (ERR_MLX_FUNCTION);
	}
	scene.canvas->win = &win;
	canvas_to_mlx_image(scene.canvas, win.pct.addr);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
	catch_mlx_hooks(&win);
	mlx_mouse_hook(win.win_ptr, mouse_hook, &scene);
	//mlx_loop(win.mlx_ptr);
	free_canvas(scene.canvas);
	free(w.lights);
	free(w.shape);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	return (0);
}