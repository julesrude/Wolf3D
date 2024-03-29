/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:26:09 by yruda             #+#    #+#             */
/*   Updated: 2019/09/06 19:49:51 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void				*ft_memset(void *dest, int c, size_t count);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst,
					const void *restrict src, size_t n);
void				*ft_memccpy(void *restrict dst,
					const void *restrict src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				ft_strcat_last(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1,
					const char *restrict s2, size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
					size_t dstsize);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_itoa(int n, char *result);
void				ft_putchar(char c);
void				ft_putstr(char *c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstat(t_list *begin_list, unsigned int nbr);
void				ft_lstaddback(t_list **alst, t_list *new);
int					ft_lstsize(t_list *begin_list);
void				ft_lstsortalpha(t_list **head, t_list *current);
void				ft_lstsortcycle(t_list **head, t_list *current);

int					ft_iswhitespace(int c);
size_t				ft_numwords(char const *s);
int					ft_count_words(char const *s);
int					ft_wordlen(char *s);

/*
** math
*/

int					ft_maxarr(int *a, int n);
int					ft_max(int a, int b);
int					ft_minarr(int *a, int n);
int					ft_min(int a, int b);
int					ft_sqrtint(unsigned int i);
int					ft_pow(int num, int pow);

void				ft_arrdel(void **arr, int elems);
char				**ft_arrdup(char **arr, int height, int width);

/*
**	other text functions
*/

void				ft_putstr_four(char *c1, char *c2, char *c3, char *c4);
void				ft_putendl_four(char *c1, char *c2, char *c3, char *c4);
int					ft_strchrindex(const char *s, int c);

int					get_next_line(const int fd, char **line);

#endif
