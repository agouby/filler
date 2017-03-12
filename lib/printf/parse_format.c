/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:22:19 by agouby            #+#    #+#             */
/*   Updated: 2017/03/06 21:36:27 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_perc(const char *format)
{
	int count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count++;
			format++;
			while (*format && !is_end_flag(*format))
				format++;
			if (*(format) == '\0')
				return (count);
		}
		format++;
	}
	return (count);
}

void	get_index_perc(t_flags *flags, const char *format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(flags->array = (int *)malloc(sizeof(int) * flags->nb_perc + 1)))
		ft_print_error("Failed to allocate memory.");
	while (format[i])
	{
		if (format[i] == '%')
		{
			flags->array[j] = i;
			i++;
			while (!is_end_flag(format[i]) && format[i])
				i++;
			j++;
		}
		i++;
	}
}
