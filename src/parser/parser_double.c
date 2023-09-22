/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:05 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 16:20:44 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
/*
static bool	set_absolut_result(char *str, double *result)
{
    double	fraction;
    bool	is_decimal;
	
	fraction = 0.1;
	is_decimal = false;
	if (!ft_isdigit(*str))
		return (false)
	while (*str != '\0')
	{
		if (ft_isdigit(*str) && is_decimal == false)
			*result = *result * 10.0 + (*str - '0');
		else if (ft_isdigit(*str) && is_decimal == true)
		{
			result = result + (*str - '0') * fraction;
			fraction *= 0.1;
		} 
		else if (*str == '.' && is_decimal == false)
			hasFraction = true;
		str++;
    }
	if (*str != '\0')
		return (false)
}


bool parser_double(char *str, double *result)
{
    bool	is_negative;
    
	result = 0;
	is_negative = false;
    if (*buf == '-')
	{
        is_negative = true;
        byte = read(fd, bufcd ..);
    }
	set_absolut_result(str, result)
    if (is_negative)
        result *= -1;
    return result;
}*/

bool parse_double(char *str, double *result)
{
	(void)str;
	(void)result;
	return (true);
}
