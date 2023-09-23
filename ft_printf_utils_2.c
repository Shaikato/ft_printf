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