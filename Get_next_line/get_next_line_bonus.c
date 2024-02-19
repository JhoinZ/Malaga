/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:44 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/02/19 17:15:16 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_left(char *buff)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\n' && buff[i])
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new_buff = ft_calloc(sizeof(char), (ft_strlen(buff) - i + 1));
	if (!new_buff)
		return (free(buff), NULL);
	i += 1;
	j = 0;
	while (buff[i])
		new_buff[j++] = buff[i++];
	new_buff[j] = '\0';
	return (free(buff), new_buff);
}

char	*new_line(char *buff)
{
	char			*newline;
	unsigned int	i;
	unsigned int	j;

	if (buff[0] == '\0')
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	newline = ft_calloc(sizeof(char), (i + 2));
	if (!newline)
		return (NULL);
	j = 0;
	while (buff[j] != '\n' && buff[j] != '\0')
	{
		newline[j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
		newline[j++] = '\n';
	newline[j] = '\0';
	return (newline);
}

static char	*read_buff(int fd, char *buff)
{
	int		bytes_read;
	char	*copy;

	copy = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!copy)
		return (NULL);
	bytes_read = 1;
	if (!buff)
		buff = ft_strdup("");
	while (!ft_strchr(buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, copy, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(copy), NULL);
		copy[bytes_read] = '\0';
		buff = ft_strjoin(copy, buff);
	}
	return (free(copy), buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD] = {NULL};
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff[fd], 0) < 0)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	buff[fd] = read_buff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	next = new_line(buff[fd]);
	buff[fd] = buffer_left(buff[fd]);
	return (next);
}
