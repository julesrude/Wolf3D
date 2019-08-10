/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:26:37 by yruda             #+#    #+#             */
/*   Updated: 2019/08/10 22:21:12 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define CWALL_E 0x9ae1e2
# define CWALL_W 0xf0ede3
# define CWALL_N 0xca3074
# define CWALL_S 0xf6c667
# define CFLOOR 0x332851

# define WIN_W 1280
# define WIN_H 720
# define IMAGE_W 1280
# define IMAGE_H 720
# define CENTRE_W 640
# define CENTRE_H 360

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

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_settings
{
	double	fov;
	double	neighrays;
	int		distance;
	int		blksize;

	int		player_height;
	int		horison;
	int		fish_eye;
//	int		my_size;
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

typedef struct	s_wolf
{
	char		**map;

	int			xwidth;
	int			ylength;

	int			xplayer;
	int			yplayer;
	double		angle;

	void		*mlx;
	void		*win;
	t_image		*img;
	t_settings	set;
}				t_wolf;

/*
**	main.c
*/
int		ft_close(void *param);
int		put_error(int err_option, char *param, int toexit);

/*
**	validate_file.c
*/
int		read_file(char *file, char **map, t_wolf *w);

/*
**	init_wolf.c
*/
int		init_wolf(t_wolf *w);

/*
**	init_mlx.c
*/
int		init_mlx(t_wolf *w);

/*
**	map_tostruct.c
*/
int		map_tostruct(char *map, t_wolf *w);

/*
**	cast_rays.c
*/
int		cast_rays(t_wolf *w);

/*
**	actions.c
*/
int		key_press(int key, t_wolf *w);

/*
**	draw_ray.c
*/
void	draw_ray(t_wolf *w, int wall_height, int raynum);

void	image_background(t_wolf *w, int color);

/*
**	distance_to_walls.c
*/
int		find_distance(t_wolf *w, t_point p, double angle);
int		projected_height(t_wolf *w, t_point p, double angle);

#endif