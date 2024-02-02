/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:45:42 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/02/02 17:17:36 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*taglio(char *cont)
{
	unsigned int	i;
	char			*tmp;
	char			*new;

	tmp = ft_strchr(cont, '\n');
	if (tmp == NULL)
	{
		tmp = ft_strchr(cont, '\0');
		if (tmp == NULL)
			return (NULL);
	}
	new = malloc(ft_strlen(tmp) * sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0')
	{
		new[i] = tmp[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*read_buff(int fd, char *cont)
{
	size_t	num;
	char	*copy;

	copy = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	num = read(fd, copy, BUFFER_SIZE);
	if (num < 0)
		return (NULL);
	return (cont);
}

char	*get_next_line(int fd)
{
	static char	*cont;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cont = read_buff(fd, cont);
	if (!cont)
		return (NULL);
	next = taglio(cont);
	return (next);
}

int	main(void)
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
}
