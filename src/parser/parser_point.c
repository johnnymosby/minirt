/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 16:20:57 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
bool	parse_point(int fd, t_tuple *point, char *buf)
{
	int		i;
	ssize_t	byte;
	char	*to_transform;

	i = 1;
	byte = 1;
	to_transform[0] = *buf;
	while (byte > 0 && to_transform[i] != '\n' && to_transfor[i] != '\0')
	{
		byte = read(fd, to_transform + i, 1);
		i++;
	}
	while (byte > 0 && *buf != ' ' && *buf != '\0' && *buf != '\n')
	{
		to_transform[i++] = *buf	
	}
		while (byte > 0 && is_digit(*buf))
		{
			byte = read(fd, &buf, 1);
		}
		if (*buf == .)
		i++;
		if (i)
		if (byte < 0 || i != 3)
		return (false)
	return (true);
}*/

bool parse_point(char *str, t_tuple *point)
{
	(void)str;
	(void)point;
	return (true);
}

