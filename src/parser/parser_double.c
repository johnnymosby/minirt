/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:05 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 21:09:46 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	set_absolut_result(char *file_string, int *index, double *result)
{
    double	fraction;
    bool	is_decimal;
	
	fraction = 0.1;
	is_decimal = false;
	if (!ft_isdigit(file_string[*index]))
		return (false);
	while (ft_isdigit(file_string[*index]) || file_string[*index] == '.')
	{
		if (ft_isdigit(file_string[*index]) && is_decimal == false)
			*result = *result * 10.0 + (file_string[*index] - '0');
		else if (ft_isdigit(file_string[*index]) && is_decimal == true)
		{
			*result = *result + (file_string[*index] - '0') * fraction;
			fraction *= 0.1;
		} 
		else if (file_string[*index] == '.' && is_decimal == false)
			is_decimal = true;
		else if (file_string[*index] == '.')
			return (false);
		(*index)++;
    }
	return (true);
}


bool parse_double(char *file_string, int *index, double *result)
{
    bool	is_negative;
    
	*result = 0;
	is_negative = false;
    if (file_string[*index] == '-')
	{
        is_negative = true;
        (*index)++;
    }
	if (set_absolut_result(file_string, index, result) == false)
		return (false);
    if (is_negative)
        *result = *result * -1;
    return (true);
}

