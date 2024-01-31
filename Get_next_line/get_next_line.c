/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:45:42 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/31 18:32:59 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_fd(int fd, static char *buffer, char *next)
{
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next;

	if (fd < 0)
		return (NULL);
	read_fd(fd, buffer, next);
}
