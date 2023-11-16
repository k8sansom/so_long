/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:21 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 16:27:10 by ksansom          ###   ########.fr       */
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


# define HEIGHT 810
# define WIDTH 810
# define BG_IMG "../assets/Beach_overworld.xpm"

typedef struct s_struct
{
	int		fd;
	int		height;
	int		width;
	int		players;
	int		columns;
	int		exit;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
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

//utils
void	ft_free (char *arr);
#endif