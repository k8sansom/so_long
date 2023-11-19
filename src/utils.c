#include "../inc/so_long.h"

void	ft_error(char *s, t_struct *game)
{
	int	i;

	i = 0;
	if (game->winpointer)
		mlx_destroy_window (game->mlxpointer, game->winpointer);
	free (game->mlxpointer);
	while (i < game->height - 1)
	{
		free (game->map[i]);
		i++;
	}
	free (game->map);
	perror (s);
	exit (STDERR_FILENO);
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