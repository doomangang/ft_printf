/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:48 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/16 15:01:07 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	format_printer(const char *s, va_list p);
int	ft_put_uint(unsigned int n, char *base);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_put_nbr(long long nbr, char *base);
int	ft_put_unbr(unsigned long long n, char *base);
int	display(unsigned long long nbr, char *base, int nob);

#endif