/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:55:30 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 20:20:54 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	print_map_local(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

char	*first_and_last_line(char **map)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > j)
			j = ft_strlen(map[i]);
		i++;
	}
	dest = (char *)malloc(sizeof(char) * (j + 3));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < j + 2)
	{
		dest[i] = 'X';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*copy_map_line(char *str, int f)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 1;
	dest = (char *)malloc(sizeof(char) * f + 1);
	if (!dest)
		return (NULL);
	dest[0] = 'X';
	while (str[i])
	{
		if (ft_strchr_cub("01NEWS", str[i]))
			dest[j] = str[i];
		else
			dest[j] = 'X';
		i++;
		j++;
	}
	while (j < f)
		dest[j++] = 'X';
	dest[j] = '\0';
	return (dest);
}

char	**copy_map_playable(char **map)
{
	char	**dest;
	int		i;
	int		j;

	i = 1;
	dest = (char **)malloc(sizeof(char *) * (count_map_rgb(map) + 3));
	if (!dest)
		return (NULL);
	dest[0] = first_and_last_line(map);
	j = ft_strlen(dest[0]);
	while (i < count_map_rgb(map) + 1)
	{
		dest[i] = copy_map_line(map[i - 1], j);
		i++;
	}
	dest[i] = first_and_last_line(map);
	dest[i + 1] = NULL;
	free_map2(map);
	return (dest);
}

char	**overlay_the_map(char **map, char **map_cpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_cpy[i] && map[i])
	{
		while (map[i][j])
		{
			if (ft_strchr_cub("01NEWS", map[i][j]))
				map_cpy[i][j] = map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (map_cpy);
}

int	map_playable(t_map *cub)
{
	cub->map = copy_map_playable(cub->map);
	if (!cub->map)
		return (1);
	if (map_close(cub->map))
		return (1);
	return (0);
}

// int	map_playable(t_map *cub)
// {
// 	cub->map = copy_map_playable(cub->map);
// 	if (!cub->map)
// 		return (1);
// 	print_map_local(cub->map);
// 	if (map_close(cub->map))
// 		return (1);
// 	return (0);
// }
