/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:30 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 17:25:49 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_cub *cub)
{
	double	moveSpeed;
	int		netX;
	int		netY;

	moveSpeed = 0.01;
	netX = (int)(cub->player.x + cub->player.dir_x * moveSpeed);
	netY = (int)(cub->player.y + cub->player.dir_y * moveSpeed);
	if (cub->map.grid[netX][(int)cub->player.y] == 0)
		cub->player.x += cub->player.dir_x * moveSpeed;
	if (cub->map.grid[(int)cub->player.x][netY] == 0)
		cub->player.y += cub->player.dir_y * moveSpeed;
}

static void	move_backward(t_cub *cub)
{
	double	moveSpeed;
	int		netX;
	int		netY;

	moveSpeed = 0.01;
	netX = (int)(cub->player.x - cub->player.dir_x * moveSpeed);
	netY = (int)(cub->player.y - cub->player.dir_y * moveSpeed);
	if (cub->map.grid[netX][(int)cub->player.y] == 0)
		cub->player.x -= cub->player.dir_x * moveSpeed;
	if (cub->map.grid[(int)cub->player.x][netY] == 0)
		cub->player.y -= cub->player.dir_y * moveSpeed;
}

static void	rotate_left(t_cub *cub)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rotSpeed;

	rotSpeed = 0.003;
	oldDirX = cub->player.dir_x;
	oldPlaneX = cub->player.plane_x;
	cub->player.dir_x = cub->player.dir_x * cos(rotSpeed) - cub->player.dir_y
		* sin(rotSpeed);
	cub->player.dir_y = oldDirX * sin(rotSpeed) + cub->player.dir_y
		* cos(rotSpeed);
	cub->player.plane_x = cub->player.plane_x * cos(rotSpeed)
		- cub->player.plane_y * sin(rotSpeed);
	cub->player.plane_y = oldPlaneX * sin(rotSpeed) + cub->player.plane_y
		* cos(rotSpeed);
}

static void	rotate_right(t_cub *cub)
{
	double	oldDirX;
	double	oldPlaneX;
	double	rotSpeed;

	rotSpeed = 0.003;
	oldDirX = cub->player.dir_x;
	oldPlaneX = cub->player.plane_x;
	cub->player.dir_x = cub->player.dir_x * cos(-rotSpeed) - cub->player.dir_y
		* sin(-rotSpeed);
	cub->player.dir_y = oldDirX * sin(-rotSpeed) + cub->player.dir_y
		* cos(-rotSpeed);
	cub->player.plane_x = cub->player.plane_x * cos(-rotSpeed)
		- cub->player.plane_y * sin(-rotSpeed);
	cub->player.plane_y = oldPlaneX * sin(-rotSpeed) + cub->player.plane_y
		* cos(-rotSpeed);
}

void	handle_movement(t_cub *cub)
{
	if (cub->keys.w)
		move_forward(cub);
	if (cub->keys.s)
		move_backward(cub);
	if (cub->keys.a)
		rotate_left(cub);
	if (cub->keys.d)
		rotate_right(cub);
}
