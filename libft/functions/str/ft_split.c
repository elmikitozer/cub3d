/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:46:36 by ellehmim          #+#    #+#             */
/*   Updated: 2023/11/25 16:46:45 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	countwords(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		n++;
		i++;
	}
	return (n);
}

static void	remptab(char *dest, const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest [i] = '\0';
}

static void	tabl(char **tab, const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			count++;
		if (count > 0)
		{
			tab[j] = malloc((count + 1) * sizeof(char));
			if (!tab[j])
				return ;
			remptab(tab[j], (s + i), c);
			j++;
			i += count;
		}
		else
			i++;
	}
	tab[j] = 0;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s)
		return (NULL);
	len = countwords(s, c);
	tab = malloc((len + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tabl(tab, s, c);
	return (tab);
}
