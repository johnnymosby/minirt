/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:49:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 11:46:31 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_OPEN_FILE -1
# define ERR_NAME_FILE_WRONG -2
# define ERR_NB_MANDATORY_ELMTS -3
# define ERR_IDENTIFIER_ELEMENT_WRONG -4
# define ERR_MALLOC -5
# define ERR_VALUE_IS_NOT_A_DIGIT -6
# define ERR_MISSING_COMMA -7
# define ERR_MISSING_SPACE -8
# define ERR_MISSING_NL -9
# define ERR_VALUE_RANGE -10
# define ERR_READ -11
# define ERR_NB_ARGUMENTS -12
# define ERR_MLX_WIN -13
# define ERR_MLX_PCT -14
# define ERR_MLX_MENU -15
# define ERR_NORM_VECTOR -16

# define PRINTLINE 0
# define PRINTCHAR 1

# define ERR_LIGHTNING	1
# define ERR_CAMERA		2
# define ERR_LIGHT		3
# define ERR_SPHERE		4
# define ERR_PLANE		5
# define ERR_CYLINDER	6
# define ERR_SHAPES		7
# define ERR_ELEMENTS	8
# define ERR_CANVAS		9

int		print_error(char *file_string, int index, int err, int elmt);

#endif