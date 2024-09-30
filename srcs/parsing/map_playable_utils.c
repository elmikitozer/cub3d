/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:35:21 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 20:14:25 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	position_player(char **map, char c, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (map[i][j + 1] == 'X' || map[i][j - 1] == 'X' || map[i + 1][j] == 'X'
			|| map[i - 1][j] == 'X')
			return (1);
	}
	return (0);
}

int	map_close(char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_cpy[i])
	{
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == '0')
			{
				if (map_cpy[i][j + 1] == 'X' || map_cpy[i][j - 1] == 'X'
					|| map_cpy[i + 1][j] == 'X' || map_cpy[i - 1][j] == 'X')
					return (1);
			}
			if (ft_strchr_cub("NEWS", map_cpy[i][j]))
				if (position_player(map_cpy, map_cpy[i][j], i, j))
					return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
