/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:45:42 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/02/01 17:10:20 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*taglio(static char *cont)
{
	size_t	num;
	char	*tmp;
	char	*new;

	tmp = ft_strchr(cont, '\n');
	if (tmp == NULL)
	{
		tmp = ft_strchr(cont, '\0');
		if (tmp == NULL)
			return (NULL);
	}
	num = ft_strlen(tmp);
	new = malloc(num * sizeof(char *));
	if (!num)
		return (NULL);
	new = tmp;
	return (new);
}

char	*read_buff(int fd, static char *cont)
{
	size_t	num;

	num = read(fd, cont, BUFFER_SIZE);
	return (num);
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
	cont = buffer_left(cont);
	return (next);
}
