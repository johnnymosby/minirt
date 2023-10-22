/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:04:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/22 13:22:35 by aguilmea         ###   ########.fr       */
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
	bool		in_shadow;
}	t_lightning;

typedef struct s_light_calc
{
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	lightv_neg;
	double	light_dot_normal;
}	t_light_calc;

typedef struct s_reflect_calc
{
	t_tuple	reflectv;
	double	reflect_dot_eye;
}	t_reflect_calc;

/*
** ------------------------------- LIGHT -------------------------------------
*/

t_light	point_light(t_color *intensity, t_tuple *position);
t_color	lightning(t_lightning *data);

#endif