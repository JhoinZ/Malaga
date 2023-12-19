/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:21:36 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/04 17:54:10 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/* int	main(void)
{
	size_t	count;
	size_t	size;
	int		*arr;
	size_t	i;

	count = 10;
	size = sizeof(int);
	arr = (int *)ft_calloc(count, size);
	if (arr == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	i = 0;
	while (i < count)
	{
		arr[i] = i * 2;
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}
 */