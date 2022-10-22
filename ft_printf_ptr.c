/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:29:25 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/22 16:29:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(unsigned long ptr)
{
	int	len;

	len = ft_printf_str("0x");
	len += ft_printf_nbr_base(ptr, "0123456789abcdef");
	return (len);
}
