/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:11:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/02/07 23:12:38 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	va_list	args_copy;
	int		args;

	va_start(arg_ptr, str);
	va_copy(args_copy, arg_ptr);
	args = 0;
	while (args < max)
	{
		va_arg();
	}
	va_end(arg_ptr);
}
