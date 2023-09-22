/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 21:19:26 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	set_one_element(char *start, int *index, t_element *element)
{
	if (ft_strncmp(start, "sp ", 3))
		return (parse_sphere(start, index +3, element));
	else
		return (NULL);
}


/*
*/
static int	count_elements(char *file_string)
{
	int	nb_elements;
	int	i;
		
	nb_elements = 0;
	i = 0;
	while (file_string[i] == '\n')
		i++;
	while (file_string[i] != '\0')
	{
		if (file_string[i] == '\n')
		{
			nb_elements++;
			while(file_string[i] == '\n')
				i++;
		}
		else
			i++;
	}
	if (i > 0 && file_string[i - 1] != '\n')
		nb_elements++;
	return (nb_elements);
}

/*
*	calls the open function, count the number of elements.
*	no file descriptor is open after returning the function.
*/
t_element	*get_elements(char *file_string)
{
	t_element	*elements;
	int			index;
	int			nb_elements;
	int			i;
	
	index = 0;
	nb_elements = count_elements(file_string);
	if (nb_elements < 3)
		return (NULL);
	elements = ft_calloc(nb_elements, sizeof(t_element));
	if (elements == NULL)
		return (NULL);		
	i = 0;
	while (i < nb_elements)
	{
		if (set_one_element(file_string, &index, elements +i) == false)
		{
			free(elements);
			return (NULL);
		}
		i++;
	}
	return (elements);
}
