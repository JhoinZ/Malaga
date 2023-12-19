/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:13:03 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/08 18:40:59 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (fd >= 0)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

/* int	main(void)
{
	int	fd;

	char s[] = "Hello, world!";
	fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		return (1);
	}
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
} */
