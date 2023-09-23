/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:18:54 by randre            #+#    #+#             */
/*   Updated: 2023/09/23 06:18:54 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_count_arg(const char *str)
{
	int	i;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_isvalid_arg(*str) && *str != '%')
				i++;
			str++;
		}
		else
			str++;
	}
}

int	ft_printf(const char *str, ...)
{
	int	nbr_arg;
	va_list args;

	nbr_arg = ft_count_arg(str);
	va_start(args, str);
	while(*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			str++;
		}
		else
		{
			str++;
			if (ft_isvalid_arg(*str) && *str != '%')
			{
				ft_typecheck(*str, args);
				va_arg(args, int);
			}
			else
				write(1, str, 1);
			str++;
		}
	}
	return (1);
}