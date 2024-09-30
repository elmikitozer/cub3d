/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:33:57 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 21:53:48 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_size_map(t_map *cub)
{
	int	i;

	i = 0;
	if (!cub->map)
		return (0);
	while (cub->map[i])
		i++;
	return (i);
}

int	ft_strlen_cub(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			c++;
		i++;
	}
	return (i - c);
}

void	final_map(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'X')
				cub->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

static int	to_parse(int ac, char **av, t_map *cub)
{
	creat_map(ac, av, cub);
	print_map(cub);
	if (split_map_info(cub))
		return (1);
	if (check_map(cub))
		return (1);
	if (map_playable(cub))
		return (1);
	printf("map valide\n");
	return (0);
}

int	parsing(t_cub *cub, int ac, char **av)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (printf("error\n"));
	if (to_parse(ac, av, map))
		return (printf("invalide map\n"));
	final_map(map);
	print_map(map);
	if (ft_tab_atoi(map))
		return (printf("error\n"));
	print_map_int(map);
	// free_map(map);
	cub->map = *map;
	return (0);
}
