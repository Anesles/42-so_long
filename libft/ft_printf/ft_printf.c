/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:05:03 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/24 18:17:45 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	detect_args(char *s, va_list args)
{
	char	next;
	int		len;

	len = -2;
	next = *s;
	if (next == 'c')
		len += print_char(args);
	else if (next == 's')
		len += print_string(args);
	else if (next == 'p')
		len += print_pointer(args);
	else if (next == 'd' || next == 'i')
		len += print_int(args);
	else if (next == 'u')
		len += print_uint(args);
	else if (next == 'x' || next == 'X')
		len += print_hex(args, next);
	else if (next == '%')
	{
		write(1, "%", 1);
		len += 1;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	va_start(args, str);
	len = ft_strlen(str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			len += detect_args(&((char *)str)[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (len);
}
