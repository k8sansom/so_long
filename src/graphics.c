#include "../inc/so_long.h"

int	ft_set_graphics(t_struct *game)
{
	int	height;
	int width;

	height = 0;
	while (height < game->mapheight)
	{
		width = 0;
		while (game->map[height][width])
		{
			
		}
	}
}

void	ft_set_images(t_struct *game)
{
	int	x;
	int	y;

	game->ground = mlx_xpm_file_to_image (game->mlx_ptr, "assets/floor.rpm", &x, &y);
	game->wall = mlx_xpm_file_to_image (game->mlx_ptr, "assets/wall.rpm", &x, &y);
	game->player = mlx_xpm_file_to_image (game->mlx_ptr, "assets/Kate.rpm", &x, &y);
	game->collectable = mlx_xpm_file_to_image (game->mlx_ptr, "assets/wine.rpm", &x, &y);
	game->exit = mlx_xpm_file_to_image (game->mlx_ptr, "assets/toilet.rpm", &x, &y);
}