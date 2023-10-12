/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:40:48 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 17:29:04 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H

#ifdef __APPLE__
# define KEY_ESC 53
# define KEY_ZOOM_IN 4
# define KEY_ZOOM_OUT 5
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_T 17
# define KEY_CTRL 256
# define KEY_SPACE 49
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_PLUS 24
# define KEY_MINUS 27
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
#endif

#ifdef __linux__
# define KEY_ESC 65307
# define KEY_ZOOM_IN 4
# define KEY_ZOOM_OUT 5
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 114
# define KEY_T 116
# define KEY_CTRL 65507
# define KEY_SPACE 32
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_MINUS 45
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
#endif

#endif