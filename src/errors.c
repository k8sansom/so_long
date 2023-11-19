#include "../inc/so_long.h"

static void	ft_checker(t_struct *game, int height, int width)
{
	if (game->map[height][width] != '0' && game->map[height][width] != '1'\
		&& game->map[height][width] != 'C' && game->map[height][width] != 'E'\
		&& game->map[height][width] != 'P')
		ft_error ("Error: unknown character in map", &game)
	if (game->map[height][width] == 'C')
		game->collectables++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}
static int	ft_horizontal(t_struct *game)
{
	int	width;
	int	bottomwall;

	width = 0;
	bottomwall = game->mapheight - 1;
	while (width < game->mapwidth)
	{
		if (game->map[0][width] != 1 || game->map[bottomwall][width] != 1)
			return (1)
		width++;
	}
	return (0);
}

static int	ft_vertical(t_struct *game)
{
	int	height;
	int	rightwall;

	height = 0;
	rightwall = game->mapwidth - 1;
	while (height < game->mapheight)
	{
		if (game->map[height][0] != 1 || game->map[height][rightwall] != 1)
			return (1);
		height++;
	}
	return (0);
}

void	ft_error_check(t_struct *game)
{
	int	vertical;
	int	horizontal;
	int	height;
	int	width;

	vertical = ft_vertical (game);
	horizontal = ft_horizonal (game);
	if (vertical == 1 || horizontal == 1)
		ft_error ("Error: missing external walls!", &game);
	height = 0;
	while (height < game->mapheight - 1)
	{
		width = 0;
		while (width < game->mapwidth)
		{
			ft_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->playercount != 1 || game->columncount < 1 || game->exitcount != 1)
		ft_error ("Error: Something is wrong with player, exit or collectable", &game);
}