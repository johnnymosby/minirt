/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:09:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/22 13:51:02 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "libft.h"
# include "shapes.h"
# include "rays.h"
# include "light.h"

typedef struct s_world
{
	t_hit		*xs;
	t_light		*lights;
	t_lightning	lightning;
	t_shape		*shape;
	int			nb_lights;
	int			nb_shapes;
}	t_world;

t_world		default_world(void);
t_hit		*intersect_world(t_world *w, t_ray *ray);
t_matrix	view_transform(t_tuple *from, t_tuple *to, t_tuple *up);

#endif