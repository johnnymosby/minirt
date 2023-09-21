/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:38:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/21 13:58:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include <mlx.h>
#include  "libft.h"
#include <stddef.h>// NULL
#include <stdlib.h>// exit
#include <stdbool.h>// bool

#define		WIN_HEIGHT	1024
#define		MENU_WIDTH	256
#define		PCT_WIDTH	768

typedef struct s_image {
    void	*img_ptr;
    void	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}    t_image;

typedef struct s_win{
void	*mlx_ptr;
void	*win_ptr;
t_image	menu;
t_image	pct;
} 	t_win;

t_win	window(void);
bool	initialise_picture(t_win *window);
bool	initialise_menu(t_win *window);

#endif
