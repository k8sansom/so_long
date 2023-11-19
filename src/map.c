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
	game->mapheight++;
	temp = (char **)malloc (sizeof(char *) * (game->mapheight + 1));
	if (!temp)
		ft_error ("Error: allocating memory for map", &game);
	temp[game->mapheight] = NULL;
	while (i < (game->mapheight - 1))
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
		ft_error ("Error: reading map", &game);
	while (1)
	{
		mapping = get_next_line(game->fd);
		if (ft_adding_rows(game, mapping) == 1)
			break ;
	}
	close (game->fd);
	game->mapwidth = ft_get_width (game->map[0]);
}