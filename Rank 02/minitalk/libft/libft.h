/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:27:56 by ramartin          #+#    #+#             */
/*   Updated: 2022/11/14 17:08:09 by ramartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

/*Mandatory*/

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f) (unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*Bonus*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del) (void *));
void			ft_lstdelone(t_list *lst, void (*del) (void *));
void			ft_lstiter(t_list *lst, void (*f) (void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) \
		(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

/*** Extra ***/
/** ft_printf **/
/* Printf */
int				printf_format(va_list args, const char format);
int				ft_printf(const char *format, ...);

/* Character */
int				printf_char(char out);

/* String */
int				printf_string(char *out);

/* Pointer */
int				ptrlen(uintptr_t num);
void			putptr(uintptr_t num);
int				printf_pointer(unsigned long long out);

/* Decimal and Integer */
int				printf_num(int out);

/* Unsigned Decimal */
int				numlen(unsigned	int num);
char			*uitoa(unsigned int n);
int				printf_udec(unsigned int out);

/* Hexadecimal */
int				hexlen(unsigned	int num);
void			puthex(unsigned int num, const char format);
int				printf_hex(unsigned int num, const char format);

#endif
