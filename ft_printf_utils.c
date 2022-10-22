/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:48:16 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/21 16:07:24 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_printf_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			len += ft_printf_char(str[i]);
			i++;
		}
	}
	else
		len = ft_printf_str("(null)");
	return (len);
}

int	ft_printf_nbr_base(long long num, char *base)
{
	int		baselen;
	int		len;

	baselen = ft_strlen(base);
	len = 0;
	if (num < 0)
	{
		len += ft_printf_char('-');
		len += ft_printf_nbr_base(num * -1, base);
	}
	else if (num >= baselen)
	{
		len += ft_printf_nbr_base(num / baselen, base);
		len += ft_printf_nbr_base(num % baselen, base);
	}
	else
		len += ft_printf_char(base[num]);
	return (len);
}

int	ft_printf_ptr(unsigned long ptr)
{
	int	len;

	len = ft_printf_str("0x");
	len += ft_printf_nbr_base(ptr, "0123456789abcdef");
	return (len);
}
