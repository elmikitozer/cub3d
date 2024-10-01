/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellehmim <ellehmim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:28:09 by ellehmim          #+#    #+#             */
/*   Updated: 2024/03/26 12:41:14 by ellehmim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*gnl_ft_substr(char *s, int start, int len, int f);
char	*gnl_ft_strjoin(char *s1, char *s2);
int		gnl_ft_strlen(char *str);
int		gnl_count(char *str);
int		gnl_find(char *str);
int		ft_readline(int fd, char **buf);
void	gnl_ft_memset(char *c, int k, int n);
void	ft_strcpy(char *dest, char *s, int start, int len);

#endif
