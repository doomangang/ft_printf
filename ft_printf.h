/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:48 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/17 19:27:14 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	format_printer(const char *s, va_list p);
int	char_printer(int c);
int	str_printer(char *s);
int	pointer_printer(unsigned long long n, char *base);
int	num_printer(long long n, char *base);
int	unsigned_printer(unsigned int n, char *base);
int	display(unsigned long long n, char *base, int nob);

#endif