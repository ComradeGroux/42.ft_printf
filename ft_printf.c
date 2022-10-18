/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:55:55 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/18 20:50:44 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_choose_conv(const char *format, va_list ap, int *len)
{
	char	*s;

	if (format == '%')
	{
		len++;
		ft_putchar_fd('%', 1);
	}
	else if (format == 'c')
	{
		len++;
		ft_putchar_fd(va_arg(ap, char), 1);
	}
	else if (format == 's')
	{
		s = va_arg(ap, char *);
		len += ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
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
		if (format == '%')		// Conversion
		{
			format++;
			ft_choose_conv(format, ap, &len);
		}
		else
			ft_putchar_fd(format, 1);
		format++;
	}
	va_end(ap);
	return (0); // RETOURNE LE NOMBRE DE BYTES ECRIT (SANS LE '\0')
}
