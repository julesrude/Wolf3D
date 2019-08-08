/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:22:53 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 19:54:59 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		ft_close(void *param)
{
	(void)param;
	system("leaks -q wolf3d");
	exit(0);
	return (0);
}

/*
**	question about the return value. should it be (-1) or (0)
**	when exit == 1, we should exit from the program, if no, the prog continues
*/

int		put_error(int err_option, char *param, int toexit)
{
	char	errmessage[512];

	ft_bzero(errmessage, 512);
	ft_putstr(COLOR_RED);
	if (err_option == ERR_ERRNO)
	{
		ft_strcat(errmessage, "wolf3d");
		(param) ? ft_strcat(errmessage, ": ") : (NULL);
		(param) ? ft_strcat(errmessage, param) : (NULL);
		perror(errmessage);
	}
	else if (err_option == ERR_NOMAP)
		ft_putendl_fd("wolf3d: you forgot to feed me the maze map\n\
		\rusage: \x1b[32m./wolf3d [mazefile]\x1b[0m", 2);
	else if (err_option == ERR_MESSAGE)
		ft_putendl_fd(param, 2);
	system("leaks -q wolf3d");
	if (toexit == 1)
		exit(EXIT_FAILURE);
	return (-1);
}

int		main(int argc, char **argv)
{
	char	*map;
	t_wolf	*w;

	map = NULL;
	w = NULL;
	init_wolf(&w);
	if (argc == 1)
		put_error(ERR_NOMAP, NULL, 1);
	if (read_file(argv[1], &map, w) == -1)
		return (EXIT_FAILURE);
	map_tostruct(map, w);
	cast_rays(w);
	init_mlx(w);
	mlx_hook(w->win, 2, 0, key_press, w);
	// mlx_hook(m->win, 4, 0, mouse_press, w);
	// mlx_hook(m->win, 5, 0, mouse_release, w);
	// mlx_hook(m->win, 6, 0, mouse_move, w);
	mlx_hook(w->win, 17, 0, ft_close, w);
	mlx_loop(w->win);
	return (0);
}
