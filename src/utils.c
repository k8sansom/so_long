/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:10:58 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/20 16:24:16 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit(char *s, t_struct *game, int exit_code)
{
	int	i;

	i = 0;
	if (game->win_ptr)
		mlx_destroy_window (game->mlx_ptr, game->win_ptr);
	free (game->mlx_ptr);
	if (game->fd)
		close (game->fd);
	while (i < game->map_height - 1)
	{
		free(game->map[i]);
		i++;
	}
	free (game->map);
	if (s)
		ft_printf("%s\n", s);
	exit (exit_code);
}

int	ft_move(t_struct *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectable_counter != 0)
			return (0);
		ft_printf("You've won!\n");
		ft_exit("", game, 0);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->move_counter++;
	}
	else if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->collectable_counter--;
		game->move_counter++;
	}
	return (1);
}

