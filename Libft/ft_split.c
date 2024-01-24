/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:07 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/15 16:16:02 by fsaffiri         ###   ########.fr       */
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

char	**ft_create(char **fin, char c, char const *s)
{
	size_t	start;
	size_t	k;
	size_t	end;

	start = 0;
	k = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (start < end)
		{
			fin[k] = ft_substr(s, start, end - start);
			k++;
		}
		start = end;
	}
	fin[k] = NULL;
	return (fin);
}

char	**ft_split(char const *s, char c)
{
	char	**fin;

	fin = (char **)malloc((counter(s, c) + 1) * sizeof(char *));
	if (!s || !fin)
		return (NULL);
	ft_create(fin, c, s);
	return (fin);
}

/* int	main(void)
{
	char	**result;
	char	*str;
	char	c;

	str = "      split       this for   me  !       ";
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
