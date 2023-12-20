/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:32:36 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/20 18:05:56 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	get_numb(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
	{
		n = -n;
		count = 1;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	count += 1;
	return (count);
}

char	*casispeciali(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (n == 0 || n == -2147483648)
		return (casispeciali(n));
	len = get_numb(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (len > i)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/* int	main(void)
{
	int		n;
	char	*str;

	n = -6478;
	str = ft_itoa(n);
	if (str != NULL)
	{
		printf("%s\n", str);
		free(str);
	}
	else
		printf("Error\n");
	return (0);
} */
