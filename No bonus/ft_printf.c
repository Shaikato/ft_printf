/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:18:54 by randre            #+#    #+#             */
/*   Updated: 2023/10/07 14:08:57 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_loop(va_list args, const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			i++;
			str++;
		}
		else
		{
			str++;
			if (ft_isvalid_arg(*str) && *str != '%')
				i += ft_typecheck(*str, args);
			else
			{
				write(1, str, 1);
				i++;
			}
			str++;
		}
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = ft_printf_loop(args, str);
	va_end(args);
	return (i);
}

