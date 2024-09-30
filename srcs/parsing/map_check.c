/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:46:31 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 20:20:54 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strchr_cub(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	valide_map(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		while (cub->map[i][j])
		{
			if (!ft_strchr_cub("10NSEW ", cub->map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	valide_map_infos2(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = strlen(cub->map_infos[i]);
		if (!(cub->map_infos[i][j - 1] == 'm' && cub->map_infos[i][j
			- 2] == 'p' && cub->map_infos[i][j - 3] == 'x'
			&& cub->map_infos[i][j - 4] == '.'))
			return (1);
		i++;
	}
	return (0);
}

int	valide_map_infos(t_map *cub)
{
	if (cub->map_infos[0][0] != 'N' || cub->map_infos[0][1] != 'O')
		return (1);
	if (cub->map_infos[1][0] != 'S' || cub->map_infos[1][1] != 'O')
		return (2);
	if (cub->map_infos[2][0] != 'W' || cub->map_infos[2][1] != 'E')
		return (3);
	if (cub->map_infos[3][0] != 'E' || cub->map_infos[3][1] != 'A')
		return (4);
	if (cub->map_infos[4][0] != 'F')
		return (5);
	if (cub->map_infos[5][0] != 'C')
		return (6);
	if (valide_map_infos2(cub))
		return (7);
	return (0);
}

int	check_map(t_map *cub)
{
	if (valide_map(cub))
		return (1);
	if (valide_map_infos(cub))
		return (1);
	if (valide_rgb(cub))
	{
		return (1);
	}
	return (0);
}
