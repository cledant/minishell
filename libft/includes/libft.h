/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:12:52 by cledant           #+#    #+#             */
/*   Updated: 2016/01/27 18:57:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
	void			*content;
	size_t			content_size;
}					t_btree;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_isspace(int c);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
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
void				ft_putendl(char const *s);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpushback(t_list *alst, t_list *new);
int					ft_abs(int n);
int					ft_isodd(int n);
int					ft_iseven(int n);
void				ft_putnbrendl(int n);
void				ft_putnbrendl_fd(int n, int fd);
void				ft_putendln(char const *s, size_t n);
void				ft_putstrn(char const *s, size_t n);
int					get_next_line(int fd, char **line);
int					ft_max(int i, int j);
int					**ft_int_tab2_new(size_t i, size_t j);
int					ft_can_be_atoi(char *c);
char				**ft_strsplit_allspace(char const *s);
t_list				*ft_lstread_file(int fd);
size_t				ft_lstcount_non_zero_size_node(t_list *list);
size_t				ft_lstcount_node(t_list *list);
int					ft_round_double(double nb);
t_btree				*ft_btree_new(void const *content, size_t content_size);
void				ft_btree_delone(t_btree **alst, void (*del)(void *,
						size_t));
void				ft_btree_del_all_node(t_btree **alst);
void				ft_btree_add_node(t_btree *root, t_btree *new, int
						(*cmpf)(void *, void *));
void				ft_btree_apply_reverse_infix(t_btree *root,
						void (*apply)(void *));
void				ft_btree_apply_infix(t_btree *root,
						void (*apply)(void *));
void				ft_btree_apply_postfix(t_btree *root,
						void (*apply)(void *));
int					ft_strcmp_nchar(const char *s1, const char *s2, size_t n);
void				ft_free_content(void *content, size_t content_size);
int					ft_is_str_a_number(char *str);

#endif
