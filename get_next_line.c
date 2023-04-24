/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:27:43 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/04/24 15:17:06 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_backup(char *backup)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (backup[i])
		s[c++] = backup[i++];
	s[c] = '\0';
	free(backup);
	return (s);
}

char	*ft_get_line(char *backup)
{
	char	*s;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	s = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		s[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		s[i] = backup[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read_backup(int fd, char *backup)
{
	char	*buffer;
	int		nb_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	nb_bytes = 1;
	while (!ft_strchr(backup, '\n') && nb_bytes != 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = ft_read_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_backup(backup);
	return (line);
}
