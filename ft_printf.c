/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:55:55 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/20 16:55:23 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_conv(char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == '%')
		len = ft_printf_char('%');
	else if (format == 'c')
		len = ft_printf_char(va_arg(ap, int));
	else if (format == 's')
		len = ft_printf_str(va_arg(ap, char *));
	else if (format == 'i' && format == 'd')
		len = ft_printf_nbr_base(va_arg(ap, long long), "0123456789");
	else if (format == 'x')
		len = ft_printf_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len = ft_printf_nbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (format == 'p')
		len = ft_printf_ptr(va_arg(ap, unsigned long long));
	else if (format == 'u')
		len = ft_printf_nbr_base(va_arg(ap, unsigned long), "0123456789");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_printf_conv(format[i], ap);
		}
		else
			len += ft_printf_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
