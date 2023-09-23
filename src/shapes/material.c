/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:27:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/23 18:52:44 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	set_material_to_default(t_material *material)
{
	material->ambient = 0.1;
	material->diffuse = 0.9;
	material->specular = 0.9;
	material->shininess = 200.0;
	material->color = color(1, 1, 1);
}

bool	are_equal_materials(t_material *mtrl1, t_material *mtrl2)
{
	if (are_equal_doubles(mtrl1->ambient, mtrl2->ambient) == false)
		return (false);
	else if (are_equal_doubles(mtrl1->diffuse, mtrl2->diffuse) == false)
		return (false);
	else if (are_equal_doubles(mtrl1->specular, mtrl2->specular) == false)
		return (false);
	else if (are_equal_doubles(mtrl1->shininess, mtrl2->shininess) == false)
		return (false);
	else
		return (true);
}
