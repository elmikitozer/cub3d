/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:52:44 by myevou           #+#    #+#             */
/*   Updated: 2023/11/06 14:52:44 by myevou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//sets the first n bytes of the memory area pointed to by b to zero
void	ft_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	if (n == 0)
		return ;
	dest = b;
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}
