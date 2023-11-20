/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:10:58 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/20 11:22:00 by ksansom          ###   ########.fr       */
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
		free (game->map[i]);
		i++;
	}
	free (game->map);
	if (s)
		perror (s);
	exit (exit_code);
}

void	ft_free(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}
