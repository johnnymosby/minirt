/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:54:29 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 13:06:30 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static void	set_default_spheres(t_shape *s)
{
	t_matrix	m;

	s[0] = create_sphere();
	s[0].material.color = color(0.8, 1.0, 0.6);
	s[0].material.diffuse = 0.7;
	s[0].material.specular = 0.2;
	s[0].sphere.radius = 1;
	
	s[1] = create_sphere();
	m = scaling(0.5, 0.5, 0.5);
	set_transform(s+1, &m);
}

static void	set_default_light(t_light *l)
{
	t_color		intensity;
	t_tuple		position;
	
	intensity = color(1,1,1);
	position = point(-10, 10, -10);
	l[0] = point_light(&intensity, &position);
}

static void	set_world_to_default(t_world *w)
{
	t_light		*l = ft_calloc(1, sizeof(t_light));
	t_shape		*s = ft_calloc(2, sizeof(t_shape));
	
	set_default_light(l);
	set_default_spheres(s);
	w->lightning.light = l;
	w->shape = s;
	w->nb_shapes = 2;
}
t_world	default_world(void)
{
	t_world	w;

	set_world_to_default(&w);
	return (w);
}