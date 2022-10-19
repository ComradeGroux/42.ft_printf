/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:55:55 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/19 23:14:10 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_conv(const char *format, va_list ap)
{
	int	len;

	len = 0;
	if (format == '%')
		len = ft_putchar_fd('%', 1);
	else if (format == 'c')
		len = ft_putchar_fd(va_arg(ap, char), 1);
	else if (format == 's')
		len = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (format == 'x')
		len = ft_putnbr_base_fd(va_arg(ap, int), "0123456789abcdef");
	else if (format == 'X')
		len = ft_putnbr_base_fd(va_arg(ap, int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format != '\0')
	{
		if (format == '%')
		{
			format++;
			len += ft_choose_conv(format, ap, &len);
		}
		else
			len += ft_putchar_fd(format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}
