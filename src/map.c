/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:04:11 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/20 16:11:38 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_get_width(char *str)
{
	int	width;

	width = 0;
	while (str[width])
		width++;
	if (str[width - 1] == '\n')
		--width;
	return (width);
}

static int	ft_adding_rows(t_struct *game, char *row)
{
	char	**temp;
	int		i;

	i = 0;
	if (!row)
		return (1);
	game->map_height++;
	temp = (char **)malloc (sizeof(char *) * (game->map_height + 1));
	if (!temp)
		ft_exit ("Error: allocating memory for map", game, game->exit_code++);
	temp[game->map_height] = NULL;
	while (i < (game->map_height - 1))
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = row;
	if (game->map)
		free (game->map);
	game->map = temp;
	return (0);
}

void	ft_read_map(t_struct *game, char *s)
{
	char	*mapping;

	game->fd = open (s, O_RDONLY);
	if (game->fd < 0)
		ft_exit ("Error: reading map", game, game->exit_code++);
	while (1)
	{
		mapping = get_next_line(game->fd);
		if (ft_adding_rows(game, mapping) == 1)
			break ;
	}
	close (game->fd);
	game->map_width = ft_get_width (game->map[0]);
}
