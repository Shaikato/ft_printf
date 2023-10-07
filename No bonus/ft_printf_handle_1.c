/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:33:11 by randre            #+#    #+#             */
/*   Updated: 2023/10/07 14:49:51 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_chandle(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_shandle(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
}

int	ft_dhandle(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	return (ft_putnbr(nbr));
}

int	ft_uhandle(va_list args)
{
	long long int	nbrr;

	nbrr = va_arg(args, long);
	if (nbrr < 0)
		nbrr = 4294967296 + nbrr;
	return (ft_putnbr_long(nbrr));
}

int	ft_xhandle(va_list args, size_t i)
{
	char	*base_str;
	int		y;
	size_t	nbr;
	char	*str;

	nbr = va_arg(args, size_t);
	y = ft_xcount(nbr);
	if (y == -1)
		return (1);
	if (i == 0)
		base_str = ft_strdup("0123456789abcdef");
	else
		base_str = ft_strdup("0123456789ABCDEF");
	i = y;
	str = malloc(sizeof(char) * (y + 1));
	str[y + 1] = 0;
	while (y--)
	{
		str[y] = base_str[nbr % 16];
		nbr /= 16;
	}
	write(1, str, i);
	free(str);
	free(base_str);
	return (i);
}
