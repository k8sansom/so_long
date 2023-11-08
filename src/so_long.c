/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/08 15:53:55 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	void	*mlx_cnx;
	void	*window;

	mlx_cnx = mlx_init ();
	window = mlx_new_window(mlx_cnx, HEIGHT, WIDTH, "I did it!");
	mlx_loop (mlx_cnx);
}
