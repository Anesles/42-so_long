/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:34:01 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/07 22:38:48 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	length;
	char	*f;

	length = ft_strlen(s);
	i = 0;
	while (i <= length)
	{
		if (s[i] == c)
		{
			f = (char *)&s[i];
			return (f);
		}
		i++;
	}
	return (NULL);
}
