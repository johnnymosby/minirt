/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 12:26:46 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parser(char *filename)
{
	char		*file_string;
	t_element	*elmts;
	
	file_string = get_file_into_string(filename);
	if (file_string == NULL)
		return (false);
	elmts = get_elements(file_string);
	if (elmts == NULL)
	{
		free(file_string);
		return (false);
	}
	return (true);
}