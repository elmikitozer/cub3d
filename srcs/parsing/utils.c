/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:53:33 by myevou            #+#    #+#             */
/*   Updated: 2024/10/01 17:44:06 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_infos(char **map_infos)
{
	int	i;

	i = 0;
	while (map_infos[i])
		printf("%s\n", map_infos[i++]);
}

void	print_map(t_map *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
		printf("%s\n", cub->map[i++]);
}

static int	int_spawn_dir(char c)
{
	if (c == 'N')
		return (11);
	if (c == 'S')
		return (12);
	if (c == 'W')
		return (13);
	if (c == 'E')
		return (14);
	return (0);
}

static void	fill_tab(int *tab, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'S' || str[i] == 'N' || str[i] == 'W' || str[i] == 'E')
			tab[i] = int_spawn_dir(str[i]);
		else
			tab[i] = str[i] - '0';
		i++;
	}
}

int	ft_tab_atoi(t_map *cub)
{
	int	**tab;
	int	i;
	int	row;
	int	col;

	row = count_map_rgb(cub->map);
	col = ft_strlen(cub->map[0]);
	i = 0;
	tab = (int **)malloc(sizeof(int *) * row);
	if (!tab)
		return (1);
	while (i < row)
	{
		tab[i] = (int *)malloc(sizeof(int) * col);
		if (!tab[i])
			return (1);
		fill_tab(tab[i], cub->map[i]);
		i++;
	}
	cub->map_int = tab;
	return (0);
}
