/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/16 18:47:55 by aguilmea         ###   ########.fr       */
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
		ft_putstr_fd("Error\nError in the memory allocation of lights\n", 2);
		return (ERR_MALLOC);
	}
	w->shape = ft_calloc(w->nb_shapes, sizeof(t_shape));
	if (w->shape == NULL)
	{
		ft_putstr_fd("Error\nError in the memory allocation of shapes\n", 2);
		free(w->lights);
		return (ERR_MALLOC);
	}
	w->lightning.material = ft_calloc(1, sizeof(t_material));
	if (w->lightning.material == NULL)
	{
		ft_putstr_fd("Error\nError in the memory allocation of lightning\n", 2);
		free(w->lights);
		free(w->shape);
		return (ERR_MALLOC);
	}
	return (0);
}

static int	check_nb_elements(t_element *elmts, int nb_elmts, t_world *w)
{
	int		i;
	int		nb[3];

	i = -1;
	ft_bzero(nb, sizeof(nb));
	while (++i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_AMBIENT)
			nb[ELMT_AMBIENT]++;
		else if (elmts[i].element_type == ELMT_CAMERA)
			nb[ELMT_CAMERA]++;
		else if (elmts[i].element_type == ELMT_LIGHT)
			nb[ELMT_LIGHT]++;
	}
	if (nb[ELMT_AMBIENT] != 1 || nb[ELMT_CAMERA] != 1 || nb[ELMT_LIGHT] != 1)
	{
		print_error_parsing(NULL, 0, ERR_NB_MANDATORY_ELMTS);
		return (ERR_NB_MANDATORY_ELMTS);
	}
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

static bool	put_elements_into_scene(t_element *elmts, int nb_elmts, t_scene *scene)
{
	int	i;
	int	index_lights;
	int	index_shapes;

	i = -1;
	index_lights = -1;
	index_shapes = -1;
	while (++i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_CAMERA)
			put_elements_into_camera (elmts + i, &scene->camera);
		else if (elmts[i].element_type == ELMT_AMBIENT)
			put_elements_into_lightning (elmts + i, 0, scene->world);
		else if (elmts[i].element_type == ELMT_LIGHT)
			put_elements_into_lightning (elmts + i, ++index_lights, scene->world);
		else
			put_elements_into_shapes (elmts + i, ++index_shapes, scene->world);
	}
	return (true);
}
static int	free_elements(t_element *elmmts, int err_code)
{
	free (elmmts);
	return (err_code);
}


int	parser(char *filename, t_scene *scene)
{
	char		*file_string;
	t_element	*elmts;
	int			nb_elmts;
	int			ret;

	file_string = put_file_into_string(filename, &ret);
	if (ret != 0)
		return (ret);
	elmts = NULL;
	ret = get_elements(file_string, &nb_elmts, elmts);
	free(file_string);
	if (ret != 0)
		return (ret);
	if (check_nb_elements(elmts, nb_elmts, scene->world) != 0)
		return (free_elements(elmts, ERR_NB_MANDATORY_ELMTS));
	if (allocate_shapes_lights_lightning(scene->world) != 0)
		return (free_elements(elmts, ERR_MALLOC));
	put_elements_into_scene(elmts, nb_elmts, scene);
	free(elmts);
	return (0);
}
