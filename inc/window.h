/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:38:27 by aguilmea          #+#    #+#             */
/*   Updated: 2024/03/28 17:40:07 by rbasyrov         ###   ########.fr       */
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
# include "shapes.h"
# include "errors.h"

# define WIN_HEIGHT 500
# define MENU_WIDTH 200
# define PCT_WIDTH 500

# define WHITE 0x00FFFFFF
# define LIGHT_GREY 0x004E4E4E
# define DARK_GREY 0x00111111
# define BLACK 0x00000000

typedef struct s_scene	t_scene;

typedef enum e_control_state
{
	CAMERA,
	SHAPE,
	LIGHT
}	t_control_state;

typedef struct s_controls
{
	t_scene				*scene;
	t_control_state		control_state;
	t_shape				*shape_in_control;
}	t_controls;

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

t_win	window(void);
int		initialise_mlx(t_scene *sc, t_win *window);
bool	initialise_picture(t_win *window);
bool	initialise_menu(t_win *window);
void	catch_close_hooks(t_win *window);
int		mouse_hook(int keycode, int x, int y, t_controls *controls);
void	change_camera_zoom(int keycode, t_scene *scene);
void	respond_to_left_click(t_controls *controls, int x, int y);
void	respond_to_right_click(t_controls *controls);
t_shape	*find_clicked_shape(t_controls *controls, int x, int y);
void	rerender(t_scene *scene);
void	render_menu(t_win *window);
void	change_shape_size(int keycode, t_controls *controls);
void	translate_camera(int keycode, t_controls *controls);
void	set_updated_transform_in_camera(t_controls *controls, t_matrix *m);
void	rotate_camera(int keycode, t_controls *controls);
void	translate_shape(int keycode, t_controls *controls);
void	set_updated_transform_in_shape(t_controls *controls, t_matrix *m);
void	rotate_shape(int keycode, t_controls *controls);
void	translate_light(int keycode, t_controls *controls);

#endif
