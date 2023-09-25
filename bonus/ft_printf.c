/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 06:47:30 by randre            #+#    #+#             */
/*   Updated: 2023/09/25 06:47:30 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	ft_printf(const char *format, ...)
{
	t_arg arg;
	va_list	args;

	va_start(args, format);
	ft_init_arg(&arg);
	while(*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
		}
		else
		{
			format++;
			format += ft_parse(format, &arg);
			ft_treat(arg, args);
			ft_init_arg(&arg);
		}
	}
}