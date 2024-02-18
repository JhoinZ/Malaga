/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:19:34 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/02/18 18:22:46 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_left(char *buff)
{
	int		len_buff;
	int		i;
	char	*new_buff;

	len_buff = 0;
	while (buff[len_buff] != '\n' && buff[len_buff] != '\0')
		len_buff++;
	if (buff[len_buff] == '\0')
		return (free(buff), NULL);
	if (buff[len_buff] == '\n')
		len_buff++;
	new_buff = ft_calloc((ft_strlen(buff) - len_buff + 1), sizeof(char));
	if (!new_buff)
		return (free(buff), NULL);
	i = 0;
	while (buff[len_buff] != '\0')
	{
		new_buff[i] = buff[len_buff];
		i++;
		len_buff++;
	}
	new_buff[i] = '\0';
	free(buff);
	return (new_buff);
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
	if (buff[i] == '\n')
		i++;
	newline = ft_calloc((i + 1), sizeof(char));
	if (!newline)
		return (NULL);
	j = 0;
	while (i > j)
	{
		newline[j] = buff[j];
		j++;
	}
	newline[j] = '\0';
	return (newline);
}

static char	*read_buff(int fd, char *buff)
{
	int		bytes_read;
	char	*copy;

	copy = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!copy)
		return (free(buff), NULL);
	bytes_read = 1;
	while (!ft_strchr(copy, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, copy, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(copy), NULL);
		copy[bytes_read] = '\0';
		if (copy[0] != '\0')
			buff = ft_strcat_mal(buff, copy);
	}
	return (free(copy), buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_buff(fd, buff[fd]);
	if (!buff)
		return (NULL);
	next = new_line(buff[fd]);
	buff[fd] = buffer_left(buff[fd]);
	return (next);
}
