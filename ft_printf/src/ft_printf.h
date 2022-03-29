/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:57 by ramartin          #+#    #+#             */
/*   Updated: 2022/03/29 08:55:26 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

/* Printf */
int		printf_format(va_list args, const char format);
int		ft_printf(const char *format, ...);

/* Character */
int		printf_char(char out);

/* String */
int		printf_string(char *out);

/* Pointer */
int		ptrlen(uintptr_t num);
void	putptr(uintptr_t num);
int		printf_pointer(unsigned long long out);

/* Decimal and Integer */
int		printf_num(int out);

/* Unsigned Decimal */
int		numlen(unsigned	int num);
char	*uitoa(unsigned int n);
int		printf_udec(unsigned int out);

/* Hexadecimal */
int		hexlen(unsigned	int num);
void	puthex(unsigned int num, const char format);
int		printf_hex(unsigned int num, const char format);

#endif