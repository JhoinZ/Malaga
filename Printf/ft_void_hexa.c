/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:05:23 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/30 15:43:29 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_trasf(char *s, unsigned long int point, int len)
{
	unsigned int	lung;

	lung = ft_strlen(s);
	if (point >= lung)
	{
		len = hexa_trasf(s, point / lung, len);
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

int	ft_void_hexa(void *p)
{
	unsigned long int	point;
	int					len;

	point = (unsigned long int)p;
	len = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	len = hexa_trasf("0123456789abcdef", point, len);
	if (len == -1)
		return (-1);
	len += 2;
	return (len);
}
