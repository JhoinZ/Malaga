/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:30:53 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/11 14:30:53 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	j;
	unsigned char *ptr;

	ptr = (unsigned char *)b;
	j = 0;
	while (j < len)
	{
		ptr[j] = c;
		j++;
	}
	return (b);
}
