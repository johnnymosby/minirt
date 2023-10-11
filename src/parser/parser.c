/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/11 18:10:56 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	allocates memory to w->lights, w->shape, w->lightning.material
*/
static bool	allocate_shapes_lights_lightning(t_world *w)
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
	w->lightning.material = ft_calloc(1, sizeof(t_material));
	if (w->lightning.material == NULL)
		return (false);
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
/*
	allocates memory to:
		w->lightning.material (put_elements_into_lightning > put_ambient_into_lightning)
*/
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
		{	
		//	printf("****i:%d******\n", i);
			put_elements_into_camera (elmts + i, cam);
		}
		else if (elmts[i].element_type == ELMT_AMBIENT)
		{
		//	printf("****i:%d******\n", i);
			put_elements_into_lightning (elmts + i, 0, w);
		}
		else if (elmts[i].element_type == ELMT_LIGHT)
		{	
		//	printf("****i:%d******index light:%d****\n", i, index_lights);
			put_elements_into_lightning (elmts + i, index_lights, w);
			index_lights++;
		}
		else
		{	
		//	printf("****i:%d******index shape:%d****\n", i, index_shapes);
			put_elements_into_shapes (elmts + i, index_shapes, w);
			index_shapes++;
		}
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
	if (allocate_shapes_lights_lightning(w) == false)
	{	
		free(elmts);
		return (false);
	}
	put_elements_into_world_and_camera(elmts, nb_elmts, w, cam);
	free(elmts);
	return (true);
}
