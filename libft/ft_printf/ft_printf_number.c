/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:10:55 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/24 18:17:33 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	print_pointer(va_list args)
{
	long long int	p;
	int				len;

	p = va_arg(args, long long int);
	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	len = len_ptr(p);
	ft_ptr(p);
	return (len + 2);
}

int	print_int(va_list args)
{
	int		n;
	int		len;

	n = va_arg(args, int);
	len = ft_int(n);
	return (len);
}

int	print_uint(va_list args)
{
	unsigned int	n;
	int				len;

	n = va_arg(args, unsigned int);
	len = ft_uint(n);
	return (len);
}

int	print_hex(va_list args, char c)
{
	int	p;
	int	len;

	p = va_arg(args, long long int);
	len = len_hex(p);
	ft_hex(p, c);
	return (len);
}
