#include "../inc/so_long.h"

static int	ft_adding_rows(t_struct *game, char *row)
{
	char	**temp;
	int		i;

	i = 0;
	if (!row)
		return (1);
	game->height++;
	temp = (char **)malloc (sizeof(char *) * (game->height + 1));
	if (!temp)
		return (1);
	temp[game->height] = NULL;
	while (i < (game->height - 1))
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = row;
	if (game->map)
		ft_free (game->map);
	game->map = temp;
	return (0);
}

void	ft_read_map(t_struct *game, char *s)
{
	char *mapping;

	game->fd = open (s, O_RDONLY);
	if (game->fd < 0)
	{
		perror ("Error reading map");
		exit (STDERR_FILENO);
	}
	while (1)
	{
		mapping = get_next_line(game->fd);
		if (ft_adding_rows(game, mapping) == 1)
			break ;
	}
	close (game->fd);
	game->width = ft_get_width (game->map[0]);
}