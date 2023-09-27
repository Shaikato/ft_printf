/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:41:43 by randre            #+#    #+#             */
/*   Updated: 2023/09/23 08:41:43 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>

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

void	ft_putnbr_long(long long int n)
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
}

void	ft_hexa(int nbr)
{
	char	*base_str;
	int		y;
	char	*str;
	int		i;

	base_str = ft_strdup("0123456789ABCDEF");
	str = malloc(sizeof(char) * 9);
	y = -1;
	while (y++ < 7)
		str[y] = '0';
	str[8] = 0;
	y = ft_xcount(nbr);
	i = 7;
	while (i > 8 - y - 1)
	{
		str[i] = base_str[nbr % 16];
		nbr /= 16;
		i--;
	}
	write(1, str, 8);
	free(str);
}
