/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:26:41 by myevou            #+#    #+#             */
/*   Updated: 2024/09/23 14:27:40 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static clear_image(t_cub *cub)
{
	ft_bzero(cub->img_data, cub->screen_width * cub->screen_height * 4);
}

int	rc_loop(t_cub *cub)
{
	clear_image(cub);
	raycasting(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
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
		steps_and_side_dist(cub, &ray);
		dda_alg(cub, &ray);
		wall_distance(cub, &ray);
		line_height(cub, &ray);
		draw_wall(cub, &ray, x);
		x++;
	}
}
