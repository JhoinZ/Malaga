/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:52:31 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/04 19:28:27 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char			*ptr;
	unsigned int	i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* int	main(void)
{
	char	*original;
	char	*copy;

	original = "Hello, world!";
	copy = ft_strdup(original);
	if (copy != NULL)
	{
		printf("Original: %s\n", original);
		printf("Copy: %s\n", copy);
		free(copy);
	}
	else
	{
		printf("Failed to duplicate string.\n");
	}
	return (0);
} */
