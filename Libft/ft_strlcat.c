/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:59:03 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/15 15:07:07 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != size)
		dest[i + j] = '\0';
	while (src[j] != '\0')
	{
		j++;
	}
	return (i + j);
}

/* int	main(void)
{
	unsigned int	size;
	int				result;

	char dest[100] = "Hello, ";
	char src[100] = "world!";
	result = ft_strlcat(src, dest, size);
	printf("%d", result);
	return (0);
} */
