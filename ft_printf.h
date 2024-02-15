/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:48 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/15 23:30:15 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	format_printer(const char *s, va_list p, int *err);
int	ft_put_uint(unsigned int n, char *base, int *err);
int	ft_putchar(int c, int *err);
int	ft_putstr(char *s, int *err);
int	ft_put_nbr(long long nbr, char *base, int *err);
int	ft_put_unbr(unsigned long long n, char *base, int *err);
int	display(unsigned long long nbr, char *base, int nob, int *err);

#endif