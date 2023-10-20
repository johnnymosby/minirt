/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/20 18:56:21 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_message(int err)
{
	char	*s[70];

	s[1] = "Opening the file is not possible\n";
	s[2] = "Name of the file is not correct\n";
	s[3] = "Number of mandatory elements is not correct\n";
	s[4] = "Identifier of element is not correct\n";
	s[5] = "Memory allocation error\n";
	s[6] = "Value should be a digit\n";
	s[7] = "A comma is missing\n";
	s[8] = "A space is missing\n";
	s[9] = "The value is not in the expected range\n";
	s[10] = "A problem occured while reading\n";
	s[11] = "Number of arguments is not correct\n";
	ft_putstr_fd(s[-err], 2);
}

static void	count_lines_and_chars(char *file_str, int index, int *nl, int *ch)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= index)
	{
		if (file_str[i] == '\n')
			(*nl)++;
		i++;
	}
	i = 0;
	while (count < *nl)
	{
		if (file_str[i] == '\n')
			count++;
		i++;
	}
	*ch = index - i;
}

static int	print_localisation(int type, int nb)
{
	char	*str;

	str = ft_itoa(nb);
	if (str == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("MEM. ALLOC. WHILE PRINTING ERR MESSAGE\n", 2);
		return (-1);
	}
	if (type == PRINTLINE)
		ft_putstr_fd("line:\t", 2);
	if (type == PRINTCHAR)
		ft_putstr_fd("character:\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free(str);
	return (0);
}

static void	print_element(int element)
{
	char	*s[8];

	s[0] = "";
	s[1] = "Lightning: ";
	s[2] = "Camera: ";
	s[3] = "Light: ";
	s[4] = "Sphere: ";
	s[5] = "Plane: ";
	s[6] = "Cylinder: ";
	s[6] = "Shapes: ";
	s[7] = "Elements: ";
	ft_putstr_fd(s[element], 2);
}

int	print_error_int(char *file_string, int index, int err, int elmt)
{
	int	line_nb;
	int	char_nb;	

	line_nb = 1;
	char_nb = 1;
	count_lines_and_chars(file_string, index, &line_nb, &char_nb);
	ft_putstr_fd("Error\n", 2);
	if (index != 0)
	{
		ft_putstr_fd("Error in parsing fount at:\n", 2);
		if (print_localisation(PRINTLINE, line_nb))
			return (err);
		if (print_localisation(PRINTCHAR, char_nb))
			return (err);
	}
	print_element(elmt);
	print_message(err);
	return (err);
}
