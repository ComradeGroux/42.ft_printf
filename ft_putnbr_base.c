/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:08 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/19 23:15:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(int n, char *base, int fd)
{
	long	num;
	int		baselen;
	int		len;

	num = n;
	baselen = ft_strlen(base);
	len = 0;
	if (num < 0)
	{
		len += ft_putchar_fd('-', fd);
		len += ft_putnbr_base_fd(num * -1, base, fd);
	}
	else if (num >= baselen)
	{
		len += ft_putnbr_base_fd(num / baselen, base, fd);
		len += ft_putnbr_base_fd(num % baselen, base, fd);
	}
	else
		len += ft_putchar_fd(base[num], fd);
	return (len);
}
