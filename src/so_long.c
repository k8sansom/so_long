/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 13:34:51 by ksansom          ###   ########.fr       */
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

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "new window :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	data.textures = mlx_xpm_file_to_image(data.mlx_ptr, BG_IMG, \
		(int *)WIDTH, (int *)HEIGHT);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures, 1, 1);
	// mlx_hook (data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	// mlx_hook (
	// 	data.win_ptr, 
	// 	DestroyNotify, 
	// 	StructureNotifyMask, 
	// 	&on_destroy, 
	// 	&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
