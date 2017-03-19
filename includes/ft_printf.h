/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:05:54 by agouby            #+#    #+#             */
/*   Updated: 2017/03/16 09:34:34 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <inttypes.h>

typedef struct	s_prfgs
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
}				t_prfgs;

typedef struct	s_prinf
{
	int					prec_flag;
	int					w_flag;
	int					len_arg;
	char				*prinf_str;
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
}				t_prinf;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				pr_trans_char(wchar_t wchar, char *fresh, int i);
size_t			pr_get_byte_len(wchar_t *ws);
int				pr_get_charlen(wchar_t wchar);
size_t			pr_get_wstrlen(wchar_t *wstr);
char			*pr_transform_wstr(wchar_t *wstr);
void			pr_get_index_perc(t_prfgs *prfgs, const char *format);
int				pr_nb_perc(const char *format);
void			pr_get_prfgs_in_list(const char *format, ...);
void			pr_get_prinf(t_prinf *prinf, char *str_flag);
void			pr_init_all_struct(t_prinf **prinf, t_prfgs **prfgs);
void			pr_init_prinf(t_prinf *prinf);
void			pr_get_arg(va_list args, t_prfgs *f, t_prinf *i);
char			*pr_store_prfgs(int s, int *e, int *len, const char *f);
int				pr_put_prinf_in_str(t_prfgs *prfgs, t_prinf *prinf);
int				pr_is_end_flag(char c);
char			pr_get_type(t_prfgs *prfgs);
unsigned char	pr_arg_is_digit(char type);
unsigned char	pr_arg_is_sig(char type);
unsigned char	pr_arg_is_unsigned(char type);
unsigned char	pr_arg_is_char(char type);
unsigned char	pr_arg_is_string(char type);
void			pr_modify_prinf(char type, t_prinf *i, t_prfgs *f);
int				pr_is_no_type(char type);
void			pr_change_modifier(t_prinf *prinf);
int				pr_store_all(va_list args, t_prfgs *f, t_prinf *i, char *fo);
int				pr_flag_is_empty(int fd, t_prfgs *prfgs, t_prinf *prinf);
int				pr_del_and_print(int fd, t_prfgs *prfgs, t_prinf *prinf);
void			pr_get_star(t_prinf *prinf, char *str_flag);
int				pr_get_conversion(char type);
char			*pr_choose_conv(long long arg_num, t_prinf *i);
char			*pr_choose_conv_u(char type, unsigned long long n, t_prinf *i);
char			pr_change_type(char type, t_prinf *prinf);
void			pr_get_arg_ds(char type, va_list args, t_prfgs *f, t_prinf *i);
void			pr_get_arg_du(char type, va_list args, t_prfgs *f, t_prinf *i);
void			pr_get_arg_c(char type, va_list args, t_prfgs *f, t_prinf *i);
void			pr_get_arg_s(char type, va_list args, t_prfgs *f, t_prinf *i);
int				pr_is_end_flag(char type);
void			pr_deal_with_notype(t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_perc(t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_prec_d(t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_digit(char type, t_prfgs *prfgs, t_prinf *prinf);
int				pr_deal_with_char(t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_s(t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_sw(t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_b(char type, t_prfgs *prfgs);
int				pr_deal_with_cw(t_prfgs *prfgs, t_prinf *prinf);
char			*pr_add_space_b(char *str);
void			pr_add_type_front(char type, t_prfgs *prfgs, t_prinf *prinf);
void			pr_deal_with_zero(char type, t_prfgs *prfgs, t_prinf *prinf);
void			pr_reverse_bits(char *str);

#endif
