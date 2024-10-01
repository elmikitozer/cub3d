/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:13:24 by ellehmim          #+#    #+#             */
/*   Updated: 2024/10/01 17:41:37 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	msg_error(t_map *cub)
{
	free(cub);
	printf("error\n");
	exit(1);
}

void	print_map_int(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	// printf("Map int:\n");
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
			printf("%d ", cub->map_int[i][j++]);
		printf("\n");
		i++;
	}
}

void	free_map(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
		free(cub->grid[i++]);
	free_map2(cub->map);
	free_map2(cub->map_infos);
	free(cub->grid);
	// free(cub);
}

void	free_map2(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
