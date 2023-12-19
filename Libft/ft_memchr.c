/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:48:44 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/04 17:55:49 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	ptr = (unsigned char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	c;
	size_t	n;

	char str[] = "ciao filippo";
	c = 'p';
	n = 12;
	char *result = ft_memchr(str, c, n);
	if (result != NULL)
		printf("%s e' nella stringa.\n", result);
	else
		printf("Il carattere %c non è presente nella stringa.\n", c);
	return (0);
} */
