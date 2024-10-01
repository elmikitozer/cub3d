/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:22:26 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 18:00:02 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// colors are red, green, blue and white
// static int	get_wall_color(t_cub *cub, t_ray *ray)
// {
// 	int	color;

// 	if (cub->map.grid[ray->map_x][ray->map_y] == 1)
// 		color = 0xFF0000;
// 	if (cub->map.grid[ray->map_x][ray->map_y] == 1)
// 		color = 0x00FF00;
// 	if (cub->map.grid[ray->map_x][ray->map_y] == 1)
// 		color = 0x0000FF;
// 	else
// 		color = 0xFFFFFF;
// 	if (ray->side == 1)
// 		color = color / 2;
// 	return (color);
// }

// static void draw_line(t_cub *cub, int x, t_ray *ray, int color)
// {
// 	int y;
// 	char *dst;

// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		dst = cub->im +
// 	}
// }

void	load_texture(t_cub *cub, t_texture *texture, char *path)
{
	texture->img_ptr = mlx_xpm_file_to_image(cub->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img_ptr)
	{
		printf("Error\nTexture non trouvee\n");
		exit_cub(cub);
	}
	texture->data = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->img_ptr || !texture->data)
	{
		printf("Erreur lors du chargement de la texture\n");
		exit_cub(cub);
	}
}

// void	draw_wall(t_cub *cub, t_ray *ray, int x)
// {
// 	int	color;

// 	color = get_wall_color(cub, ray);
// 	draw_line(cub, x, ray, color);
// 	// y = ray->draw_start;
// 	// while (y < ray->draw_end)
// 	// {
// 	// 	// color = get_color(ray->side);
// 	// 	// put_pixel(cub, x, y, color);
// 	// 	y++;
// 	// }
// 	// A VOIR COMMENT FAIRE PUISQUE LES MURS SONT DES IMAGES
// }

static void	select_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			ray->tex_num = 3; // Ouest
		else
			ray->tex_num = 2; // Est
	}
	else
	{
		if (ray->ray_dir_y > 0)
			ray->tex_num = 0; // Nord
		else
			ray->tex_num = 1; // Sud
	}
	// SI PROBLEME AVEC LES TEXTURES COMME AUREL ET THOMAS ==>
	// {
	// 	if (ray->ray_dir_x > 0)
	// 		ray->tex_num = 0;
	// 	else
	// 		ray->tex_num = 1;
	// }
	// else
	// {
	// 	if (ray->ray_dir_y > 0)
	// 		ray->tex_num = 2;
	// 	else
	// 		ray->tex_num = 3;
	// }
}

static void	wall_x(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = cub->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = cub->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	tex_x(t_cub *cub, t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * (double)cub->texture[ray->tex_num].width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		ray->tex_x = cub->texture[ray->tex_num].width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		ray->tex_x = cub->texture[ray->tex_num].width - ray->tex_x - 1;
}

static int	get_texture_color(t_texture *texture, int x, int y)
{
	int		color;
	char	*dst;

	dst = texture->data + (y * texture->size_line + x * (texture->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static void	put_pixel_to_image(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= cub->screen_width || y < 0 || y >= cub->screen_height)
		return ;
	dst = cub->img_data + (y * cub->size_line + x * (cub->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_textured_line(t_cub *cub, t_ray *ray, int x)
{
	int			y;
	int			texY;
	double		step;
	double		texPos;
	int			color;
	t_texture	tex;

	tex = cub->texture[ray->tex_num];
	step = 1.0 * tex.height / ray->line_height;
	texPos = (ray->draw_start - cub->screen_height / 2 + ray->line_height / 2)
		* step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texY = (int)texPos % (tex.height - 1);
		texPos += step;
		color = get_texture_color(&tex, ray->tex_x, texY);
		if (ray->side == 1)
			color = (color >> 1) & 8355711; // Assombrir pour les murs sur Y
		// printf("Pixel Color at (%d, %d): %#X\n", x, y, color);
		put_pixel_to_image(cub, x, y, color);
		y++;
	}
}

void	draw_wall(t_cub *cub, t_ray *ray, int x)
{
	select_texture(ray);
	wall_x(cub, ray);
	tex_x(cub, ray);
	draw_textured_line(cub, ray, x);
}

void	draw_ceiling_and_floor(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->screen_height / 2)
	{
		x = 0;
		while (x < cub->screen_width)
			put_pixel_to_image(cub, x++, y, cub->ceiling_color);
		y++;
	}
	y = cub->screen_height / 2;
	while (y < cub->screen_height)
	{
		x = 0;
		while (x < cub->screen_width)
			put_pixel_to_image(cub, x++, y, cub->floor_color);
		y++;
	}
}
