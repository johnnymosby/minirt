/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:38:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/09 13:15:23 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "libft.h"
# include <mlx.h>
# include <stdbool.h> // bool
# include <stddef.h>  // NULL
# include <stdlib.h>  // exit
# ifdef __linux__
#  include "X11/keysym.h"
# endif
# include "mlx_keys.h"
# include "stdio.h"

# define WIN_HEIGHT 100
# define MENU_WIDTH 100
# define PCT_WIDTH 200

typedef struct s_image
{
	void	*img_ptr;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_image;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	menu;
	t_image	pct;
}			t_win;

t_win		window(void);
bool		initialise_mlx(t_win *window);
bool		initialise_picture(t_win *window);
bool		initialise_menu(t_win *window);
void		catch_mlx_hooks(t_win *window);

#endif
