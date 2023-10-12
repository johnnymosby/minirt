/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:26:37 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 17:27:23 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

void	rerender(t_scene *scene)
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

