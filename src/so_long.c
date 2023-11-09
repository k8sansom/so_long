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

int main(void)
{
    void	*mlx_ptr;
	void	*mlx_window;
	int		y;
	int		x;

	//srand (time (NULL));
	y = HEIGHT * 0.1;
    mlx_ptr = mlx_init();
    mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "I did it!");
	while (y < HEIGHT * 0.9)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH * 0.9)
		{
			mlx_pixel_put (mlx_ptr, mlx_window, x, y, PURPLE);
			x++;
		}
		y++;
	}
	mlx_string_put (mlx_ptr, mlx_window, WIDTH * 0.8, HEIGHT * 0.95, rand () % 0x1000000, "by K8");
	mlx_loop(mlx_ptr);
}
