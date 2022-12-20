/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:07:27 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/08 18:39:34 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	size_t	start;
	size_t	finish;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	finish = ft_strlen(s1);
	while (finish > start && ft_char_in_set(s1[finish - 1], set))
		finish--;
	str = (char *)malloc((finish - start + 1) * sizeof(*s1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < finish)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
