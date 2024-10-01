/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:44:38 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 16:13:26 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	steps_and_side_dist(t_cub *cub, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((ray->map_x + 1.0 - cub->player.x)
				* ray->delta_dist_x);
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((ray->map_y + 1.0 - cub->player.y)
				* ray->delta_dist_y);
	}
}

void	dda_alg(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (cub->map.grid[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
		// if (cub->map.grid[ray->map_y][ray->map_x] == 1)
		// 	ray->hit = 1;
	}
}

void	wall_distance(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - cub->player.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - cub->player.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	line_height(t_cub *cub, t_ray *ray)
{
	ray->line_height = (int)(cub->screen_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + cub->screen_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + cub->screen_height / 2;
	if (ray->draw_end >= cub->screen_height)
		ray->draw_end = cub->screen_height - 1;
}

