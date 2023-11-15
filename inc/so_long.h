/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:21 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/15 14:23:24 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define HEIGHT 810
# define WIDTH 810
# define BG_IMG "../assets/Beach_overworld.xpm"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures;
	//t_map		*map; 
}	t_data;

#endif