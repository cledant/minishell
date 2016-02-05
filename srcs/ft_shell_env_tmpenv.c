/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:33:22 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 10:10:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_shell_env_tmpenv(char **argv, char **cpy_env)
{
	int		env_size;
	char	**tmp_env;

	env_size = ft_char2_index_size(cpy_env);
	if ((tmp_env = ft_strnew_char2(env_size + 1)) == NULL)
	{
		ft_strdel_char2(&cpy_env);
		ft_putendl_fd("minishell : not enough free memory", 2);
		return (NULL);
	}
	if ((tmp_env = ft_strcpy_char2(tmp_env, cpy_env)) == NULL)
	{
		ft_strdel_char2(&cpy_env);
		ft_putendl_fd("minishell : not enough free memory", 2);
		return (NULL);
	}
	if ((tmp_env[env_size] = ft_strdup(*argv)) == NULL)
	{
		ft_strdel_char2(&cpy_env);
		ft_strdel_char2(&tmp_env);
		ft_putendl_fd("minishell : not enough free memory", 2);
		return (NULL);
	}
	return (tmp_env);
}
