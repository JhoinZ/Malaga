/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsaffiri <fsaffiri@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:10:54 by fsaffiri          #+#    #+#             */
/*   Updated: 2024/01/24 18:35:43 by fsaffiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar('-', fd);
		ft_putnbr(214748364, fd);
		ft_putchar('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
		ft_putnbr(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), fd);
		ft_putchar((n % 10 + '0'), fd);
	}
	else
	{
		ft_putchar((n + '0'), fd);
	}
}
