/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:07 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/20 18:57:43 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	counter(char const *s, char c)
{
	size_t			j;
	unsigned int	i;

	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j++;
			while (s[i + 1] == c)
				i++;
		}
		i++;
	}
	return (j);
}

char	**principale(char **fin, char const *s, char c, size_t i)
{
	return (fin);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**fin;

	if (!s)
		return (NULL);
	i = counter(s, c);
	fin = (char **)malloc((i + 1) * sizeof(char *));
	if (!fin)
		return (NULL);
	return (principale(fin, s, c, i));
}
