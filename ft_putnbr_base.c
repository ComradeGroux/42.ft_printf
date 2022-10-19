/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:22:08 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/19 22:51:12 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	long	num;
	int		baselen;

	num = n;
	baselen = ft_strlen(base);
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd(num * -1, base, fd);
	}
	else if (num > baselen)
	{
		ft_putnbr_base_fd(num / baselen, base, fd);
		ft_putnbr_base_fd(num % baselen, base, fd);
	}
	else
		ft_putchar_fd(base[num], fd);
}

int	main(void)
{
	int n = 15;

	ft_putnbr_base_fd(n, "0123456789abcdef", 1);
}
