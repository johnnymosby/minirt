/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:38:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/18 13:10:45 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

#include <mlx.h>
#include  "libft.h"
#include <stddef.h>// NULL
#include <stdlib.h>// exit
#include <stdbool.h>// bool

#define		WIN_HEIGHT	1920
#define		MENU_WIDTH	980
#define		PCT_WIDTH	100

typedef struct s_image {
    void	*img_ptr;
    char	*addr;
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
void	free_mlx_memory(t_win *window);

#endif
