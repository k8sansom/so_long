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
	t_struct	game;

	if (ac != 2)
		ft_error ("Please provide a map name", 0);
	//safely initialize all the programs memory on the stack
	ft_memset (&game, 0, sizeof(t_struct));
	ft_read_map (&game, av[1]);
	ft_error_check (&game);
	game.mlx_ptr = mlx_init ();
	if (game.mlx_ptr == NULL)
		ft_error ("Error initializing mlx", &game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.width * 40), (game.height * 40), "So Long");
	if (game.win_ptr == NULL)
		ft_error ("Error initializing window", &game);
	ft_set_images (&game);
	ft_set_graphics (&game);
	mlx_key_hook(game.win_ptr, controls_working, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
}
