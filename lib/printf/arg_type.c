/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:08:46 by agouby            #+#    #+#             */
/*   Updated: 2017/03/12 03:16:08 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	arg_is_signed(char type)
{
	return (type == 'd' || type == 'i' || type == 'D');
}

unsigned char	arg_is_unsigned(char type)
{
	return (type == 'u' || type == 'U' || type == 'o' ||
			type == 'O' || type == 'x' || type == 'X' || type == 'p');
}

unsigned char	arg_is_char(char type)
{
	return (type == 'c');
}

unsigned char	arg_is_string(char type)
{
	return (type == 's');
}

unsigned char	arg_is_digit(char type)
{
	return (arg_is_signed(type) || arg_is_unsigned(type));
}
