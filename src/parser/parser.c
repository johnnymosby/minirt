/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 18:47:43 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parser(char *filename)
{
	char		*file_string;
	t_element	*elmts;
	
	file_string = put_file_into_string(filename);
	if (file_string == NULL)
		return (false);
	elmts = get_elements(file_string);
	free(file_string);
	if (elmts == NULL)
		return (false);
//	if (put_elements_into_world_and_camera(elmts, w, cam))
//	{	
//		free(elmets);
//		return (false);
//	}
	free(elmts);
	return (true);
}
