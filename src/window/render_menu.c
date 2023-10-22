/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:38:48 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/22 13:37:16 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	print_infos(t_win *win)
{
	void	*m;
	void	*p;

	m = win->mlx_ptr;
	p = win->win_ptr;
	mlx_set_font(m, p,
		"-sony-fixed-medium-r-normal--24-170-100-100-c-120-jisx0201.1976-0");
	mlx_string_put(m, p, PCT_WIDTH + 5, 50, WHITE, "Control Keys");
	mlx_set_font(m, p,
		"-misc-fixed-medium-r-normal--0-0-75-75-c-0-iso10646-1");
	mlx_string_put(m, p, PCT_WIDTH + 5, 90, DARK_GREY, "translate");
	mlx_string_put(m, p, PCT_WIDTH + 20, 110, WHITE, "WASD, space, control");
	mlx_string_put(m, p, PCT_WIDTH + 5, 150, DARK_GREY, "rotate");
	mlx_string_put(m, p, PCT_WIDTH + 20, 170, WHITE, "QE, arrows");
	mlx_string_put(m, p, PCT_WIDTH + 5, 210, DARK_GREY, "change light");
	mlx_string_put(m, p, PCT_WIDTH + 20, 230, WHITE, "L + translate");
}

static void	put_pixel(unsigned char *s, int color)
{
	*(s + 3) = color / (256 * 256 * 256);
	*(s + 2) = (color % (256 * 256 * 256)) / (256 * 256);
	*(s + 1) = (color % (256 * 256)) / 256;
	*(s + 0) = (color % 256);
}


static void	print_background(t_win *window)
{
	int	h;
	int	w;

	h = 0;
	while (h < WIN_HEIGHT)
	{
		w = 0;
		while (w < MENU_WIDTH)
		{
			put_pixel(window->menu.addr + window->menu.line_len * h
				+ (window->menu.bpp / 8) * w, LIGHT_GREY);
			w ++;
		}
		h++;
	}
}


/*
$ xlsfonts '*fixed*' | less
lists all fonts with fixed width
§ xfd 
to check the fonts without changing the code
https://twiserandom.com/unix/x11-fonts-a-tutorial/index.html
no check needed - if mlxfont doesn't work will print with the wrong font
*/
void	render_menu(t_win *window)
{
	print_background(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
		window->menu.img_ptr, PCT_WIDTH, 0);
	print_infos(window);
}