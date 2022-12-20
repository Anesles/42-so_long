/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:02:50 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/24 18:17:18 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	len_hex(unsigned int p)
{
	int	len;

	if (p == 0)
		return (1);
	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	len_ptr(unsigned long long p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	ft_uint(unsigned int n)
{
	char	*base;
	int		len;

	base = "0123456789";
	len = 0;
	if (n >= 10)
		len += ft_int(n / 10);
	write(1, &base[n % 10], 1);
	return (len + 1);
}
