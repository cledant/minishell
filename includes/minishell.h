/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:00:31 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 12:58:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>

char	**ft_strdup_char2(char **str);
char	**ft_strcpy_char2(char **dst, char **src);
void	ft_switch_char2(char ***str1, char ***str2);
int		ft_char2_index_size(char **argv);
void	ft_strdel_char2(char ***argv);
void	ft_putendl_char2(char **str);
char	**ft_strnew_char2(int size);
void	ft_switch_str(char **str1, char **str2);
size_t	ft_strlen_till_char(const char *s, int c);
int		ft_is_str_alphanum(char *str);
int		ft_is_str_only_spaces(char *str);
void	ft_shell_exit(char **argv, char **env, char *line, char **i_env);
void	ft_shell_setenv(char **argv, char ***env);
int		ft_shell_setenv_error(char **argv);
void	ft_shell_unsetenv(char **argv, char ***env);
int		ft_shell_env(char **argv, char **env, char **i_env);
char	**ft_shell_env_tmpenv(char **argv, char **cpy_env);
void	ft_shell_cd(char **argv, char ***env, char **i_env);
int		ft_check_shell_env_arg(char **argv);
int		ft_seek_exec_path(char **argv, char **env, char **init_env);
int		ft_is_cmd_builtin(char *str);
int		ft_execute_builtin(char **argv, char ***env, char *line, char **i_env);
int		ft_execute_prog(char **argv, char **env);
int		ft_fork_process(void);
char	*ft_search_in_env(char **big, char *little);
char	*ft_search_in_env_with_stop(char **big, char *little, int c);
int		ft_search_index_in_env(char **big, char *little);
int		ft_search_index_in_env_with_stop(char **big, char *little, int c);
char	*ft_get_current_dir(void);
void	ft_change_shell_level(char ***cpy_env);
void	ft_strdel_two_char(char **first, char **second);
void	ft_signal(int sig);

#endif
