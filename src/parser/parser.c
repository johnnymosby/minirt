/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 22:49:23 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "camera.h"



static bool	check_nb_elements(t_element *elmts, int nb_elmts)
{
	int		i;
	int		nb_A;
	int		nb_C;
	int		nb_L;

	i = 0;
	nb_A = 0;
	nb_C = 0;
	nb_L = 0;
	while ( i < nb_elmts)
	{
		if (elmts[i].element_type == ELMT_CAMERA)
			nb_C++;
		else if (elmts[i].element_type == ELMT_AMBIENT)
			nb_A++;
		else if (elmts[i].element_type == ELMT_LIGHT)
			nb_L++;
		i++;
	}
	if (nb_A != 1 || nb_C != 1 || nb_L != 1)
		return (false);
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
	if (check_nb_elements(elmts, nb_elmts) == false)
	{
		free (elmts);
		return (NULL);
	}
	w->nb_shapes = nb_elmts - 3;
	(void)cam;
//	if (put_elements_into_world_and_camera(elmts, w, cam))
//	{	
//		free(elmets);
//		return (false);
//	}
	free(elmts);
	return (true);
}
