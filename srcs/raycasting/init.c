/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:16:34 by myevou            #+#    #+#             */
/*   Updated: 2024/09/26 14:30:29 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->screen_width = 600;
	cub->screen_height = 480;
	cub->win = mlx_new_window(cub->mlx, cub->screen_width, cub->screen_height,
			"cub3d");
	cub->img_ptr = mlx_new_image(cub->mlx, cub->screen_width,
			cub->screen_height);
	if (!cub->img_ptr)
	{
		printf("Erreur : Impossible de créer l'image principale\n");
		exit(1);
	}
	cub->img_data = mlx_get_data_addr(cub->img_ptr, &cub->bpp,
			&cub->size_line, &cub->endian);
}

void	init_player(t_cub *cub)
{
	cub->player.x = 7.0;
	cub->player.y = 7.0;
	cub->player.dir_x = -1.0;   // Initial direction: doit changer
	cub->player.dir_y = 0.0;    // en fonction du N, S, E, W
	cub->player.plane_x = 0.0;  // plan cam perpendiculaire à dir
	cub->player.plane_y = 0.66; // FOV a 66°
}

void	init_ray(t_cub *cub, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)cub->screen_width - 1;
		// x-coordinate in camera space = direction du rayon en fonction de la position sur l'ecran
	ray->ray_dir_x = cub->player.dir_x + cub->player.plane_x * ray->camera_x;
		// direction of ray
	ray->ray_dir_y = cub->player.dir_y + cub->player.plane_y * ray->camera_x;
		// direction of ray
	ray->map_x = (int)cub->player.x;
		// position initiale de la grille (map_x,
			//map_y) (en convertissant la pos du joueur on sait dans quelle case de la grille il est)
	ray->map_y = (int)cub->player.y;
		// position initiale de la grille (map_x,
			//map_y) (en convertissant la pos du joueur on sait dans quelle case de la grille il est)
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	// ray->delta_dist_x = ray->ray_dir_x == 0 ? 1e30 : fabs(1 / ray->ray_dir_x);
		// length of ray from one x or y-side to next x or y-side
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	// ray->delta_dist_y = ray->ray_dir_y == 0 ? 1e30 : fabs(1 / ray->ray_dir_y);
		// length of ray from one x or y-side to next x or y-side
	ray->hit = 0;
		// hit a wall
}

void	init_textures(t_cub *cub)
{
	load_texture(cub, &cub->texture[0], "textures/north.xpm"); // Texture Nord
	load_texture(cub, &cub->texture[1], "textures/south.xpm"); // Texture Sud
	load_texture(cub, &cub->texture[2], "textures/east.xpm");  // Texture Est
	load_texture(cub, &cub->texture[3], "textures/west.xpm");  // Texture Ouest
}

void	init(t_cub *cub)
{
	init_cub(cub);
	init_player(cub);
	init_map(cub);
	init_textures(cub);
}
