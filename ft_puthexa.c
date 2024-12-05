/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:20:41 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/21 10:21:08 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_puthexau_fd(unsigned int num, int fd)
{
	char	*s;
	int		counter;

	counter = 0;
	s = "0123456789ABCDEF";
	if (num >= 16)
		counter += ft_puthexau_fd(num / 16, fd);
	write(fd, &s[num % 16], 1);
	return (counter + 1);
}

int	ft_puthexal_fd(unsigned long num, int fd)
{
	char	*s;
	int		counter;

	counter = 0;
	s = "0123456789abcdef";
	if (num >= 16)
		counter += ft_puthexal_fd(num / 16, fd);
	write(fd, &s[num % 16], 1);
	return (counter + 1);
}

int	ft_putadd_fd(unsigned long num, int fd)
{
	int	counter;

	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	counter = 2;
	write(fd, "0x", 2);
	counter += ft_puthexal_fd(num, fd);
	return (counter);
}

int	write_null(void)
{
	ft_putstr_fd("(null)", 1);
	return (6);
}
/*
int main(){
	int i = 13;
	int result = ft_putadd_fd(i, 1);
	printf("\n%d\n", result);
	return 0;
}
*/
