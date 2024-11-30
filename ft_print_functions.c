/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:44:47 by sencetin          #+#    #+#             */
/*   Updated: 2024/11/30 17:48:05 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s != '\0')
	{
		ft_print_char(*s++);
		len++;
	}
	return (len);
}

int	ft_print_num(long long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		len += ft_print_num(nbr / 10);
	len += ft_print_char((nbr % 10) + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
		len += ft_print_unsigned(nbr / 10);
	len += ft_print_char((nbr % 10) + '0');
	return (len);
}

int	ft_print_hex(unsigned int nbr, const char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len += ft_print_hex(nbr / 16, base);
	len += write(1, &base[nbr % 16], 1);
	return (len);
}
