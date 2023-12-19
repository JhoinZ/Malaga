/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:32:36 by fsaffiri          #+#    #+#             */
/*   Updated: 2023/12/19 16:29:54 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_int_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == -2147483647)
		return (ft_strdup(n));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	len--;
	while (len > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	main(void)
{
	int		n;
	char	*str;

	n = -2147483647;
	str = ft_itoa(n);
	if (str != NULL)
	{
		printf("%s\n", str);
		free(str);
	}
	else
		printf("Error: ft_itoa returned NULL\n");
	return (0);
}
