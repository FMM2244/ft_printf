/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:26:44 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/18 17:30:59 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	type_specifier_xp(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'p')
		return (i += ft_putadd_fd((unsigned long)va_arg(args, void *), 1));
	else if (c == 'x')
		return (i += ft_puthexal_fd(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (i += ft_puthexau_fd(va_arg(args, unsigned int), 1));
	return (i);
}

static int	type_specifier_c(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == '%')
		write(1, "%", 1);
	return (1);
}

int	returned_val(char c, char *s, int i)
{
	if (!s)
		return (0);
	i += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (c != 's')
		free(s);
	return (i);
}

int	type_specifier(char c, va_list args)
{
	int		i;
	char	*s;

	i = 0;
	s = NULL;
	if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			return (write_null());
	}
	else if (c == 'u')
		return (i += ft_itoa_u(va_arg(args, int)));
	else if (c == '%' || c == 'c')
		return (i += type_specifier_c(c, args));
	else if (c == 'x' || c == 'X' || c == 'p')
		return (i += type_specifier_xp(c, args));
	return (returned_val(c, s, i));
}

int	ft_printf(const char *s, ...)
{
	int		total_length_counter;
	va_list	args;

	va_start(args, s);
	total_length_counter = 0;
	while (*s != 0)
	{
		if (*s == '%')
		{
			s++;
			total_length_counter += type_specifier(*s, args);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			total_length_counter++;
		}
		s++;
	}
	va_end(args);
	return (total_length_counter);
}
/*
#include <stdio.h>
int main(){
	ft_printf(" NULL %s NULL ", NULL);
	return 0;
}
*/
