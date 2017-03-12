/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:05:54 by agouby            #+#    #+#             */
/*   Updated: 2017/03/08 20:55:09 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_flags
{
	int					e_flag;
	int					len_flag;
	char				*str_flag;
	long long			arg_num;
	char				*arg_str;
	wchar_t				*wtmp;
	int					*array;
	int					i;
	char				*format_tmp;
	int					empty_arg;
	int					nb_perc;
}				t_flags;

typedef struct	s_infos
{
	int					prec_flag;
	int					w_flag;
	int					len_arg;
	char				*infos_str;
	int					prec_size;
	int					wstar;
	int					pstar;
	int					is_min;
	unsigned char		hash_flag : 1;
	unsigned char		min_flag : 1;
	unsigned char		plus_flag : 1;
	unsigned char		zero_flag : 1;
	unsigned char		sp_flag : 1;
	unsigned char		z_flag : 1;
	unsigned char		ll_flag : 1;
	unsigned char		hh_flag : 1;
	unsigned char		j_flag : 1;
	unsigned char		l_flag : 1;
	unsigned char		h_flag : 1;
	unsigned char		no_modif : 1;
	unsigned char		arg_is_neg : 1;
	unsigned char		wrong_prec : 1;
	int					pos_bz;
}				t_infos;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				transform_char(wchar_t wchar, char *fresh, int i);
size_t			get_byte_len(wchar_t *ws);
int				get_charlen(wchar_t wchar);
size_t			get_wstrlen(wchar_t *wstr);
char			*transform_wstr(wchar_t *wstr);
void			get_index_perc(t_flags *flags, const char *format);
int				nb_perc(const char *format);
void			get_flags_in_list(const char *format, ...);
void			print_infos(t_infos *infos);
void			get_infos(t_infos *infos, char *str_flag);
void			init_all_struct(t_infos **infos, t_flags **flags);
void			init_infos(t_infos *infos);
void			get_arg(va_list args, t_flags *f, t_infos *i);
char			*store_flags(int s, int *e, int *len, const char *f);
int				put_infos_in_str(t_flags *flags, t_infos *infos);
int				is_end_flag(char c);
char			get_type(t_flags *flags);
unsigned char	arg_is_digit(char type);
unsigned char	arg_is_signed(char type);
unsigned char	arg_is_unsigned(char type);
unsigned char	arg_is_char(char type);
unsigned char	arg_is_string(char type);
void			modify_infos(char type, t_infos *i, t_flags *f);
int				is_no_type(char type);
void			change_modifier(t_infos *infos);
int				store_all(va_list args, t_flags *f, t_infos *i, char *format);
int				flag_is_empty(int fd, t_flags *flags, t_infos *infos);
int				del_and_print(int fd, t_flags *flags, t_infos *infos);
void			get_star(t_infos *infos, char *str_flag);
int				get_conversion(char type);
char			*choose_conv(long long arg_num, t_infos *i);
char			*choose_conv_u(char type, unsigned long long n, t_infos *i);
char			change_type(char type, t_infos *infos);
void			get_arg_ds(char type, va_list args, t_flags *f, t_infos *i);
void			get_arg_du(char type, va_list args, t_flags *f, t_infos *i);
void			get_arg_c(char type, va_list args, t_flags *f, t_infos *i);
void			get_arg_s(char type, va_list args, t_flags *f, t_infos *i);
int				is_end_flag(char type);
void			deal_with_notype(t_flags *flags, t_infos *infos);
void			deal_with_perc(t_flags *flags, t_infos *infos);
void			deal_with_prec_d(t_flags *flags, t_infos *infos);
void			deal_with_digit(char type, t_flags *flags, t_infos *infos);
int				deal_with_char(t_flags *flags, t_infos *infos);
void			deal_with_s(t_flags *flags, t_infos *infos);
void			deal_with_sw(t_flags *flags, t_infos *infos);
void			deal_with_b(char type, t_flags *flags);
int				deal_with_cw(t_flags *flags, t_infos *infos);
char			*add_space_b(char *str);
void			add_type_front(char type, t_flags *flags, t_infos *infos);
void			deal_with_zero(char type, t_flags *flags, t_infos *infos);
void			reverse_bits(char *str);

#endif
