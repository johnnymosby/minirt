/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:04:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/23 18:40:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "colors.h"

typedef struct s_light
{
	t_color	intensity;
	t_tuple	position;
}	t_light;

typedef struct s_material	t_material;

typedef struct s_lightning
{
	t_material	*material;
	t_light		*light;
	t_tuple		*point;
	t_tuple		*eyev;
	t_tuple		*normalv;
}	t_lightning;

/*
** ------------------------------- LIGHT -------------------------------------
*/

t_light	point_light(t_color *intensity, t_tuple *position);
t_color	lightning(t_lightning *data);

#endif