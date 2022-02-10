/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 13:06:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "color.h"
# include "gfd.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>

# define STDIN	0
# define STDOUT	1
# define STDERR	2

# ifndef PB_BUFFER
#  define PB_BUFFER	40000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_split_next
{
	size_t			start;
	size_t			len;
}					t_split_next;

void			*ft_memset(void *s, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strnstr(const char *s, const char *to_find, size_t len);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);
double			ft_atof(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

ssize_t			ft_ps(char *str);
ssize_t			ft_psc(char *str, char *color);
ssize_t			ft_pser(char *str);
ssize_t			ft_pserc(char *str, char *color);
ssize_t			ft_pn(int nbr);
ssize_t			ft_pner(int nbr);
ssize_t			ft_pnc(int nbr, char *color);
ssize_t			ft_pnerc(int nbr, char *color);

void			ft_pb(const bool w, const char *str);
void			ft_pb_s(const bool w, const char *str, const size_t size);
size_t			ft_pb_f(const bool w, const char *str);
bool			ft_pb_oms(const bool w, const char *str, const size_t size);
bool			ft_pb_omsa(const bool w, const char *str, const size_t size);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strcpy(char *dst, const char *src);
size_t			ft_strlcpy(char *dst, const char *src, const size_t size);
size_t			ft_strocpy(char *dst, const char *src, const size_t size);
char			*ft_strjoin_free(char *s1, char *s2,
					bool const f1, bool const f2);

int				ft_nbrlen(int nb);
int				ft_abs(int n);
bool			ft_is_prime(int n);
bool			ft_is_prime_ul(unsigned long n);
int				ft_next_prime(int n);
int				ft_prev_prime(int n);
unsigned long	ft_next_prime_ul(unsigned long n);
unsigned long	ft_prev_prime_ul(unsigned long n);

#endif
