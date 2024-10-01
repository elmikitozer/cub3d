/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:10:20 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 17:58:27 by myevou           ###   ########.fr       */
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
/*                                PARSING                                     */
/* ************************************************************************** */

/*parsing*/
int		ft_strlen_cub(char *str);
int		count_size_map(t_map *cub);
int		parsing(t_cub *cub, int ac, char **av);

/*map_creat*/
int	    line_map(t_map *cub, char *av, char **chain);
char	*so_join(char *s1, char *s2);
char	*so_dup(char *str, char *s1, char *s2);
void	creat_map(int ac, char **av, t_map *cub);
void	valide_file(t_map *cub, char *str);

/*map_split*/
int  	split_map_info(t_map *cub);
int		start_map(t_map *cub);
char	*map_infos_line(char *str);
char	**copy_only_map(t_map *cub, int i);
char	**copy_only_map_infos(t_map *cub, int i);

/*map_check*/
int		check_map(t_map *cub);
int		valide_map_infos(t_map *cub);
int		valide_map_infos2(t_map *cub);
int		valide_map(t_map *cub);
int		ft_strchr_cub(const char *str, char c);

/*map_check_utils*/
int		valide_rgb(t_map *cub);
int		value_rgb(char **rgb);
int		count_map_rgb(char **str);
char	*new_line(char *str);

/*map_playable*/
int		map_playable(t_map *cub);
char	**copy_map_playable(char **map);
char	**overlay_the_map(char **map, char **map_cpy);
char	*copy_map_line(char *str, int f);
char	*first_and_last_line(char **map);

/*map_playable_utils*/
int		map_close(char **map_cpy);
int		position_player(char **map, char c, int i, int j);

/*provisoir*/
void	free_map(t_map *cub);
void	print_map(t_map *cub);
void    msg_error(t_map *cub);
void	print_map_infos(char **map_infos);
void	free_map2(char **map);

/* utils */
int ft_tab_atoi(t_map *cub);
void	print_map_int(t_map *cub);


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
void	print_map_grid(t_map *cub);

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
