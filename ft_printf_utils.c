/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:55:36 by randre            #+#    #+#             */
/*   Updated: 2023/09/23 06:55:36 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>

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

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	c = (char)(n + 48);
	if (n < 10)
		write(1, &c, 1);
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

int	ft_isvalid_arg(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	ft_typecheck(const char c, va_list args)
{
	if (c == 'c')
		ft_chandle(args);
	else if (c == 's')
		ft_shandle(args);
	//else if (c == 'p')
	//	ft_phandle(args);
	else if (c == 'd')
		ft_dhandle(args);
	else if (c == 'i')
		ft_dhandle(args);
	else if (c == 'u')
		ft_uhandle(args);
	else if (c == 'x')
		ft_xhandle(args, 0);
	else if (c == 'X')
		ft_xhandle(args, 1);
	else
		return (0);
	return (1);
}