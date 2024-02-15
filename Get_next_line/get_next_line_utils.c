/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:46:19 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/02/15 16:37:11 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == (unsigned char)c)
		return (&ptr[i]);
	return (NULL);
}

char	*ft_strjoin(char *cat, char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src)
		return (dest);
	while (src[i] != '\0')
	{
		cat[i] = src[i];
		i++;
	}
	while (dest[j] != '\0')
	{
		cat[i] = dest[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	return (cat);
}

char	*ft_strcat_mal(char *dest, char *src)
{
	char	*cat;

	if (!src)
		return (NULL);
	if (!dest)
	{
		dest = malloc((ft_strlen(src) + 2), sizeof(char));
		if (!dest)
			return (NULL);
	}
	cat = malloc((ft_strlen(src) + ft_strlen(dest) + 2), sizeof(char));
	if (!cat)
	{
		return (free(dest), NULL);
	}
	cat = ft_strjoin(cat, src, dest);
	free(dest);
	return (cat);
}
