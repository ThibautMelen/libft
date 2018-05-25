/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroussel <jroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:18:28 by jroussel          #+#    #+#             */
/*   Updated: 2018/05/25 18:37:22 by jroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# define BUFF_SIZE 1024
# define SPLITTER '\n'

typedef unsigned char	t_byte;
typedef struct			s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}						t_list;
typedef struct			s_vars
{
	t_byte	buff[BUFF_SIZE];
	int		pb;
	int		pf;
	int		len;
	t_byte	*output;
	char	order[6];
	char	size;
	int		width;
	int		precision;
	char	flag;
	int		options[49];
	int		olen;
	char	*prefix;
	int		prlen;
	char	*value;
	int		valen;
	int		negative;
}						t_vars;
typedef struct			s_func
{
	void	(*call)(t_vars *, va_list *);
	char	flag;
}						t_func;
typedef struct			s_color
{
	char	*id;
	char	*value;
}						t_color;

/*
** Memory
*/
void					*ft_memset(void *mem, int byte, size_t size);
void					ft_bzero(void *mem, size_t size);
void					*ft_memcpy(void *dest, const void *src, size_t size);
void					*ft_memccpy(void *dest, const void *src, int chr,
									size_t size);
void					*ft_memmove(void *dest, const void *src, size_t size);
void					*ft_memchr(const void *mem, int chr, size_t size);
int						ft_memcmp(const void *mem1, const void *mem2,
									size_t size);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ptr);

/*
** String
*/
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t size);
char					*ft_strcat(char *str1, const char *str2);
char					*ft_strncat(char *str1, const char *str2, size_t size);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strchr(const char *str, int chr);
char					*ft_strrchr(const char *str, int chr);
char					*ft_strstr(const char *str, const char *search);
char					*ft_strnstr(const char *str, const char *search,
									size_t size);
int						ft_strcmp(const char *str1, const char *str2);
int						ft_strncmp(const char *str1, const char *str2,
									size_t size);
char					*ft_strnew(size_t size);
void					ft_strdel(char **ptr);
void					ft_strclr(char *str);
void					ft_striter(char *str, void (*f)(char *));
char					*ft_strsub(const char *str, unsigned int start,
									size_t size);
char					*ft_strjoin(const char *str1, const char *str2);
char					*ft_strjoinch(const char *str, char chr);
char					*ft_strtrim(const char *str);
char					**ft_strsplit(const char *str, char c);
void					ft_strupper(char *str);
void					ft_strlower(char *str);
void					ft_strcapitalize(char *str);

/*
** List
*/
t_list					*ft_lstnew(const void *content, size_t size);
void					ft_lstdel(t_list **plist);
size_t					ft_lstlen(t_list *list);
void					ft_lstadd(t_list **plist, t_list *new);
void					ft_lstaddi(t_list **plist, t_list *new, int index);
void					ft_lstpush(t_list **plist, t_list *new);
void					ft_lstremove(t_list **plist, t_list *elem);
t_list					*ft_lstget(t_list *list, int index);
void					ft_lstiter(t_list *list, void (*f)(t_list *elem));

/*
** Writers
*/
int						ft_printf(const char *format, ...);

/*
** Testers
*/
int						ft_isblank(int chr);
int						ft_islower(int chr);
int						ft_isupper(int chr);
int						ft_isalpha(int chr);
int						ft_isdigit(int chr);
int						ft_isalnum(int chr);
int						ft_isascii(int chr);
int						ft_isprint(int chr);
int						ft_isnumber(const char *str);

/*
** Converters
*/
long					ft_atol(const char *str);
char					*ft_ltoa(intmax_t nbr);
char					*ft_ultoa(uintmax_t nbr);
char					*ft_ultoa_base(uintmax_t nbr, uint8_t base);
int						ft_toupper(int chr);
int						ft_tolower(int chr);

/*
** Reader
*/
int						ft_gnl(const int fd, char **line);

/*
** For ft_printf
*/
void					write_buff(t_byte byte, t_vars *vars);
void					print_buff(t_vars *vars);
void					parse_color(const char *f, t_vars *vars, va_list *args);
void					convert(t_vars *vars, va_list *args);
void					format(t_vars *vars);
void					write_output(t_vars *vars);
void					create_output(t_vars *vars);
void					parse(const char *format, t_vars *vars, va_list *args);
void					write_unicode(t_vars *vars, wchar_t wc, int s, int *i);
int						bin_size(wchar_t wc);
int						isflag(int type, char c);
void					define_prefix(t_vars *vars);
void					init_vars(t_vars *vars);
void					reinit_vars(t_vars *vars);
void					func_s(t_vars *vars, va_list *args);
void					func_ss(t_vars *vars, va_list *args);
void					func_p(t_vars *vars, va_list *args);
void					func_d(t_vars *vars, va_list *args);
void					func_dd(t_vars *vars, va_list *args);
void					func_i(t_vars *vars, va_list *args);
void					func_o(t_vars *vars, va_list *args);
void					func_oo(t_vars *vars, va_list *args);
void					func_u(t_vars *vars, va_list *args);
void					func_uu(t_vars *vars, va_list *args);
void					func_x(t_vars *vars, va_list *args);
void					func_xx(t_vars *vars, va_list *args);
void					func_c(t_vars *vars, va_list *args);
void					func_cc(t_vars *vars, va_list *args);
void					func_percent(t_vars *vars, va_list *args);
void					func_n(t_vars *vars, va_list *args);
void					alt_func_c(t_vars *vars, char c);

#endif
