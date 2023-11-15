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

// int	on_destroy(t_data *data)
// {
// 	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_display(data->mlx_ptr);
// 	free(data->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

// int	on_keypress(int keysym, t_data *data)
// {
// 	(void)data;
// 	ft_printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_game	*game;
	t_img	*images;

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
