/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:28:11 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/03 18:59:33 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTATIONS_H
# define COMPUTATIONS_H

# include "tuples.h"
# include "rays.h"
# include "shapes.h"
# include "world.h"
# include "colors.h"

typedef struct s_comp {
	double      t;
    t_shape     object;
	t_tuple		point;
    t_tuple     normalv;
	t_tuple     eyev;
    bool		inside;
}	t_comp;

t_comp prepare_computations(t_hit *intersection, t_ray *ray);
t_color shade_hit(t_world *w, t_comp *comps);
t_color color_at(t_world *w, t_ray *r);

#endif