/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:07 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/11 18:46:48 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	counter(char const *s, char c)
{
	size_t			j;
	unsigned int	i;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (j);
}

char	*ft_coping(const char *s, size_t n)
{
	char	*frs;

	frs = (char *)malloc((n + 1) * sizeof(char));
	if (!frs)
		return (NULL);
	frs = ft_strncpy(frs, (char *)s, n);
	frs[n] = '\0';
	return (frs);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**fin;

	i = 0;
	k = 0;
	fin = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !fin)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			fin[k] = ft_coping(s + j, i - j);
			k++;
		}
	}
	fin[k] = NULL;
	return (fin);
}

/* int	main(void)
{
	char	**result;
	char	*str;
	char	c;

	str = "Hello, how are you?";
	c = ' ';
	result = ft_split(str, c);
	if (result != NULL)
	{
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("%s\n", result[i]);
		}
		for (int i = 0; result[i] != NULL; i++)
		{
			free(result[i]);
		}
		free(result);
	}
	return (0);
} */
