/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:43:05 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 17:23:58 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	exit_cub(t_cub *cub)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 4)
// 	{
// 		if (cub->texture[i].img_ptr)
// 			mlx_destroy_image(cub->mlx, cub->texture[i].img_ptr);
// 	}
// 	if (cub->img_ptr)
// 		mlx_destroy_image(cub->mlx, cub->img_ptr);
// 	if (cub->win)
// 		mlx_destroy_window(cub->mlx, cub->win);
// 	if (cub->map.grid)
// 	{
// 		i = -1;
// 		while (++i < cub->map.height)
// 			free(cub->map.grid[i]);
// 		free(cub->map.grid);
// 	}
// 	if (cub->mlx)
// 		mlx_destroy_display(cub->mlx);
// 	free(cub->mlx);
// 	exit(0);
// 	return (0);
// }

int exit_cub(t_cub *cub)
{
	if (cub->texture[0].img_ptr)
		mlx_destroy_image(cub->mlx, cub->texture[0].img_ptr);
	if (cub->texture[1].img_ptr)
		mlx_destroy_image(cub->mlx, cub->texture[1].img_ptr);
	if (cub->texture[2].img_ptr)
		mlx_destroy_image(cub->mlx, cub->texture[2].img_ptr);
	if (cub->texture[3].img_ptr)
		mlx_destroy_image(cub->mlx, cub->texture[3].img_ptr);
	free_map(&cub->map);
	// if(cub->map.grid)
	// {
	// 	int i = -1;
	// 	while (++i < cub->map.height)
	// 		free(cub->map.grid[i]);
	// 	free(cub->map.grid);
	// }
	mlx_destroy_image(cub->mlx, cub->img_ptr);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	// free(cub->ma)
	free(cub->mlx);
	exit(0);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	static int	prev_x = -1;
	double		rotSpeed;
	int			delta_x;
	double		olddir_x;
	double		oldplane_x;

	(void)y;
	if (prev_x == -1)
		prev_x = x;
	delta_x = x - prev_x;
	prev_x = x;
	rotSpeed = delta_x * 0.02;
	olddir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(-rotSpeed) - cub->player.dir_y
		* sin(-rotSpeed);
	cub->player.dir_y = olddir_x * sin(-rotSpeed) + cub->player.dir_y
		* cos(-rotSpeed);
	oldplane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(-rotSpeed)
		- cub->player.plane_y * sin(-rotSpeed);
	cub->player.plane_y = oldplane_x * sin(-rotSpeed) + cub->player.plane_y
		* cos(-rotSpeed);
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		exit_cub(cub);
	else if (keycode == 119 || keycode == 65362) // 'w' ou Flèche Haut
		cub->keys.w = 1;
	else if (keycode == 115 || keycode == 65364) // 's' ou Flèche Bas
		cub->keys.s = 1;
	else if (keycode == 97 || keycode == 65361) // 'a' ou Flèche Gauche
		cub->keys.a = 1;
	else if (keycode == 100 || keycode == 65363) // 'd' ou Flèche Droite
		cub->keys.d = 1;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 119 || keycode == 65362) // 'w' ou Flèche Haut
		cub->keys.w = 0;
	else if (keycode == 115 || keycode == 65364) // 's' ou Flèche Bas
		cub->keys.s = 0;
	else if (keycode == 97 || keycode == 65361) // 'a' ou Flèche Gauche
		cub->keys.a = 0;
	else if (keycode == 100 || keycode == 65363) // 'd' ou Flèche Droite
		cub->keys.d = 0;
	return (0);
}
