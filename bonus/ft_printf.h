/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randre <randre@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:17:01 by randre            #+#    #+#             */
/*   Updated: 2023/09/25 07:17:01 by randre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_arg
{
	unsigned int		is_dotted;
	unsigned int		spaces;
	int		precision;
	char				type;
	unsigned int		is_signed;
	unsigned int		ox;
	char				space_char;
	unsigned int		is_valid;
	unsigned int		left_pad;
	unsigned int		space_sign;
}	t_arg;

void	ft_init_arg(t_arg *arg);
int		ft_isvalid_arg(const char c);
int		ft_parse(const char *format, t_arg *arg);
char	*ft_itoa(int n);
char	ft_chandle(va_list args);
char	*ft_shandle(va_list args);
char	*ft_dhandle(va_list args);
char	*ft_xhandle(va_list args, int i);
int		ft_printf(const char *format, ...);
char	*ft_strdup(const char *s);
int		ft_xcount(int nbr);
int		ft_treat(t_arg arg, va_list args);

#endif