/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:07:00 by randre            #+#    #+#             */
/*   Updated: 2023/09/25 08:07:00 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include <stdlib.h>

char	ft_chandle(va_list args)
{
	char	c;

	c = (char) va_arg(args, int);
	return (c);
}

char	*ft_shandle(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	return (str);
}

char	*ft_dhandle(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	return (ft_itoa(nbr));
}

char	*ft_xhandle(va_list args, int i)
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
	return (str);
}
