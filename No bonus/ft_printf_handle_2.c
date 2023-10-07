/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:45:22 by randre            #+#    #+#             */
/*   Updated: 2023/10/07 01:42:38 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

void	ft_phandle(va_list args)
{
	size_t	nbr;

	nbr = va_arg (args, size_t);
	if (!nbr)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_hexa(nbr);
	}
}
