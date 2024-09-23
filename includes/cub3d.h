/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:10:20 by myevou            #+#    #+#             */
/*   Updated: 2024/09/23 14:01:34 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include <math.h>

/* ************************************************************************** */
/*                               RAYCASTING                                   */
/* ************************************************************************** */

// INIT
void	init_cub(t_cub *cub);
void	init_player(t_cub *cub);
void	init_ray(t_cub *cub, t_ray *ray, int x);
void	init_textures(t_cub *cub);
void	init(t_cub *cub);

// RAYCASTING
void	raycasting(t_cub *cub);

// Utils
void	steps_and_side_dist(t_cub *cub, t_ray *ray);
void	dda_alg(t_cub *cub, t_ray *ray);
void	wall_distance(t_cub *cub, t_ray *ray);
void	line_height(t_cub *cub, t_ray *ray);

// DRAW
void	draw_wall(t_cub *cub, t_ray *ray, int x);
void	load_texture(t_cub *cub, t_texture *texture, char *path);


#endif
