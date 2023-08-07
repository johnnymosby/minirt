/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:47:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/07 23:58:01 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	*canvas(int width, int height)
{
	t_canvas	*canvas;
	t_color		*pixels;

	pixels = ft_calloc(width * height, sizeof(t_color));
	if (pixels == NULL)
		return (NULL);
	canvas = ft_calloc(1, sizeof(t_canvas));
	if (canvas == NULL)
	{
		free(pixels);
		return (NULL);
	}
	canvas->pixels = pixels;
	canvas->width = width;
	canvas->height = height;
	return (canvas);
}
