/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:41:43 by randre            #+#    #+#             */
/*   Updated: 2023/10/07 14:39:15 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>

int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

int	ft_nbrlenlong(long long int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

size_t	ft_xcount(size_t nbr)
{
	int	y;

	y = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		y++;
		nbr /= 16;
	}
	return (y);
}

int	ft_putnbr_long(long long int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_long(n / 10);
		ft_putnbr_long(n % 10);
	}
	c = (char)(n + 48);
	if (n < 10)
		write(1, &c, 1);
	return (ft_nbrlenlong(n));
}

int	ft_hexa(size_t nbr)
{
	char	*base_str;
	int		y;
	char	*str;
	int		i;

	base_str = ft_strdup("0123456789abcdef");
	i = ft_xcount(nbr);
	str = malloc(sizeof(char) * i + 1);
	y = -1;
	while (y++ < i)
		str[y] = '0';
	str[i] = 0;
	y = i - 1;
	while (y > -1)
	{
		str[y] = base_str[nbr % 16];
		nbr /= 16;
		y--;
	}
	write(1, str, i);
	free(str);
	free(base_str);
	return (i);
}
