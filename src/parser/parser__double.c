/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:05 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 16:42:40 by aguilmea         ###   ########.fr       */
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
		return (ERR_VALUE_IS_NOT_A_DIGIT);
	while (ft_isdigit(file_string[*index]) || file_string[*index] == '.')
	{
		if (ft_isdigit(file_string[*index]) && is_decimal == false)
			*result = *result * 10 + (file_string[*index] - '0');
		else if (ft_isdigit(file_string[*index]) && is_decimal == true)
		{
			*result = *result + (file_string[*index] - '0') * fraction;
			fraction *= 0.1;
		}
		else if (file_string[*index] == '.' && is_decimal == false)
			is_decimal = true;
		else if (file_string[*index] == '.')
			return (ERR_VALUE_IS_NOT_A_DIGIT);
		(*index)++;
	}
	return (0);
}

int	parse_double(char *file_string, int *index, double *result)
{
	bool	is_negative;
	int		ret;

	*result = 0;
	is_negative = false;
	ret = 0;
	if (file_string[*index] == '-')
	{
		is_negative = true;
		(*index)++;
	}
	ret = set_absolut_result(file_string, index, result);
	if (ret != 0)
		return (ret);
	if (is_negative)
		*result = *result * -1;
	while (file_string[*index] == ' ')
		(*index)++;
	return (0);
}
