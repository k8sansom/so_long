/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:01:49 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/22 12:02:25 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_flood_fill(t_struct *temp, int y, int x)
{
	if (temp->map[y][x] == '1')
		return (0);
	if (temp->map[y][x] == 'C')
		temp->collectable_counter--;
	if (temp->map[y][x] == 'E')
	{
		temp->exit_counter = 1;
		return (0);
	}
	temp->map[y][x] = '1';
	if (ft_flood_fill(temp, y + 1, x))
		return (1);
	if (ft_flood_fill(temp, y - 1, x))
		return (1);
	if (ft_flood_fill(temp, y, x + 1))
		return (1);
	if (ft_flood_fill(temp, y, x - 1))
		return (1);
	return (0);
}

void	ft_parse_path(t_struct *game)
{
	t_struct	temp;
	int			i;

	ft_memset(&temp, 0, sizeof(t_struct));
	temp.collectable_counter = game->collectable_counter;
	temp.x_axis = game->x_axis;
	temp.y_axis = game->y_axis;
	temp.exit_counter = 0;
	temp.map = (char **)malloc(temp.map_height * sizeof(char *));
	if (!temp.map)
		ft_exit("Error: allocating memory", game, game->exit_code++);
	i = 0;
	while (i < game->map_height)
	{
		temp.map[i] = ft_strdup(game->map[i]);
		i++;
	}
	temp.map[++i] = NULL;
	ft_flood_fill(&temp, temp.y_axis, temp.x_axis);
	ft_printf("exit: %i, collectables: %i\n", temp.exit_counter, temp.collectable_counter);
	if (temp.exit_counter != 1 || temp.collectable_counter != 0)
	{
		ft_free(temp.map);
		ft_exit("Error: no valid path available", game, game->exit_code++);
	}
	ft_free(temp.map);
	ft_printf("All good with flood fill testing\n");
}
