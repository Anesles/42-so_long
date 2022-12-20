/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:39:41 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/24 18:17:37 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_hex(long int p, char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (p < 0)
		p = (4294967295 - (p * -1)) + 1;
	if (p >= 16)
	{
		ft_hex(p / 16, c);
		ft_hex(p % 16, c);
	}
	else
		write(1, &base[p], 1);
}

void	ft_ptr(unsigned long long p)
{
	char	*base;

	base = "0123456789abcdef";
	if (p >= 16)
	{
		ft_ptr(p / 16);
		ft_ptr(p % 16);
	}
	else
		write(1, &base[p], 1);
}

int	ft_int(int n)
{
	char	*base;
	int		len;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	base = "0123456789";
	len = 0;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		len++;
	}
	if (n >= 10)
		len += ft_int(n / 10);
	write(1, &base[n % 10], 1);
	return (len + 1);
}
