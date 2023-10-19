/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:47:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/17 11:19:02 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	free_canvas(t_canvas *c)
{
	free (c->pixels);
	free (c);
	return ;
}

t_canvas	*canvas(int width, int height)
{
	t_canvas	*canvas;

	canvas = ft_calloc(1, sizeof(t_canvas));
	if (canvas == NULL)
		return (NULL);
	canvas->pixels = ft_calloc(width * height, sizeof(t_color));
	if (canvas->pixels == NULL)
	{	
		free(canvas);
		return (NULL);
	}
	canvas->width = width;
	canvas->height = height;
	return (canvas);
}
