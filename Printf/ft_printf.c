/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:20 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/29 17:32:39 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int var_type(char c, va_list args)
{
	if (c == 'c')
		return ;	
	if (c == 's')
		return ;
	if (c == 'p')
		return ;
	if (c == 'd')
		return ;
	if (c == 'i')
		return ;
	if (c == 'u')
		return ;
	if (c == 'x')
		return ;
	if (c == 'X')
		return ;
	if (c == '%')
		return ;
}

int	percentual(char c, va_list args)
{
	int len;

	len = 0;
	if (c != '%')
	{
		len = var_type(c, args);
		if (len == -1)
			return (-1);
		return (len);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

int	write_str(const char *s, va_list args, int len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + percentual(s[i + 1], args);
			if (len == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &s[i], 1) != 1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, s);
	len = write_str(s, args, len);
	va_end(args);
	return (len);
}
