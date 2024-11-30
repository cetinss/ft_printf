/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:33:17 by sencetin          #+#    #+#             */
/*   Updated: 2024/11/30 18:11:18 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"

int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_num(long long nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_hex(unsigned int nbr, const char *base);
int	ft_print_pointer(unsigned long p);
int	ft_printf(const char *format, ...);

#endif
