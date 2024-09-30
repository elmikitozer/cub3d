/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:14:59 by ellehmim          #+#    #+#             */
/*   Updated: 2024/09/30 20:20:54 by myevou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*so_dup(char *str, char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*so_join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
	{
		if (s1)
			free(s1);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		if (s1)
			free(s1);
		return (0);
	}
	str = so_dup(str, s1, s2);
	free(s1);
	return (str);
}

int	line_map(t_map *cub, char *av, char **chain)
{
	char	*buffer;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		msg_error(cub);
	*chain = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		*chain = so_join(*chain, buffer);
		if (*chain == 0)
		{
			free(chain);
			return (0);
		}
		if (buffer)
			free(buffer);
	}
	close(fd);
	return (1);
}

void	valide_file(t_map *cub, char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'b') || !(str[i - 2] == 'u') || !(str[i - 3] == 'c')
		|| !(str[i - 4] == '.'))
		msg_error(cub);
}

void	creat_map(int ac, char **av, t_map *cub)
{
	char	*chain;

	if (ac != 2)
		exit(EXIT_FAILURE);
	valide_file(cub, av[1]);
	if (line_map(cub, av[1], &chain) == 0)
		exit(EXIT_FAILURE);
	cub->map = 0;
	cub->map = ft_split(chain, '\n');
	if (!cub->map)
	{
		free(chain);
		msg_error(cub);
	}
	free(chain);
}
