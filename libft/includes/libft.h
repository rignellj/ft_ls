/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:08:35 by jrignell          #+#    #+#             */
/*   Updated: 2020/04/23 13:07:04 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
********************************************************************************
**                                                                            **
**                         LIBRARIES                                          **
**                                                                            **
********************************************************************************
*/

# include <unistd.h>
# include "../printf_srcs/includes/ft_printf.h"

/*
********************************************************************************
**                                                                            **
**                         MACROS                                             **
**                                                                            **
********************************************************************************
*/

# define BUFF_SIZE 25
# define FD_SIZE 4000
# define FT_ULONG_MAX 18446744073709551615
# define FT_LONG_MAX 9223372036854775807
# define FT_LONG_MIN -9223372036854775808
# define FT_UINT_MAX 4294967295
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648
# define FT_USHRT_MAX 65535
# define FT_SHRT_MAX 32767
# define FT_SHRT_MIN -32768
# define FT_CHAR_MAX 127
# define FT_CHAR_MIN -128
# define FT_UCHAR_MAX 255
# define FT_ABS(x) (x > 0 ? x : -x)

/*
********************************************************************************
**                                                                            **
**                         STRUCT(S)                                          **
**                                                                            **
********************************************************************************
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
********************************************************************************
**                                                                            **
**                         ENUM(S)                                            **
**                                                                            **
********************************************************************************
*/

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
********************************************************************************
**                                                                            **
**                         INT FUNCTIONS                                      **
**                                                                            **
********************************************************************************
*/

unsigned short		ft_numlen(long long num);

int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isspace(int c);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					get_next_line(const int fd, char **line);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi_base(const char *str, int str_base);

size_t				ft_arraylen(const char **arr);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
********************************************************************************
**                                                                            **
**                         CHAR * FUNCTIONS                                   **
**                                                                            **
********************************************************************************
*/

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_implode(char **s);
char				*ft_add_char(char *s, int c);
char				*ft_only_space(char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_joindel(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_lftoa(long double value, size_t precision);
char				*ft_itoa_base(long long int value, int base, int upper);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_itoa_base_u(unsigned long long int value,
					int base, int upper);

/*
********************************************************************************
**                                                                            **
**                         CHAR ** FUNCTIONS                                  **
**                                                                            **
********************************************************************************
*/

char				**ft_strsplit(char const *s, char c);
char				**ft_array_push(char **old, char const *append);
char				**ft_arraynew(size_t size);

/*
********************************************************************************
**                                                                            **
**                         VOID FUNCTIONS                                     **
**                                                                            **
********************************************************************************
*/

void				ft_putnbr_ull_fd(unsigned long long int n, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long long int n);
void				ft_putnbr_fd(long long int n, int fd);
void				ft_memdel(void **ap);
void				ft_mem_arrdel(void **tab);
void				ft_strdel(char **as);
void				ft_strfee(char const *s1, char const *s2, char const *s3);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_swap(void **first, void **second);

/*
********************************************************************************
**                                                                            **
**                         VOID * FUNCTIONS                                   **
**                                                                            **
********************************************************************************
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);

/*
********************************************************************************
**                                                                            **
**                         LIST FUNCTIONS                                     **
**                                                                            **
********************************************************************************
*/

int					ft_lstiterif(t_list *lst, int (*f)(t_list *elem));

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstget_first(t_list *current);
t_list				*ft_lstget_last(t_list *current);

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_print_current_node(t_list **node);

/*
********************************************************************************
**                                                                            **
**                         SORT FUNCTIONS                                     **
**                                                                            **
********************************************************************************
*/

t_list				*ft_mergesort(t_list *node, int (*cmp)(void *, void *));
void				ft_qsort(char **str, int first, int last,
					int (*cmp)(void*, void*));
void				ft_bubblesort(char **array);

#endif
