/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:36:31 by myevou            #+#    #+#             */
/*   Updated: 2024/09/23 13:59:27 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_map
{
	int			**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	int			tex_num;
}				t_ray;

typedef struct s_texture
{
	void		*img_ptr;
	char		*data;
	int 		width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	int			screen_width;
	int			screen_height;
	char		*img_data;
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	t_texture	texture[4];
	t_map		map;
	t_player	player;
}				t_cub;

#endif
