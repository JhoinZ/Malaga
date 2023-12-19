/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:50:06 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/07 16:19:11 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = start;
	while (i < start + len)
	{
		subs[i - start] = s[i];
		i++;
	}
	subs[len] = '\0';
	return (subs);
}

/* int	main(void)
{
	char			*s;
	unsigned int	start;
	size_t			len;
	char			*subs;

	s = "";
	start = 0;
	len = 1;
	subs = ft_substr(s, start, len);
	if (subs != NULL)
	{
		printf("Substring: %s\n", subs);
		free(subs);
	}
	else
		printf("Failed\n");
	return (0);
} */
