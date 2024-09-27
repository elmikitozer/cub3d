/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:26:41 by myevou            #+#    #+#             */
/*   Updated: 2024/09/27 11:51:13 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void clear_image(t_cub *cub)
{
	// ft_bzero(cub->img_data, cub->screen_width * cub->screen_height * 4);
	memset(cub->img_data, 0, cub->screen_width * cub->screen_height * 4);
}

int	rc_loop(t_cub *cub)
{
	handle_movement(cub);
	clear_image(cub);
	draw_ceiling_and_floor(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img_ptr, 0, 0);
	return (0);
}

void	raycasting(t_cub *cub)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < cub->screen_width)
	{
		init_ray(cub, &ray, x);
		// printf("Ray %d: cameraX=%f, rayDirX=%f, rayDirY=%f\n", x, ray.camera_x, ray.ray_dir_x, ray.ray_dir_y);
		steps_and_side_dist(cub, &ray);
		dda_alg(cub, &ray);
		wall_distance(cub, &ray);
		line_height(cub, &ray);
		// printf("Ray %d: mapX=%d, mapY=%d, side=%d, perpWallDist=%f\n", x, ray.map_x, ray.map_y, ray.side, ray.perp_wall_dist);
		draw_wall(cub, &ray, x);
		x++;
	}
}
