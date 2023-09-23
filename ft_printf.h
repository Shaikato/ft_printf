/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:56:59 by randre            #+#    #+#             */
/*   Updated: 2023/09/23 06:56:59 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

unsigned int	ft_strlen(const char *str);
int				ft_printf(const char *str, ...);
int				ft_isvalid_arg(const char c);
void			ft_chandle(va_list args);
void			ft_shandle(va_list args);
void			ft_dhandle(va_list args);
void			ft_uhandle(va_list args);
int				ft_typecheck(const char c, va_list args);
void			ft_putnbr(int n);
char			*ft_strdup(const char *s);
void			ft_xhandle(va_list args, int i);
int				ft_xcount(int nbr);
void			ft_putnbr_long(long long int n);

#endif
