/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:56:07 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/11 17:03:18 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr2 > ptr1)
	{
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	else if (ptr2 < ptr1)
	{
		while (n > 0)
		{
			ptr1[n - 1] = ptr2[n - 1];
			n--;
		}
	}
	return (dst);
}
