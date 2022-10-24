/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:56:51 by lasalmi           #+#    #+#             */
/*   Updated: 2022/10/11 12:13:40 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BUFF_SIZE 8
# define FD_MAX 4096
# define MAP_SIZE 100000

typedef enum e_caller {
	FT_PRINTF,
	FT_DPRINTF,
	FT_SPRINTF
}	t_pf_caller;

typedef enum e_length
{
	PF_INIT,
	PF_HH,
	PF_H,
	PF_L,
	PF_LL,
	PF_LONGD
}	t_length;

typedef struct s_flags
{
	int			padleft;
	int			sign;
	int			space;
	int			pad_with_zeroes;
	int			alt_form;
	t_length	length;
}	t_flags;

typedef enum e_ft_stage
{
	FT_READ_PRINT,
	FT_READ_SPEC,
	FT_CONV_CHAR,
	FT_CONV_STR,
	FT_CONV_PTR,
	FT_conv_oux,
	FT_CONV_DI,
	FT_CONV_FLOAT,
	FT_WRITE,
	FT_END,
	___UNUSED
}	t_stage;

typedef struct s_vardata
{
	size_t	padlen;
	size_t	conv_len;
	size_t	zero_prec;
	uint8_t	toupper;
	size_t	intlen;
}	t_vardata;

typedef struct s_strdata
{
	t_pf_caller	caller;
	t_flags		flags;
	size_t		width;
	size_t		precision;
	uint8_t		explicit_zeroprec;
	char		*variable_str;
	size_t		strlen;
	char		*padding;
	int			padlen;
	const char	*working_format;
	va_list		list;
}	t_strdata;

typedef struct s_pf_controller
{
	t_stage		stage;
	size_t		chars_written;
	int			format_i;
	t_pf_caller	caller;
	int			fd;
	char		*temp_print;
	size_t		size;
}	t_pf_controller;

typedef enum e_status
{
	OKAY,
	MALLOCFAIL,
	WRITE,
	NULLBYTE,
	PERCENT,
	ERROR,
	_UNUSED
}	t_status;

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct s_hashmap
{
	void	*ptr;
	char	*key;
}	t_hashmap;

typedef void			(*t_myfunc)(t_pf_controller*, t_strdata*);

size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_isascii(int c);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnew(size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_atoi(const char *str);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
char				*ft_strnstr(const char *haystack, \
const char *needle, size_t len);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putendl(const char *s);
char				*ft_strtrim(const char *s);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isprint(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_memdel(void **ap);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strpbrk(const char *s, const char *charset);
size_t				ft_strcspn(const char *s, const char *charset);
size_t				ft_strspn(const char *s, const char *charset);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strsep(char **stringp, const char *delim);
size_t				ft_intlen(long long nb);
int					get_next_line(const int fd, char **line);
int					ft_getchar(void);
char				*ft_getnbrs(char **str);
size_t				ft_filerows(char *file);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
void				ft_swap(int *a, int *b);
int					ft_printf(const char *input_format, ...);
void				ft_pf_stage_to_write(t_pf_controller *pf_controller);
void				ft_pf_stage_to_end(t_pf_controller *pf_controller);
void				ft_pf_stage_to_read_spec(t_pf_controller *pf_controller);
t_status			ft_check_character(char c);
t_status			ft_pf_conv_char(t_strdata *strdata, int c);
t_status			ft_pf_conv_str(t_strdata *strdata, char *str);
t_stage				ft_pf_read_conv(t_strdata *strdata);
void				ft_pf_print(t_pf_controller *pf_controller, \
t_strdata *strdata);
void				ft_pf_handle_char(t_pf_controller *pf_controller, \
t_strdata *strdata);
void				ft_pf_set_stage_to(t_pf_controller \
*pf_controller, t_stage to);
t_status			ft_pf_pad_with(t_strdata *strdata, char c);
void				ft_conv_handler(t_pf_controller *pf_controller, \
t_strdata *strdata);
void				ft_pf_read_specifiers(t_pf_controller *pf_controller, \
t_strdata *strdata);
void				ft_pf_handle_str(t_pf_controller *pf_controller, \
t_strdata *strdata);
void				ft_pf_handle_ptr(t_pf_controller *pf_controller, \
t_strdata *strdata);
t_status			ft_pf_convert_hexa(t_strdata *strdata, long long ptr);
void				ft_pf_init_strdata(t_strdata *data_to_init);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_toupper(int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_isdigit(int c);
void				ft_pf_oux_handler(t_pf_controller *pf_controller, \
t_strdata *strdata);
void				ft_conv_oux(unsigned long long nb, \
int base, size_t intlen, char *str);
void				ft_pf_get_uint_data(t_vardata *vardata, \
unsigned long long nb, int base, t_strdata *strdata);
int					ft_pf_get_conv_base(t_strdata *strdata);
void				ft_add_zeropad(char **str, size_t padlen);
void				ft_pf_add_0x(char **str, long long var, t_strdata *strdata);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
void				ft_pf_read_length(t_strdata *strdata);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_pf_check_zeropadding(t_vardata \
*vardata, t_strdata *strdata);
void				ft_pf_get_sint_len(t_vardata *vardata, \
long long nb, t_strdata *strdata);
void				ft_pf_handle_di(t_pf_controller \
*pf_controller, t_strdata *strdata);
void				ft_conv_di(long long nb, \
int base, size_t intlen, char *str);
void				ft_pf_uox_padding(t_strdata *strdata, \
t_vardata vardata);
void				ft_pf_skip_leading_zeroes(const char **str);
void				ft_pf_get_double_len(t_vardata *vardata, \
long double nb, t_strdata *strdata);
void				ft_pf_conv_f(t_vardata *vardata, \
t_strdata *strdata, long double nb, char *str);
void				ft_pf_handle_f(t_pf_controller \
*pf_controller, t_strdata *strdata);
void				ft_pf_round_f_str(char **str, t_strdata *strdata, \
size_t i, long double nb);
int					ft_pf_need_upround(long double d, int precision, \
t_strdata *strdata);
void				ft_pf_init_pf_controller(t_pf_controller *pf_controller);
void				ft_pf_init_strdata(t_strdata *data_to_init);
void				ft_pf_init_flags(t_flags *flags_to_init);
void				ft_pf_init_vardata(t_vardata *vardata);
void				ft_read_format(t_pf_controller \
*pf_controller, t_strdata *strdata);
void				ft_write_iterated(t_pf_controller \
*pf_controller, t_strdata *strdata);
int					ft_dprintf(int fd, const char *input_format, ...);
int					ft_pf_writer(t_pf_controller *pf_controller, \
const char *to_print, size_t len);
int					ft_output_error(t_pf_controller \
*pf_controller, t_strdata *strdata);
int					ft_sprintf(char	*str, const char *input_format, ...);
int					ft_snprintf(char *str, size_t size, \
const char *input_format, ...);
void				ft_pf_mallocfail(t_strdata *strdata);
void				ft_quicksortint(int *arr, int len);
int					ft_abs(int value);
int					ft_is_in_range(int nb, int start, int end);
int					ft_diff(int a, int b);
void				ft_pf_dispatcher(t_pf_controller *pf_controller, \
t_strdata *strdata, int func_index);
int					ft_file_rows(char *file);
char				***ft_file_split(char *file, char *delim);
char				**ft_line_split(char *str, char *delim);
int					ft_is_number(char *str);
int					ft_is_int(char *str);
void				ft_free_str_arr(char ***arr);
unsigned long long	ft_hash_key(char *str);
t_hashmap			*ft_hash_map(void);
int					ft_hash_add(void *ptr, char *key);
void				*ft_hash_search(char *key);
int					ft_hash_remove(char *key);
#endif
