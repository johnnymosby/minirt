/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_get_elements_from_string.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/10 19:52:10 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	set_one_element(char *file_string, int *index, t_element *element)
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
	print_error_parsing("wrong identifier at the start of the line\n");
	return (false);
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

/*
*	calls the open function, count the number of elements.
*	no file descriptor is open after returning the function.
*/
t_element	*get_elements(char *file_string, int *nb_elmts)
{
	t_element	*elements;
	int			index;
	int			i;

	index = 0;
	*nb_elmts = count_elements(file_string);
	if (*nb_elmts < 3)
		return (print_error_parsing("wrong number of elements\n"));
	elements = ft_calloc(*nb_elmts, sizeof(t_element));
	if (elements == NULL)
		return (NULL);
	i = 0;
	while (i < *nb_elmts)
	{
		while (file_string[index] == '\n')
			index++;
		if (set_one_element(file_string, &index, elements + i) == false)
		{
			free(elements);
			return (NULL);
		}
		i++;
	}
	return (elements);
}
