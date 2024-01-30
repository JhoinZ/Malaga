/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:20 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/30 16:44:07 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	var_type(char c, va_list args, int len)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_void_hexa(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigndec(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_lowhexa(va_arg(args, int)));
	else if (c == 'X')
		return (ft_upphexa(va_arg(args, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	write_str(const char *s, va_list args, int len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = len + var_type(s[i + 1], args, len);
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
