/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:36:06 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/04 15:52:40 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

/* int	main(void)
{
	char	c;
	char	*result;

	const char s[] = "ciao davide";
	c = 'd';
	result = ft_strchr(s, c);
	if (result != NULL)
		printf("%s e' nella stringa.\n", result);
	else
		printf("Il carattere %c non è presente nella stringa.\n", c);
	return (0);
} */
