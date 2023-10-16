/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_get_elements_from_string.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/16 15:05:54 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	set_one_element(char *file_string, int *index, t_element *element)
{
	if (ft_strncmp(file_string + *index, "A ", 2) == 0)
		return (parse_ambient(file_string, index, element));
	else if (ft_strncmp(file_string + *index, "C ", 2) == 0)
		return (parse_camera(file_string, index, element));
	else if (!ft_strncmp(file_string + *index, "L ", 2))
		return (parse_light(file_string, index, element));
	else if (!ft_strncmp(file_string + *index, "sp ", 3))
		return (parse_sphere(file_string, index, element));
	else if (!ft_strncmp(file_string + *index, "pl ", 3))
		return (parse_plane(file_string, index, element));
	else if (!ft_strncmp(file_string + *index, "cy ", 3))
		return (parse_cylinder(file_string, index, element));
	return (ERR_IDENTIFIER_ELEMENT_WRONG);
}

static int	count_elements(char *file_string)
{
	int		nb_elements;
	char	*tmp;

	nb_elements = 0;
	tmp = file_string;
	while (*tmp == '\n')
		tmp++;
	while (*tmp != '\0')
	{
		if (*tmp == '\n' && tmp != file_string
			&& *(tmp +1) != '\n' && *(tmp +1) != '\0')
			nb_elements++;
		tmp++;
	}
	if (file_string != tmp && *tmp -1 != '\n')
		nb_elements++;
	return (nb_elements);
}

static int	set_elements(char *file_string, int *index, \
					int *nb_elmts, t_element *elements)
{
	int	i;
	int	ret;

	i = 0;
	while (i < *nb_elmts)
	{
		while (file_string[*index] == '\n')
			(*index)++;
		ret = set_one_element(file_string, index, elements + i);
		if (ret != 0)
		{
			free(elements);
			return (ret);
		}
		i++;
	}
	return (0);
}
int	free_elements(char *file_string, int index, int err_code)
{
	print_error_parsing(file_string, index, err_code);
	return(err_code);
}
/*
	calls the open function, count the number of elements.
	no file descriptor is open after returning the function.
*/
int	get_elements(char *file_string, int *nb_elmts, t_element *elmts)
{
	int			index;
	int			ret;

	index = 0;
	*nb_elmts = count_elements(file_string);
	elmts = ft_calloc(*nb_elmts, sizeof(t_element));
	if (elmts == NULL)
		return (free_elements(file_string, 0, ERR_MALLOC));
	ret = set_elements(file_string, &index, nb_elmts, elmts);
	if (ret != 0)
		return (free_elements(file_string, index, ret));
	return (0);
}
