/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:10:20 by myevou            #+#    #+#             */
/*   Updated: 2024/09/27 12:00:02 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/* ************************************************************************** */
/*                               RAYCASTING                                   */
/* ************************************************************************** */

// INIT
void	init_cub(t_cub *cub);
void	init_player_keys(t_cub *cub);
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
int		exit_cub(t_cub *cub);
int		key_press(int keycode, t_cub *cub);

// DRAW
void	draw_wall(t_cub *cub, t_ray *ray, int x);
void	load_texture(t_cub *cub, t_texture *texture, char *path);
void	draw_ceiling_and_floor(t_cub *cub);

// MOVES
void	handle_movement(t_cub *cub);
int		mouse_move(int x, int y, t_cub *cub);

// KEYS
int		key_press(int keycode, t_cub *cub);
int		key_release(int keycode, t_cub *cub);

// MAIN LOOP
int		rc_loop(t_cub *cub);
void	init_map(t_cub *cub);

#endif
