/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:59:35 by sencetin          #+#    #+#             */
/*   Updated: 2024/11/30 17:50:52 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer(unsigned long p)
{
	int	len;

	len = 0;
	if (p >= 16)
		len += ft_pointer(p / 16);
	len += write(1, &LOWER[p % 16], 1);
	return (len);
}

int	ft_print_pointer(unsigned long p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		len += write(1, "(nil)", 5);
	}
	else
	{
		len += ft_print_char('0');
		len += ft_print_char('x');
		len += ft_pointer(p);
	}
	return (len);
}
