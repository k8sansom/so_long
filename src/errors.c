/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:00:42 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/20 16:31:02 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_checker(t_struct *game, int height, int width)
{
	if (game->map[height][width] != '0' && game->map[height][width] != '1'\
		&& game->map[height][width] != 'C' && game->map[height][width] != 'E'\
		&& game->map[height][width] != 'P')
		ft_exit ("Error: unknown character in map", game, game->exit_code++);
	if (game->map[height][width] == 'C')
		game->collectable_counter++;
	if (game->map[height][width] == 'P')
		game->player_counter++;
	if (game->map[height][width] == 'E')
		game->exit_counter++;
}

static int	ft_horizontal(t_struct *game)
{
	int	x;
	int	bottom_wall;

	x = 0;
	bottom_wall = game->map_height - 1;
	while (x < game->map_width)
	{
		if (game->map[0][x] != 1 || game->map[bottom_wall][x] != 1)
			return (1);
		x++;
	}
	return (0);
}

static int	ft_vertical(t_struct *game)
{
	int	right_wall;
	int	y;

	y = 0;
	right_wall = game->map_width - 1;
	while (y < game->map_height)
	{
		if (game->map[y][0] != 1 || game->map[y][right_wall] != 1)
			return (1);
		y++;
	}
	return (0);
}

void	ft_error_check(t_struct *game)
{
	int	vertical;
	int	horizontal;
	int	height;
	int	width;

	vertical = ft_vertical(game);
	horizontal = ft_horizontal(game);
	if (vertical == 1 || horizontal == 1)
		ft_exit ("Error: missing external walls!", game, game->exit_code++);
	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width < game->map_width)
		{
			ft_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->player_counter != 1 || game->collectable_counter < 1 \
		|| game->exit_counter != 1)
		ft_exit ("Error: Something is wrong with player, exit or collectable", \
			game, game->exit_code++);
}
