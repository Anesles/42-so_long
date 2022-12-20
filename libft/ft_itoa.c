/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:46:23 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/09 17:42:03 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_n(int n, char *ret, int is_neg, size_t size)
{
	if (n == 0)
	{
		ret[0] = '0';
		ret[1] = 0;
		return (ret);
	}
	if (is_neg)
	{
		ret[0] = '-';
		ret[size + 1] = 0;
	}
	else
	{
		ret[size] = 0;
		size--;
	}
	while (n != 0)
	{
		ret[size--] = '0' + (n % 10);
		n /= 10;
	}
	return (ret);
}

static char	*ft_alloc(int n, size_t size)
{
	char	*ret;

	if (n < 0)
	{
		ret = (char *)malloc((size + 2) * sizeof(*ret));
	}
	else
		ret = (char *)malloc((size + 1) * sizeof(*ret));
	if (n == 0)
		ret = (char *)malloc(2 * sizeof(*ret));
	return (ret);
}

char	*ft_min(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	size;
	int		neg;
	int		number;
	char	*ret;

	if (n == -2147483648)
		return (ft_min());
	size = 0;
	neg = 0;
	number = n;
	while (number)
	{
		number /= 10;
		size++;
	}
	ret = ft_alloc(n, size);
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	if (!ret)
		return (NULL);
	ret = ft_get_n(n, ret, neg, size);
	return (ret);
}
