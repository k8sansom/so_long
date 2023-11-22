/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:02:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/22 14:32:14 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_place_graphics(t_struct *game, int height, int width, int c)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->ground, width, height);
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->wall, width, height);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->exit, width, height);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->player, width, height);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->collectable, width, height);
}

void	ft_set_graphics(t_struct *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (width < game->map_width)
		{
			if (game->map[height][width] == '0')
				ft_place_graphics (game, height, width, '0');
			if (game->map[height][width] == '1')
				ft_place_graphics (game, height, width, '1');
			if (game->map[height][width] == 'E')
				ft_place_graphics (game, height, width, 'E');
			if (game->map[height][width] == 'P')
				ft_place_graphics (game, height, width, 'P');
			if (game->map[height][width] == 'C')
				ft_place_graphics (game, height, width, 'C');
			width++;
		}
		height++;
	}
}

void	ft_set_images(t_struct *game)
{
	int	x;
	int	y;

	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/floor.rpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/wall.rpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/Kate.rpm", &x, &y);
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/wine.rpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/toilet.rpm", &x, &y);
	
}
