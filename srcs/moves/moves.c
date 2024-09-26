/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:30 by myevou            #+#    #+#             */
/*   Updated: 2024/09/26 14:52:04 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int exit_game(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
	return (0);
}

int key_press(int keycode, t_cub *cub)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(cub->mlx, cub->img_ptr);
		mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		// mlx_loop_end(cub->mlx);
		exit_game(cub);
	}
	return (0);
}
