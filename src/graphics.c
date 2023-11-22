/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:02:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/22 16:00:32 by ksansom          ###   ########.fr       */
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
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height * IMG_H)
	{
		x = 0;
		while (x < game->map_width * IMG_W)
		{
			if (game->map[y][x] == '0')
				ft_place_graphics (game, y, x, '0');
			if (game->map[y][x] == '1')
				ft_place_graphics (game, y, x, '1');
			if (game->map[y][x] == 'E')
				ft_place_graphics (game, y, x, 'E');
			if (game->map[y][x] == 'P')
				ft_place_graphics (game, y, x, 'P');
			if (game->map[y][x] == 'C')
				ft_place_graphics (game, y, x, 'C');
			x += IMG_W;
		}
		y += IMG_H;
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
