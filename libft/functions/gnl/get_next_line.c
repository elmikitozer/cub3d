/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:42:33 by ellehmim          #+#    #+#             */
/*   Updated: 2024/03/26 13:08:02 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 10 && str[i] != 0)
		i++;
	return (i);
}

int	gnl_find(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 10)
			return (1);
		i++;
	}
	return (0);
}

void	gnl_ft_memset(char *c, int k, int n)
{
	while (--n >= 0)
		c[n] = k;
}

int	ft_readline(int fd, char **buf)
{
	char	*temp;
	int		k;

	temp = malloc(BUFFER_SIZE + 1);
	gnl_ft_memset(temp, 0, BUFFER_SIZE + 1);
	while (!gnl_find(temp))
	{
		gnl_ft_memset(temp, 0, BUFFER_SIZE);
		k = read(fd, temp, BUFFER_SIZE);
		if (k <= 0)
		{
			if (gnl_ft_strlen(*buf) > 0)
				break ;
			free(*buf);
			*buf = 0;
			break ;
		}
		*buf = gnl_ft_strjoin(*buf, temp);
		if (k < BUFFER_SIZE)
			break ;
	}
	free(temp);
	return (k);
}

char	*get_next_line(int fd)
{
	char		*dest;
	static char	*buf;
	int			c;

	dest = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc (BUFFER_SIZE + 1);
		gnl_ft_memset(buf, 0, BUFFER_SIZE + 1);
	}
	ft_readline(fd, &buf);
	if (buf)
	{
		c = gnl_count(buf);
		dest = gnl_ft_substr(buf, 0, c + 1, 0);
		buf = gnl_ft_substr(buf, c + 1,
				gnl_ft_strlen(buf) - c - 1, 1);
	}
	return (dest);
}
// int	main(void)
// {
// 	int	fd;
// 	int	fd1;
// 	char *chaine;
// 	fd = open("testy", O_RDONLY);
// 	fd1 = open("testy", O_RDONLY);
// 	chaine = get_next_line(fd);
// 	while (chaine)
// 	{
// 		printf("[%s]\n\n",chaine);
// 		free(chaine);
// 		chaine = get_next_line(fd);
// 	}		
// 	close(fd);
// }
