/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:37 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/04 16:21:10 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (haystack[k] == needle[j] && k < len)
			{
				k++;
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	*ptr;

	const char haystack[] = "ciao pisello";
	const char needle[] = "lo";
	ptr = ft_strnstr(haystack, needle, 12);
	printf("%s", ptr);
	return (0);
} */
