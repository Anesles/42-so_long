/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:42:02 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/10 14:39:00 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	index;

	if (size == 0 || size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	length = ft_strlen(dst);
	index = 0;
	while (src[index] && length + 1 < size)
	{
		dst[length] = src[index];
		length++;
		index++;
	}
	dst[length] = 0;
	return (length + ft_strlen(&src[index]));
}
