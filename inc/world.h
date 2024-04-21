/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:09:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/24 16:33:18 by rbasyrov         ###   ########.fr       */
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

t_hit		*intersect_world(t_world *w, t_ray *ray);
t_matrix	view_transform(t_tuple *from, t_tuple *to, t_tuple *up);

#endif