/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:08:50 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/12 15:26:37 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*fin;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	fin = (char *)malloc((len + 1) * sizeof(char));
	if (!fin)
		return (NULL);
	i = 0;
	while (i < len)
	{
		fin[i] = f(i, s[i]);
		i++;
	}
	fin[i] = '\0';
	return (fin);
}
