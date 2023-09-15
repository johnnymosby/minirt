/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:49:06 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 18:59:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "matrices.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

t_ray	ray(t_tuple point, t_tuple direction);

#endif