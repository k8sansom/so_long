/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 16:15:30 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_struct	*game;

	if (ac != 2)
	{
		perror ("Please provide a map name");
		exit (STDERR_FILENO);
	}
	//safely initialize all the pointers in the struct to NULL
	ft_memset(&game, 0, sizeof(t_struct));
	//read map
	ft_read_map(&game, av[1]);
	game.mlx_ptr = mlx_init ();
	if (game.mlx_ptr == NULL)
		return (1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIDTH, HEIGHT, "new window :)");
	if (game.win_ptr == NULL)
	{
		mlx_destroy_display(game.mlx_ptr);
		return (free(game.mlx_ptr), 1);
	}
	mlx_loop(game.mlx_ptr);
	game.textures = mlx_xpm_file_to_image(game.mlx_ptr, BG_IMG, (int *)400, \
		(int *)400);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.textures, 2, 2);
	// // mlx_hook (game.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// mlx_hook (
	// 	game.win_ptr, 
	// 	DestroyNotify, 
	// 	StructureNotifyMask, 
	// 	&on_destroy, 
	// 	&game);
	
	free(game.mlx_ptr);
	return (0);
}
