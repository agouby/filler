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

int		pr_nb_perc(const char *format)
{
	int count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count++;
			format++;
			while (*format && !pr_is_end_flag(*format))
				format++;
			if (*(format) == '\0')
				return (count);
		}
		format++;
	}
	return (count);
}

void	pr_get_index_perc(t_prfgs *prfgs, const char *format)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(prfgs->array = (int *)malloc(sizeof(int) * prfgs->nb_perc + 1)))
		ft_print_error("Failed to allocate memory.");
	while (format[i])
	{
		if (format[i] == '%')
		{
			prfgs->array[j] = i;
			i++;
			while (!pr_is_end_flag(format[i]) && format[i])
				i++;
			j++;
		}
		i++;
	}
}
