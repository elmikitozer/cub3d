/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myevou <myevou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:05:55 by myevou           #+#    #+#             */
/*   Updated: 2024/04/16 16:06:13 by myevou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_put_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

// int main()
// {
// 	 ft_put_percent();
// 	 return 0;
// }
