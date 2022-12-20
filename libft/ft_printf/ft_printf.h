/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:09:53 by brumarti          #+#    #+#             */
/*   Updated: 2022/11/24 18:19:45 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H	

# include <stdio.h>

// utils
void	ft_hex(long int p, char c);
int		ft_int(int n);
void	ft_ptr(unsigned long long p);

// len
int		len_ptr(unsigned long long int p);
int		len_hex(unsigned int p);
int		ft_uint(unsigned int n);

// printf
int		print_pointer(va_list args);
int		print_char(va_list args);
int		print_string(va_list args);
int		print_int(va_list args);
int		print_uint(va_list args);
int		print_hex(va_list args, char c);
#endif