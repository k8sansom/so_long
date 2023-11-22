/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:21 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/22 11:43:55 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_struct
{
	int		fd;
	int		map_height;
	int		map_width;
	int		player_counter;
	int		collectable_counter;
	int		move_counter;
	int		exit_counter;
	int		x_axis;
	int		y_axis;
	int		exit_code;

	char	**map;
	void	*ground;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_struct;

//map
void	ft_read_map(t_struct *game, char *s);

//graphics
void	ft_set_images(t_struct *game);
void	ft_set_graphics(t_struct *game);

//errors
void	ft_error_check(t_struct *game);

//path check
void	ft_parse_path(t_struct *game);

//utils
void	ft_exit(char *s, t_struct *game, int exit_code);
int		ft_move(t_struct *game, int x, int y);
void	ft_free(char **arr);

//controls
int		ft_controls(int command, t_struct *game);

#endif