/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:33:11 by randre            #+#    #+#             */
/*   Updated: 2023/09/23 07:33:11 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_chandle(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);
}

void	ft_shandle(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	write(1, str, ft_strlen(str));
}

void	ft_dhandle(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr(nbr);
}

void	ft_uhandle(va_list args)
{
	long long int	nbrr;

	nbrr = va_arg(args, long);
	if (nbrr < 0)
		nbrr = 4294967296 + nbrr;
	ft_putnbr_long(nbrr);
}

void	ft_xhandle(va_list args, int i)
{
	char	*base_str;
	int		nbr;
	int		y;
	char	*str;

	if (i == 0)
		base_str = ft_strdup("0123456789abcdef");
	else
		base_str = ft_strdup("0123456789ABCDEF");
	nbr = va_arg(args, int);
	y = ft_xcount(nbr);
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
}