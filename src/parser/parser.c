/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/10 20:00:38 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	allocate_shapes_and_lights(t_world *w)
{
	w->lights = ft_calloc(w->nb_lights, sizeof(t_light));
	if (w->lights == NULL)
		return (false);
	w->shape = ft_calloc(w->nb_shapes, sizeof(t_shape));
	if (w->shape == NULL)
	{
		free(w->lights);
		return (false);
	}
	return (true);
}

static bool	check_nb_elements(t_element *elmts, int nb_elmts, t_world *w)
{
	int		i;
	int		nb_a;
	int		nb_c;
	int		nb_l;

	i = 0;
	nb_a = 0;
	nb_c = 0;
	nb_l = 0;
	while (i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_AMBIENT)
			nb_a++;
		else if (elmts[i].element_type == ELMT_CAMERA)
			nb_c++;
		else if (elmts[i].element_type == ELMT_LIGHT)
			nb_l++;
		i++;
	}
	if (nb_a != 1 || nb_c != 1 || nb_l != 1)
		return (false);
	w->nb_shapes = nb_elmts - 3;
	w->nb_lights = 1;
	return (true);
}
/*
	[BONUS]
static bool	check_nb_elements(t_element *elmts, int nb_elmts, t_world *w)
{
	int		i;
	int		nb_a;
	int		nb_c;
	int		nb_l;

	i = 0;
	nb_a = 0;
	nb_c = 0;
	nb_l = 0;
	while ( i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_CAMERA)
			nb_c++;
		else if (elmts[i].element_type == ELMT_AMBIENT)
			nb_a++;
		else if (elmts[i].element_type == ELMT_LIGHT)
			nb_l++;
		i++;
	}
	if (nb_a != 1 || nb_c != 1)
		return (false);
	w->nb_shapes = nb_elmts - 2 - nb_l;
	w->lightning.light = ft_calloc(nb_l, sizeof(t_light)); 
	if (lightning == NULL)
		return (false);
	// I need to write somewhere how many lights there are
	return (true);
}*/

static bool	put_elements_into_world_and_camera(t_element *elmts, \
	int nb_elmts, t_world *w, t_camera *cam)
{
	int	i;
	int	index_lights;
	int	index_shapes;

	i = 0;
	index_lights = 0;
	index_shapes = 0;
	while (i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_CAMERA)
			put_elements_into_camera (elmts + i, cam);
		else if (elmts[i].element_type == ELMT_AMBIENT \
			&& put_elements_into_lightning (elmts + i, 0, w) == false)
			return (false);
		else if (elmts[i].element_type == ELMT_LIGHT)
			put_elements_into_lightning (elmts + i, index_lights++, w);
		else
			put_elements_into_shapes (elmts + i, index_shapes++, w);
		i++;
	}
	return (true);
}

bool	parser(char *filename, t_world *w, t_camera *cam)
{
	char		*file_string;
	t_element	*elmts;
	int			nb_elmts;

	ft_bzero(w, sizeof (t_world));
	ft_bzero(cam, sizeof (t_world));
	file_string = put_file_into_string(filename);
	if (file_string == NULL)
		return (false);
	elmts = get_elements(file_string, &nb_elmts);
	free(file_string);
	if (elmts == NULL)
		return (false);
	if (check_nb_elements(elmts, nb_elmts, w) == false)
	{
		free (elmts);
		return (false);
	}
	if (allocate_shapes_and_lights(w) == false)
	{	
		free(elmts);
		return (false);
	}
	put_elements_into_world_and_camera(elmts, nb_elmts, w, cam);
	free(elmts);
	return (true);
}
