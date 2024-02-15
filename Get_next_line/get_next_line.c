/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:45:42 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/02/15 16:59:53 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buff(int fd, static char *buff, char *next)
{
	size_t	read_buff;
	char	*copy;

	while (!ft_strchr(copy, '\n'))
	{
		num = read(fd, copy, BUFFER_SIZE);
		if (num > 0)
			copy[num] = '\0';
		else
			return (NULL);
	}
	free(copy);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = read_buff(fd, buff, next);
	if (!buff)
		return (NULL);
	return (next);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/Users/fsaffiri/Corso/Get_next_line/test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
} */
