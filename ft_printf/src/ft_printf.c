/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:21:54 by ramartin          #+#    #+#             */
/*   Updated: 2022/03/23 13:04:16 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += printf_char(va_arg(args, int));
	if (format == 's')
		len += printf_string(va_arg(args, char *));
	if (format == 'p')
		len += printf_pointer(va_arg(args, unsigned long long));
	if (format == 'd' || format == 'i')
		len += printf_num(va_arg(args, int));
	if (format == 'u')
		len += printf_udec(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		len += printf_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = printf_format(args, format[i + 1]);
			i++;
		}
		else
			len += printf_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
