/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:08:46 by agouby            #+#    #+#             */
/*   Updated: 2017/03/14 09:22:34 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	pr_arg_is_sig(char type)
{
	return (type == 'd' || type == 'i' || type == 'D');
}

unsigned char	pr_arg_is_unsigned(char type)
{
	return (type == 'u' || type == 'U' || type == 'o' ||
			type == 'O' || type == 'x' || type == 'X' || type == 'p');
}

unsigned char	pr_arg_is_char(char type)
{
	return (type == 'c');
}

unsigned char	pr_arg_is_string(char type)
{
	return (type == 's');
}

unsigned char	pr_arg_is_digit(char type)
{
	return (pr_arg_is_sig(type) || pr_arg_is_unsigned(type));
}
