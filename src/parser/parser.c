/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 17:38:01 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	allocate_shapes_lights_lightning(t_world *w)
{
	w->lights = ft_calloc(w->nb_lights, sizeof(t_light));
	if (w->lights == NULL)
		return (print_error(NULL, -1, ERR_MALLOC, ERR_LIGHT));
	w->shape = ft_calloc(w->nb_shapes, sizeof(t_shape));
	if (w->shape == NULL)
		return (print_error(NULL, -1, ERR_MALLOC, ERR_SHAPES));
	w->lightning.material = ft_calloc(1, sizeof(t_material));
	if (w->lightning.material == NULL)
		return (print_error(NULL, -1, ERR_MALLOC, ERR_LIGHTNING));
	return (0);
}

static int	check_nb_elements(t_element *elmts, int nb_elmts, t_world *w)
{
	int		i;
	int		nb[3];

	i = 0;
	ft_bzero(nb, sizeof(nb));
	while (i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_AMBIENT)
			nb[ELMT_AMBIENT]++;
		else if (elmts[i].element_type == ELMT_CAMERA)
			nb[ELMT_CAMERA]++;
		else if (elmts[i].element_type == ELMT_LIGHT)
			nb[ELMT_LIGHT]++;
		i++;
	}
	if (nb[ELMT_AMBIENT] != 1 || nb[ELMT_CAMERA] != 1 || nb[ELMT_LIGHT] != 1)
		return (print_error(NULL, -1, ERR_NB_MANDATORY_ELMTS, 0));
	w->nb_shapes = nb_elmts - 3;
	w->nb_lights = 1;
	return (0);
}

static int	put_elements_into_scene(t_element *el, int nb, t_scene *scene)
{
	int	i;
	int	index_lights;
	int	index_shapes;

	i = -1;
	index_lights = -1;
	index_shapes = -1;
	while (++i < nb)
	{
		if (el[i].element_type == ELMT_CAMERA)
			put_elements_into_camera (el + i, &scene->camera);
		else if (el[i].element_type == ELMT_LIGHT)
			put_elements_into_light (el + i, ++index_lights, scene->world);
		else if (el[i].element_type == ELMT_PLANE || el[i].element_type
			== ELMT_SPHERE || el[i].element_type == ELMT_CYLINDER)
			put_elements_into_shapes (el + i, ++index_shapes, scene->world);
	}
	i = -1;
	while (++i < nb)
	{
		if (el[i].element_type == ELMT_AMBIENT)
			put_elements_into_ambient (el + i, scene->world);
	}
	free(el);
	return (0);
}

t_element	*count_elements(char *file_string, int *nb)
{
	char		*tmp;
	t_element	*el;

	tmp = file_string;
	while (*tmp == '\n')
		tmp++;
	while (*tmp != '\0')
	{
		if (tmp != file_string
			&& *tmp == '\n' && *(tmp +1) != '\n' && *(tmp +1) != '\0')
			(*nb)++;
		tmp++;
	}
	if (file_string != tmp && *tmp -1 != '\n')
		(*nb)++;
	el = ft_calloc(*nb, sizeof(t_element));
	if (el == NULL)
		free (file_string);
	return (el);
}

int	parser(char *filename, t_scene *scene)
{
	char		*file_string;
	t_element	*elmts;
	int			nb_elmts;
	int			ret;

	nb_elmts = 0;
	ret = 0;
	file_string = put_file_into_string(filename, &ret);
	if (file_string == NULL)
		return (print_error(NULL, -1, ret, 0));
	elmts = count_elements(file_string, &nb_elmts);
	if (elmts == NULL)
		return (print_error(NULL, -1, ERR_MALLOC, ERR_ELEMENTS));
	ret = get_elements(file_string, &nb_elmts, elmts);
	free(file_string);
	if (ret != 0)
	{
		free (elmts);
		return (ret);
	}
	if (check_nb_elements(elmts, nb_elmts, scene->world) == 0
		&& allocate_shapes_lights_lightning(scene->world) == 0)
		return (put_elements_into_scene(elmts, nb_elmts, scene));
	free (elmts);
	return (-1);
}
