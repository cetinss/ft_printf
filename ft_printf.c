/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:14:39 by sencetin          #+#    #+#             */
/*   Updated: 2024/11/30 18:09:30 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_and_print(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(arg, int));
	else if (c == 's')
		count += ft_print_str(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_print_num(va_arg(arg, int));
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		count += ft_print_hex(va_arg(arg, unsigned int), LOWER);
	else if (c == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), UPPER);
	else if (c == 'p')
		count += ft_print_pointer(va_arg(arg, unsigned long));
	else if (c == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	len = 0;
	if (!format)
		return (0);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += len_and_print(*(++format), arg);
			format++;
		}
		else
		{
			len += ft_print_char(*format++);
		}
	}
	va_end(arg);
	return (len);
}
