/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:08 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/18 19:24:59 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int n, int base, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(num * -1, fd);
	}
	else if (num > base)
	{
		ft_putnbr_fd(num / base, fd);
		ft_putnbr_fd(num % base, fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}
