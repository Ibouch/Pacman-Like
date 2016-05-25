/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:47:12 by ibouchla          #+#    #+#             */
/*   Updated: 2016/04/14 22:28:54 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define TRUE	1
# define FALSE	0
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <ft_styles.h>

typedef int			t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_strcolor_fd(char *s, char *color, int fd, t_bool endl);
size_t				ft_size_tab(char **tab);
void				ft_error_system(void);
void				ft_print_tab(char **tab, int fd);
void				ft_tabdel(char **tab);
void				ft_print_lst(t_list *lst, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lst_at(t_list *begin_lst, unsigned int id);
int					ft_lst_size(t_list *begin_lst);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, void *data, size_t size);
void				ft_lstadd_back(t_list **begin_lst, void *data, size_t size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lst_sort(t_list **alst, int (*f_cmp)());
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
size_t				ft_nbrlen(int nbr);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr_long(long n);
void				ft_putnbr(int n);
void				ft_putnbr_endl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_long_fd(long n, int fd);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
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
char				*ft_itoa(int n);
void				ft_memswap(void *a, void *b, size_t size);
void				ft_strrev(char *str);
int					ft_biggest_str(char *s1, char *s2, char *to_check);
int					ft_isspace(int c);
void				ft_strswap(char **as1, char **as2);
int					ft_strsort(char **as, int len);
char				*ft_readlink(char *path, off_t size);

#endif
