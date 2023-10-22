/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:31:37 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/22 13:23:21 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "shapes.h"

static void		calculate_for_lightning(t_light_calc *light_calc,
					t_lightning *data);
static void		calculate_for_reflect(t_reflect_calc *rflct_calc,
					t_lightning *data, t_light_calc *light_calc);
static t_color	calculate_return_color(t_color *ambient, t_color *diffuse,
					t_lightning *data, t_reflect_calc *rflct_calc);
static void		calculate_specular(t_color *specular, t_lightning *data,
					t_reflect_calc *rflct_calc);

t_color	lightning(t_lightning *data)
{
	t_color			ambient;
	t_color			diffuse;
	t_light_calc	light_calc;
	t_reflect_calc	rflct_calc;

	calculate_for_lightning(&light_calc, data);
	ambient = multiply_color_by_scalar(&light_calc.effective_color,
			data->material->ambient);
	if (light_calc.light_dot_normal < 0 || data->in_shadow == true)
		return (ambient);
	else
	{
		diffuse = multiply_color_by_scalar(&light_calc.effective_color,
				data->material->diffuse * light_calc.light_dot_normal);
		calculate_for_reflect(&rflct_calc, data, &light_calc);
		if (rflct_calc.reflect_dot_eye <= 0)
			return (add_colors(&ambient, &diffuse));
		else
			return (calculate_return_color(&ambient, &diffuse, data,
					&rflct_calc));
	}
}

static void	calculate_for_lightning(t_light_calc *light_calc,
		t_lightning *data)
{
	t_tuple			direction_to_light;

	light_calc->effective_color = multiply_colors(&data->material->color,
			&data->light->intensity);
	direction_to_light = substract_tuples(&data->light->position, data->point);
	light_calc->lightv = normalize(&direction_to_light);
	light_calc->light_dot_normal = dot(&light_calc->lightv, data->normalv);
}

static void	calculate_for_reflect(t_reflect_calc *rflct_calc,
	t_lightning *data, t_light_calc *light_calc)
{
	light_calc->lightv_neg = negate_tuple(&light_calc->lightv);
	rflct_calc->reflectv = reflect(&light_calc->lightv_neg, data->normalv);
	rflct_calc->reflect_dot_eye = dot(&rflct_calc->reflectv, data->eyev);
}

static t_color	calculate_return_color(t_color *ambient, t_color *diffuse,
	t_lightning *data, t_reflect_calc *rflct_calc)
{
	t_color			return_color;

	calculate_specular(&return_color, data, rflct_calc);
	return_color = add_colors(&return_color, ambient);
	return_color = add_colors(&return_color, diffuse);
	return (return_color);
}

static void	calculate_specular(t_color *specular, t_lightning *data,
	t_reflect_calc *rflct_calc)
{
	double	factor;

	factor = powf(rflct_calc->reflect_dot_eye, data->material->shininess);
	*specular = multiply_color_by_scalar(&data->light->intensity,
			data->material->specular * factor);
}
