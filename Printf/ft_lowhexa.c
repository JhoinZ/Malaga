/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:25:47 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/30 16:37:28 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_magic(char *s, int point, int len)
{
	unsigned int	lung;

	lung = ft_strlen(s);
	if (point >= lung)
	{
		len = hexa_magic(s, point / lung, len);
		if (len == -1)
			return (-1);
		if (write (1, &s[point % lung], 1) == -1)
			return (-1);
		len++;
	}
	if (point < lung)
	{
		if (write (1, &s[point], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_lowhexa(int n)
{
	int		len;

	len = 0;
	len = hexa_magic("0123456789abcdef", n, len);
	return (len);
}
