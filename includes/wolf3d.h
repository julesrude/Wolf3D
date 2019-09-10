/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:26:37 by yruda             #+#    #+#             */
/*   Updated: 2019/09/10 13:00:31 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	functionality:
**	'R'		shadowing on/off
**	'+/-'	increasing/decreasing field of view
**	'P'		psycho mode ///////////////////////////////to-do
*/

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "keyboard.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

# define CWALL_W 0x517c63//0xf0ede3 light
# define CWALL_E 0x9ae1e2
# define CWALL_N 0xca3074
# define CWALL_S 0xf6c667
# define CFLOOR 0x332851
# define CCEILING 0xf5b19c//ee6a59// good orange f9ac67
# define CWHITE 0xffffff

# define WIN_W 1280//1600//
# define WIN_H 720//900//
# define IMAGE_W 1280//1600//
# define IMAGE_H 720//900//
# define CENTRE_W 640//800//
# define CENTRE_H 360//450//
# define MAPIMG_W 256
# define MAPIMG_H 256

# define BLKSIZE (128)
# define STEP 8
# define ANGLE (M_PI / 180)

# define ISWALL(c) ((c >= '1' && c <= '9') ? (1) : (0))

# define COLOR_RED		"\x1b[31m"
# define COLOR_GREEN	\x1b[32m
# define COLOR_YELLOW	"\x1b[33m"
# define COLOR_BLUE		"\x1b[34m"
# define COLOR_MAGENTA	"\x1b[35m"
# define COLOR_CYAN		"\x1b[36m"
# define COLOR_RESET	"\x1b[0m"

# define ERR_ERRNO		0
# define ERR_NOMAP		1
# define ERR_MESSAGE	2

enum	wall_sides
{
	north,
	south,
	east,
	west
}					;

typedef struct	s_textures
{
  int			width;
  int			height;
  char			*buffer;
//  float			vertexes[8];
//  struct mlx_img_list_s	*next;
}				t_textures;

typedef struct	s_dpoint
{
	double	x;
	double	y;
}				t_dpoint;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_wall
{
	t_point			point;
	int				height;
	int				min;
	int				max;

	float			distance;
	int				type;
	enum wall_sides	side;
}				t_wall;

typedef struct		s_mouse
{
	int				x;
	int				previous_x;
}					t_mouse;

typedef struct	s_settings
{
	double	fov;
	double	neighrays;
	int		distance;//to the viewing plane
	int		speed;//of walking

	int		player_height;
	int		horison;
	int		fish_eye;
//	int		my_size;

	int		shadows;
	int		view_distance;//al that is after this distance is black/////////
	
	int		psycho;
	int		textures_on;
}				t_settings;

/*
**	addr - represents the begining of the memory area where the image is stored.
**	From this adress, the first bits_per_pixel (bpp) bits represent the color
**	of the first pixel in the first line of the image.
**	Add size_line to the adress to get the begining of the second line.
*/
typedef struct	s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

/*
**	xwidth & ywidth represent number of blocks
*/

typedef struct	s_wolf
{
	char		**map;
	t_image		*map_img;

	int			xwidth;
	int			ylength;

	double		xplayer;
	double		yplayer;

	char		keys[280];
	t_mouse		*mouse;

	double		angle;
	double		angle_tan;
	double		angle_cos;
	double		angle_sin;

	long int	prev_time;
	long int	now_time;
	double		frametime;

	void		*mlx;
	void		*win;
	t_image		*img;
	t_settings	*set;
	t_textures	*textures[3];
	int			colors[6];
}				t_wolf;

/*
**	main.c
*/
int			ft_close(void *param);
int			put_error(int err_option, char *param, int toexit);

/*
**	validate_map.c
*/
int			read_file(char *file, char **map, t_wolf *w);

/*
**	init_wolf.c
*/
int			init_wolf(t_wolf *w);
void		fov_changed(t_settings *set);
void		init_colors_textures(t_wolf *w);
void		set_angle(t_wolf *w, double angle);

/*
**	init_mlx.c
*/
void		init_mlx(t_wolf *w);
void		init_image(t_wolf *w);

/*
**	map_tostruct.c
*/
int			map_tostruct(char *map, t_wolf *w);

/*
**	cast_rays.c
*/
int			cast_rays(t_wolf *w);

/*
**	actions.c
*/
int			key_press(int key, t_wolf *w);
int			key_release(int key, t_wolf *w);
void		walking(t_wolf *w);
void		other_actions(t_wolf *w);
int			expose_hook(t_wolf *w);
int			mouse_move(int x, int y, t_wolf *m);

/*
**	draw_ray.c
*/
void		draw_ray(t_wolf *w, t_wall wall, int raynum);

/*
**	image.c
*/
void		image_background(t_wolf *w, int color);
void		dot_to_img(t_wolf *w, int x, int y, int color);

/*
**	distance_to_walls.c
*/
double		find_distance(t_wolf *w, t_dpoint p);
double		find_corrected_distance(t_wolf *w, double angle, double dist);
int			projected_height(t_wolf *w, double distance);

/*
**	color_scheme.c
*/
int			get_shadedcolor(t_wall wall, int color);
int			get_texture_color(t_wolf *w, t_wall wall, int x, int y);

/*
**	assist.c
*/
long int	get_now_time();
int			point_iswall(double x, double y, t_wolf *w);
t_point		coords_to_block(double x, double y, t_wolf *w);
char		*ft_strrealloc(char *s, int numcols);

/*
**	texture.c
*/
void		draw_wall_texture_ray(t_wolf *w, t_wall wall, int raynum);

#endif