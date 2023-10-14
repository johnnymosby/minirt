/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/14 18:52:25 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_message(int err_code)
{
	char	*s[70];

	s[1] = "Opening the file is not possible\n";
	s[2] = "Name of the file is not correct\n";
	s[3] = "Number of mandatory elements is not correct\n";
	s[4] = "Identifier of element is not correct\n";
	s[5] = "Nemmory allocation error while getting the data\n";
	s[6] = "Value should be a digit\n";
	s[7] = "A comma is missing\n";
	s[8] = "A space is missing\n";
	s[9] = "The value for camera / field of view should be 0-180]";
	s[10] = "The value for ambient / lightning ratio should be [0.0-1.0]";
	s[11] = "The value for colors should be [0-255]";
	s[12] = "The value for diameter should be positive";
	s[13] = "The value for cylinder height should be positive";
	s[14] = "The value for light brightness height should be positive";
	s[15] = "The value for orientation vector should be [-1,1] for each axis";
	ft_putstr_fd(s[-err_code], 2);
}

static int	count_chars(char *file_string, int index, int newlines)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (count < newlines)
	{
		if (file_string[i] == '\n')
			count++;
		i++;
	}
	return (index - i);
}

static int	count_lines(char *file_string, int index)
{
	int	newlines;
	int	i;

	newlines = 0;
	i = 0;
	while (i <= index)
	{
		if (file_string[i] == '\n')
			newlines++;
		i++;
	}
	return (newlines);
}

int	print_localisation(int type, int nb)
{
	char	*str;

	str = ft_itoa(nb);
	if (str == NULL)
	{
		ft_putstr_fd("Error\nERROR MEM. ALLOC. WHILE PRINTING ERR MESSAGE\n", 2);
		return (-1);
	}
	if (type == 1)
		ft_putstr_fd("line:\t", 2);
	if (type == 2)
		ft_putstr_fd("character:\t", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free(str);
	return (0);
}

void	*print_error_parsing(char *file_string, int index, int err_code)
{
	int	line_nb;
	int	char_nb;	

	line_nb = count_lines(file_string, index);
	char_nb = count_chars(file_string, index, line_nb);
	ft_putstr_fd("Error\n", 2);
	if (index != 0)
	{
		ft_putstr_fd("Error in parsing fount at:\n", 2);
		if (print_localisation(1, line_nb))
			return (NULL);
		if (print_localisation(2, char_nb))
			return (NULL);
	}
	print_message(err_code);
	return (NULL);
}
