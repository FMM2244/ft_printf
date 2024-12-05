/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaaita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:50:36 by fmaaita           #+#    #+#             */
/*   Updated: 2024/09/19 18:58:56 by fmaaita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_itoa_u(unsigned int n);
int	ft_putadd_fd(unsigned long num, int fd);
int	ft_puthexal_fd(unsigned long num, int fd);
int	ft_puthexau_fd(unsigned int num, int fd);
int	ft_printf(const char *s, ...);
int	write_null(void);

#endif
