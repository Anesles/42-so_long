/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:33:06 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/10 14:39:09 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	char			*t1;
	char			*t2;

	i = 0;
	t1 = (char *)s1;
	t2 = (char *)s2;
	if (n == 0)
		return (0);
	while (*t1 && *t2 && (*t1 == *t2) && i < n - 1)
	{
		t1++;
		t2++;
		i++;
	}
	return ((int)(unsigned char)(*t1) - (int)(unsigned char)(*t2));
}
