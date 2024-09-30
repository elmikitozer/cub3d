/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:30:40 by myevou            #+#    #+#             */
/*   Updated: 2024/09/30 22:34:38 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_map_data(t_cub *cub)
{
	// int	mapData[12][14] = {
	// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	// 	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	// 	};
	int	i;
	int	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			cub->map.grid[i][j] = cub->map.map_int[i][j];
			j++;
		}
		i++;
	}
}

void	init_map(t_cub *cub)
{
	int	i;

	cub->map.height = count_map_rgb(cub->map.map);  // Remplace par la largeur réelle de ta carte
	cub->map.width = ft_strlen(cub->map.map[0]); // Remplace par la largeur réelle de ta carte
	return ;
	// // Allocation de la matrice 2D
	cub->map.grid = (int **)malloc(sizeof(int *) * cub->map.height + 1);
	if (!cub->map.grid)
		exit_cub(cub);
	i = 0;
	while (i < cub->map.height + 1)
	{
		cub->map.grid[i] = (int *)malloc(sizeof(int) * cub->map.width + 1);
		if (!cub->map.grid[i])
			exit_cub(cub);;
		i++;
	}
	// Chargement des données de la carte
	// load_map_data(cub);
}
