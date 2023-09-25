/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:11:59 by randre            #+#    #+#             */
/*   Updated: 2023/09/25 07:11:59 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_isvalid_arg(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%' || 
		(c >= '0' && c <= '9') || c == '.')
		return (1);
	else
		return (0);
}

int	ft_isvalid_flag(const char c)
{
	if (c == '+' || c == '-' || c == '0' || c == '#' || c == ' ')
		return (1);
	else
		return (0);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*start;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	while (*s)
	{
		*str = *s;
		s++;
		str++;
	}
	*str = 0;
	return (start);
}

void	ft_init_arg(t_arg *arg)
{
	arg->is_dotted = 0;
	arg->spaces = 0;
	arg->precision = -1;
	arg->type = 0;
	arg->is_signed = 0;
	arg->ox = 0;
	arg->space_char = ' ';
	arg->is_valid = 0;
	arg->left_pad = 0;
	arg->space_sign = 0;
}

int	ft_parse(const char *format, t_arg *arg)
{
	int	i;

	i = 0;
	while (ft_isvalid_flag(*format))
	{
		if (*format == '+')
		{
			arg->is_signed = 1;
			arg->space_sign = 0;
		}
		if (*format == '-')
			arg->left_pad = 1;
		if (*format == '#')
			arg->ox = 1;
		if (*format == ' ' && arg->is_signed == 0)
			arg->space_sign = 1;
		if (*format == '0')
			arg->space_char = '0';
		format++;
		i++;
	}
	while (ft_isvalid_arg(*format))
	{
		if (*format == '%')
		{
			write(1, "%", 1);
			return (i + 1);
		}
		if (*format == '.')
			arg->is_dotted = 1;
		if (*format >= '0' && *format <= '9')
		{
			if (arg->is_dotted == 1)
			{
				if (arg->precision == -1)
					arg->precision = 0;
				arg->precision *= 10;
				arg->precision += *format - 48;
			}
			else
			{
				arg->spaces *= 10;
				arg->spaces += *format - 48;
			}
		}
		if (*format == 'c' || *format == 's' || *format == 'p'
		 	|| *format == 'd' || *format == 'i' || *format == 'u'
			|| *format == 'x' || *format == 'X')
		{
			arg->type = *format;
			return (i + 1);
		}
		i++;
		format++;
	}
}

#include <stdio.h>

int	ft_treat(t_arg arg, va_list args)
{
	char	*str;
	int		i;
	int		op;

	i = 0;
	if (arg.type == 'c')
	{
		str = malloc(sizeof(char) * 2);
		str[0] = ft_chandle(args);
		str[1] = 0;
	}
	else if (arg.type == 's')
		str = ft_shandle(args);
	else if (arg.type == 'd' || arg.type == 'i')
		str = ft_dhandle(args);
	else if (arg.type == 'x')
		str = ft_xhandle(args, 0);
	else if (arg.type == 'X')
		str = ft_xhandle(args, 1);
	if (arg.precision != -1)
		arg.space_char = ' ';
	if (arg.left_pad == 0 && (arg.type == 'c' || arg.type == 's'))
	{
		while(i++ < arg.spaces - ft_strlen(str))
			write(1, &arg.space_char, 1);
		write(1, str, ft_strlen(str));
	}
	else if (arg.left_pad == 1 && (arg.type == 'c' || arg.type == 's'))
	{
		write(1, str, ft_strlen(str));
		while(i++ < arg.spaces - ft_strlen(str))
			write(1, " ", 1);
	}
	if (arg.left_pad == 0 && (arg.type == 'd' || arg.type == 'i'))
	{
		op = arg.spaces - (arg.precision - ft_strlen(str)) - ft_strlen(str);
		if (arg.precision == 0)
			op -= ft_strlen(str);
		if (arg.is_signed && *str != '0')
			op--;
		while (i++ < op)
			write(1, &arg.space_char, 1);
		i = 0;
		if (arg.precision != -1 && arg.precision != 0)
			while (i++ < arg.precision - ft_strlen(str))
				write(1, "0", 1);
		if (arg.is_signed)
			if (*str != '-')
				write(1, "+", 1);
		if (arg.precision == 0 && *str == '0' && !arg.is_signed)
			write(1, " ", 1);
		else if (!(arg.precision == 0 && *str == '0'))
			write(1, str, ft_strlen(str));
	}
	else if (arg.left_pad == 1 && (arg.type == 'd' || arg.type == 'i'))
	{
		if (arg.precision != -1 && arg.precision != 0)
			while (i++ < arg.precision - ft_strlen(str))
				write(1, "0", 1);
		if (arg.is_signed)
			if (*str != '-')
				write(1, "+", 1);
		if (arg.precision == 0 && *str == '0')
			write(1, " ", 1);
		else
			write(1, str, ft_strlen(str));
		while (i++ < (arg.spaces - arg.precision) - ft_strlen(str))
			write(1, &arg.space_char, 1);
	}
	i += ft_strlen(str);
	return (i);
}

int	ft_xcount(int nbr)
{
	int	y;

	y = 0;
	while (nbr != 0)
	{
		y++;
		nbr /= 16;
	}
	return (y);
}