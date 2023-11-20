/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/20 11:22:23 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_struct	game;

	if (ac != 2)
		ft_exit ("Error: no map name", 0, game.exit_code++);
	//safely make space for program memory on the stack
	ft_memset (&game, 0, sizeof(t_struct));
	ft_read_map (&game, av[1]);
	ft_error_check (&game);
	game.mlx_ptr = mlx_init ();
	if (game.mlx_ptr == NULL)
		ft_exit ("Error: initializing mlx", &game, game.exit_code++);
	game.win_ptr = mlx_new_window(game.mlx_ptr, \
		(game.map_width * 40), (game.map_height * 40), "So Long");
	if (game.win_ptr == NULL)
		ft_exit ("Error: initializing window", &game, game.exit_code++);
	ft_set_images (&game);
	ft_set_graphics (&game);
	mlx_key_hook(game.win_ptr, ft_controls, &game);
	mlx_hook(game.win_ptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx_ptr);
}
