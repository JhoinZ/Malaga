/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:25:35 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/07 16:00:03 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*jointime(char *sjoin, const char *s2, size_t j)
{
	size_t	k;

	k = 0;
	while (s2[k] != '\0')
	{
		sjoin[j] = s2[k];
		j++;
		k++;
	}
	return (sjoin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	char	*sjoin;
	size_t	i;

	if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	else if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	sjoin = (char *)malloc((i + 1) * sizeof(char));
	if (!sjoin)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		sjoin[j] = s1[j];
		j++;
	}
	sjoin = jointime(sjoin, s2, j);
	sjoin[i] = '\0';
	return (sjoin);
}

/* int	main(void)
{
	char	*s1;
	char	*s2;
	char	*sjoin;

	s1 = "Hello, ";
	s2 = "world!";
	sjoin = ft_strjoin(s1, s2);
	if (sjoin != NULL)
	{
		printf("Joined string: %s\n", sjoin);
		free(sjoin);
	}
	else
		printf("Failed\n");
	return (0);
}
 */