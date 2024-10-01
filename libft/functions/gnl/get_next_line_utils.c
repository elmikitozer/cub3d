/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:24:55 by ellehmim          #+#    #+#             */
/*   Updated: 2024/03/26 12:40:47 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = -1;
	j = -1;
	if (!s2)
		return (NULL);
	dest = malloc((gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1 && s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	if (s1)
		free (s1);
	return (dest);
}

char	*gnl_ft_substr(char *s, int start, int len, int f)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (start > gnl_ft_strlen(s))
		len = 0;
	else if (len > gnl_ft_strlen(s + start))
		len = gnl_ft_strlen(s + start);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (len > 0)
	{
		dest[i++] = s[start++];
		len--;
	}
	dest[i] = '\0';
	if (f)
		free(s);
	return (dest);
}
