/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 13:39:56 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	allocates memory to w->lights, w->shape, w->lightning.material
*/
static int	allocate_shapes_lights_lightning(t_world *w)
{
	w->lights = ft_calloc(w->nb_lights, sizeof(t_light));
	if (w->lights == NULL)
	{
		ft_putstr_fd("Error in the memory allocation of the lights\n", 2);
		return (ERR_MALLOC);
	}
	w->shape = ft_calloc(w->nb_shapes, sizeof(t_shape));
	if (w->shape == NULL)
	{
		ft_putstr_fd("Error in the memory allocation of the shapes\n", 2);
		free(w->lights);
		return (ERR_MALLOC);
	}
	w->lightning.material = ft_calloc(1, sizeof(t_material));
	if (w->lightning.material == NULL)
	{
		ft_putstr_fd("Error in the memory allocation of the shapes\n", 2);
		return (ERR_MALLOC);
	}
	return (ERR_MALLOC);
}

static int	check_nb_elements(t_element *elmts, int nb_elmts, t_world *w)
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
		return (NUMBER_MANDATORY_ELEMENTS_WRONG);
	w->nb_shapes = nb_elmts - 3;
	w->nb_lights = 1;
	return (0);
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
		return (NUMBER_MANDATORY_ELEMENTS_WRONG);
	w->nb_shapes = nb_elmts - 2 - nb_l;
	w->nb_lights = nb_l;
	return (0);
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
	while (i++ < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_CAMERA)
			put_elements_into_camera (elmts + i, cam);
		else if (elmts[i].element_type == ELMT_AMBIENT)
			put_elements_into_lightning (elmts + i, 0, w);
		else if (elmts[i].element_type == ELMT_LIGHT)
		{
			put_elements_into_lightning (elmts + i, index_lights, w);
			index_lights++;
		}
		else
		{
			put_elements_into_shapes (elmts + i, index_shapes, w);
			index_shapes++;
		}
	}
	return (true);
}

bool	parser(char *filename, t_world *w, t_camera *cam)
{
	char		*file_string;
	t_element	*elmts;
	int			nb_elmts;

	file_string = put_file_into_string(filename);
	if (file_string == NULL)
		return (false);
	elmts = get_elements(file_string, &nb_elmts);
	free(file_string);
	if (elmts == NULL)
		return (false);
	if (check_nb_elements(elmts, nb_elmts, w) != 0)
	{
		free (elmts);
		return (false);
	}
	if (allocate_shapes_lights_lightning(w) != 0)
	{
		free(elmts);
		return (false);
	}
	put_elements_into_world_and_camera(elmts, nb_elmts, w, cam);
	free(elmts);
	return (true);
}
