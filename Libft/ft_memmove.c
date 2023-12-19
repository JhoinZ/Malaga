/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:34:37 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/04 14:27:35 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned int	i;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr2 > ptr1)
	{
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	else if (ptr2 < ptr1)
	{
		while (len > 0)
		{
			ptr1[len - 1] = ptr2[len - 1];
			len--;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char dst[50] = "Hello, world!";
	char src[50] = "Goodbye, world!";

	ft_memmove(dst, src, 14);
	printf("%s\n", dst);
	return (0);
}
 */