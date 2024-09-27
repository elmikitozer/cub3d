/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:30:40 by myevou            #+#    #+#             */
/*   Updated: 2024/09/27 17:46:04 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_map_data(t_cub *cub)
{
	int	mapData[14][14] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
	int	i;
	int	j;

	i = 0;
	while (i < cub->map.height)
	{
		j = 0;
		while (j < cub->map.width)
		{
			cub->map.grid[i][j] = mapData[i][j];
			j++;
		}
		i++;
	}
}

void	init_map(t_cub *cub)
{
	int	i;

	cub->map.width = 14;  // Remplace par la largeur réelle de ta carte
	cub->map.height = 14; // Remplace par la hauteur réelle de ta carte
	// Allocation de la matrice 2D
	cub->map.grid = (int **)malloc(sizeof(int *) * cub->map.height);
	if (!cub->map.grid)
		exit(1);
	i = 0;
	while (i < cub->map.height)
	{
		cub->map.grid[i] = (int *)malloc(sizeof(int) * cub->map.width);
		if (!cub->map.grid[i])
			exit(1);
		i++;
	}
	// Chargement des données de la carte
	load_map_data(cub);
}
