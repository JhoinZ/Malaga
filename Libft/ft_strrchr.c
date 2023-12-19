/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:15:51 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/18 18:49:36 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/* int	main(void)
{
	char	c;
	char	*result;

	const char	s[] = "ciao davide";
	c = 'd';
	result = ft_strrchr(s, c);
	if (result != NULL)
		printf("%s e' nella stringa.\n", result);
	else
		printf("Il carattere %c non è presente nella stringa.\n", c);
	return (0);
}
 */