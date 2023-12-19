/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:21:43 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/19 12:31:25 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

int	end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]))
			i--;
		else
			return (i);
	}
	return (i);
}

char	*coping(char *fin, const char *s1, int scop, int strim)
{
	int	i;

	i = 0;
	while (strim < scop)
	{
		fin[i] = s1[strim];
		strim++;
		i++;
	}
	fin[i] = '\0';
	return (fin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		strim;
	int		scop;
	char	*fin;

	if (!s1 || !set)
		return (NULL);
	strim = start(s1, set);
	scop = end(s1, set);
	if (scop == -1)
	{
		fin = (char *)malloc(1);
		if (!fin)
			return (NULL);
		fin[0] = '\0';
		return (fin);
	}
	fin = (char *)malloc(scop - strim + 2);
	if (!fin)
		return (NULL);
	coping(fin, s1, scop + 1, strim);
	return (fin);
}
