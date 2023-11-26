/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/23 16:55:07 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long.h"

static int	ft_d(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	ft_render_player(game, y, x, 'R');
	++x;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return ;
	ft_render_game(game, 'R');
	move = ft_move(game, x, y);
	if (!move)
		return ;
	game->map[y][x - 1] = '0';
	ft_print_to_screen(game);
	return ;
}

static int	ft_a(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	ft_render_player(game, y, x, 'L');
	--x;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return ;
	ft_render_game(game, 'L');
	game->map[y][x + 1] = '0';
	ft_print_to_screen(game);
	return ;
}

static int	ft_s(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	ft_render_player(game, y, x, 'D');
	++y;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return ;
	ft_render_game(game, 'D');
	move = ft_move(game, x, y);
	if (!move)
		return ;
	game->map[y - 1][x] = '0';
	ft_print_to_screen(game);
	return ;
}

static void	ft_w(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	ft_render_player(game, y, x, 'U');
	--y;
	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return ;
	ft_render_game(game, 'U');
	game->map[y + 1][x] = '0';
	ft_print_to_screen(game);
	return ;
}

int	ft_controls(int command, t_game *game)
{
	if (command == KEY_ESC)
		ft_exit ("Giving up?!", game, 0);
	if (command == KEY_W || command == KEY_UP)
		move = ft_w(game);
	if (command == KEY_S || command == KEY_DOWN)
		move = ft_s(game);
	if (command == KEY_A || command == KEY_LEFT)
		move = ft_a(game);
	if (command == KEY_D || command == KEY_RIGHT)
		move = ft_d(game);
	return ;
}
