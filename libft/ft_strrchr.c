/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:54:15 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/07 22:40:16 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	i = 0;
	f = NULL;
	while (i <= length)
	{
		if (s[i] == c)
			f = (char *)&s[i];
		i++;
	}
	return (f);
}
