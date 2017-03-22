/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:03:27 by agouby            #+#    #+#             */
/*   Updated: 2017/03/22 14:16:04 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define ABS(X) (X < 0 ? -X : X)
# define BUFF_SIZE 200

/*
typedef struct	s_boolean
{
	unsigned char boo : 1;
}				t_boolean;
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_split
{
	size_t	len;
	size_t	start;
}				t_split;

char			*ft_strnjoin_del_1(char *s1, char *s2, int s, int e);
int				ft_strchr_b(const char *s, int c);
char			*ft_strnew_set(size_t len, char set);
char			*ft_strnjoin(char const *s1, char const *s2, int s, int e);
char			*ft_strnjoin_del(char const *s1, char const *s2, int s, int e);
void			ft_tab_del(char **tab);
double			ft_deg_to_rad(int deg);
size_t			ft_lstlen(t_list *lst);
size_t			ft_tablen(char **tab);
void			ft_print_error(char *str);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strnchr(const char *s, int c, int size);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long			ft_atoi(const char *str);
int				ft_isspace(int c);
int				ft_isdigit(int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strislower(char *str);
int				ft_strisupper(char *str);
int				ft_strisdigit(char *str);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
int				ft_islower(int c);
int				ft_isupper(int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			ft_swapc(char const *a, char const *b);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
char			*ft_itoa_base(long long n, int base);
char			*ft_itoa_ubase(unsigned long long n, int base);
int				ft_pow(int n, int p);
int				ft_count_digit(long long n, size_t base);
void			ft_memdel(void **ap);
void			ft_strclr(char *str);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strtrim(char const *s);
char			*ft_strrev(char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_del(char const *s1, char const *s2, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				*ft_range(int min, int max);
void			ft_swaps(char **a, char **b);
char			**ft_sorts(char **s, size_t start, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strmap(char const *s, char (*f)(char));
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			**ft_strsplit(char const *s, char c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstrev(t_list *lst);
t_split			ft_getwords(char const *str, size_t start, int c);
size_t			ft_countwords(char *str, int c);
int				get_next_line(const int fd, char **line);
void			ft_swapi(int *a, int *b);
void			ft_swap_tab(int **a, int **b);

#endif
