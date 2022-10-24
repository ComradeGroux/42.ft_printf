/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:03 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/24 12:45:06 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf_ui(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printf_conv(char format, va_list ap);
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_n_base(long long num, char *base);
int		ft_printf_ptr(unsigned long ptr);
int		ft_printf(const char *format, ...);

#endif