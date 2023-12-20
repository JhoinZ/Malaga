/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:45:07 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/20 17:17:34 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	counter(char const *s, char c)
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
} */

/* char	*cut(char *sarr, char const *s, char c)
{
	size_t			len;
	unsigned int	start;
	unsigned int	i;
	char			*ptr1;

	start = 0;
	len = 0;
	while (s[start] == c)
		start++;
	i = start;
	while (s[i] != c)
		i++;
	len = i - start;
	ptr1 = ft_substr(s, start, len);
	return (ptr1);
} */

/* char	**ft_split(char const *s, char c)
{
	size_t			i;
	unsigned int	start;
	char			*sarr;

	i = counter(s, c);
	sarr = (char *)malloc((i + 1) * sizeof(char));
	if (!sarr)
		return (NULL);
	start = get_start();
}

int	main(void)
{
	unsigned int	i;
	size_t			ptr;

	i = 0;
	ptr = counter("         ciao mi   chiamo          filippo     ", ' ');
	printf("%zu", ptr);
	return (0);
} */
