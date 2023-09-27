/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:45:22 by randre            #+#    #+#             */
/*   Updated: 2023/09/23 08:45:22 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

void	ft_phandle(va_list args)
{
	int	*p;
	int	nbr;

	p = va_arg (args, int *);
	if (!p)
		write(1, "(nil)", 5);
	else
	{
		nbr = (intptr_t)p;
		ft_hexa(nbr);
	}
}
