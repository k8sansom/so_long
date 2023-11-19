#include "../inc/so_long.h"

void	check_errors(t_struct *game)
{
	int	vertical;
	int	horizontal;
	int	height;
	int	width;

	vertical = verticalwall(game);
	horizontal = horizontalwall(game);
	if (!verticalwall || !horizontalwall)
		ft_error ("Error: this game doesn't have walls!", &game);
	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			ft_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->player != 1 || game->wall < 1 || game->exit != 1)
		ft_error ("Error: Something is wrong with player, exit or collectable", &game);
}