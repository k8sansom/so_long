/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:21 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 11:12:39 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define HEIGHT 500
# define WIDTH 800
# define PURPLE 0xff00ff

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	//void		*textures[5];
	//t_map		*map; 
}	t_data;

#endif