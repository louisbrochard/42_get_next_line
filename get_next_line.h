/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:28:51 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/04/24 15:44:23 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
char	*ft_read_backup(int fd, char *backup);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *string, int searchedChar );
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(char *theString);

#endif
