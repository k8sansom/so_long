#include "../inc/so_long.h"

void	ft_flood_fill(t_struct *temp, int y_axis, int x_axis)
{
	if (temp->map[y][x] == '1')
		return ;
	if (temp->map[y][x] == 'C')
		temp->collectable_counter--;
	if (temp->map[y][x] == 'E')
		temp->exit_counter++;
	temp->map[y][x] == '1';
	ft_flood_fill(temp, y_axis + 1, x_axis);
	ft_flood_fill(temp, y_axis - 1, x_axis);
	ft_flood_fill(temp, y_axis, x_axis + 1);
	ft_flood_fill(temp, y_axis, x_axis - 1);
}

void ft_parse_path(t_struct *game)
{
	t_struct	temp;
	int			i;

	temp.map_height = game->map_height;
	temp.map_width = game->map_width;
	temp.collectable_counter = game->collectable_counter;
	temp.x_axis = game->x_axis;
	temp.y_axis = game->y_axis;
	temp.exit_counter = 0;
	temp.map = (char **)malloc(temp.map_height * sizeof(char *));
	if (!temp.map)
		ft_exit("Error: allocating memory", game, game->exit_code++);
	i = 0;
	while (i < temp.map_height)
	{
		temp.map[i] = ft_strdup(game->map[i]);
		i++;
	}
	ft_flood_fill(&temp, temp.y_axis, temp.x_axis);
	if (temp.exit_counter != 1 && temp.collectable_counter != 0)
	{
		ft_free(temp.map, temp.map_height);
		ft_exit("Error: no valid path available", game, game->exit_code++);
	}
	ft_free(temp.map, temp.map_height);
}