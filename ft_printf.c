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

int	ft_printf(const char *str, ...)
{
	va_list args;

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