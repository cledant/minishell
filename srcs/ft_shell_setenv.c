/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_setenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:56:12 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 12:11:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_size_2_2(char ***env, char **argv)
{
	char	**cpy_env;
	int		size;

	size = ft_char2_index_size(*env);
	if ((cpy_env = ft_strnew_char2(size + 1)) == NULL)
	{
		ft_putendl_fd("setenv : not enough free memory", 2);
		return (-1);
	}
	if (size != 0)
		ft_strcpy_char2(cpy_env, *env);
	if ((cpy_env[size] = ft_strjoin(argv[1], "=")) == NULL)
	{
		ft_strdel_char2(&cpy_env);
		ft_putendl_fd("setenv : not enough free memory", 2);
		return (-1);
	}
	ft_switch_char2(env, &cpy_env);
	ft_strdel_char2(&cpy_env);
	return (0);
}

static int		ft_size_2(char ***env, char **argv)
{
	int		index;
	char	*tmp_str;

	if (ft_search_in_env(*env, argv[1]) != NULL)
	{
		index = ft_search_index_in_env(*env, argv[1]);
		if ((tmp_str = ft_strjoin(argv[1], "=")) == NULL)
		{
			ft_putendl_fd("setenv : not enough free memory", 2);
			return (-1);
		}
		ft_switch_str(&env[0][index], &tmp_str);
		ft_strdel(&tmp_str);
	}
	else
		ft_size_2_2(env, argv);
	return (0);
}

static int		ft_size_3_2(char ***env, char **argv)
{
	char	**cpy_env;
	int		size;

	size = ft_char2_index_size(*env);
	if ((cpy_env = ft_strnew_char2(size + 1)) == NULL)
	{
		ft_putendl_fd("setenv : not enough free memory", 2);
		return (-1);
	}
	ft_strcpy_char2(cpy_env, *env);
	if ((cpy_env[size] = ft_strnew(ft_strlen(argv[1]) + 1 +
					ft_strlen(argv[2]))) == NULL)
	{
		ft_strdel_char2(&cpy_env);
		ft_putendl_fd("setenv : not enough free memory", 2);
		return (-1);
	}
	ft_strcat(cpy_env[size], argv[1]);
	ft_strcat(cpy_env[size], "=");
	ft_strcat(cpy_env[size], argv[2]);
	ft_switch_char2(env, &cpy_env);
	ft_strdel_char2(&cpy_env);
	return (0);
}

static int		ft_size_3(char ***env, char **argv)
{
	int		index;
	char	*tmp_str;

	if (ft_search_in_env(*env, argv[1]) != NULL)
	{
		index = ft_search_index_in_env(*env, argv[1]);
		if ((tmp_str = ft_strnew(ft_strlen(argv[1]) + 1 + ft_strlen(argv[2])))
					== NULL)
		{
			ft_putendl_fd("setenv : not enough free memory", 2);
			return (-1);
		}
		ft_strcat(tmp_str, argv[1]);
		ft_strcat(tmp_str, "=");
		ft_strcat(tmp_str, argv[2]);
		ft_switch_str(&env[0][index], &tmp_str);
		ft_strdel(&tmp_str);
	}
	else
		ft_size_3_2(env, argv);
	return (0);
}

void			ft_shell_setenv(char **argv, char ***env)
{
	int		size;

	size = ft_char2_index_size(argv);
	if (size == 1 && *env != NULL)
		ft_putendl_char2(*env);
	else if (size == 2)
	{
		if (ft_shell_setenv_error(argv) == -1)
			return ;
		ft_size_2(env, argv);
	}
	else if (size == 3)
	{
		if (ft_shell_setenv_error(argv) == -1)
			return ;
		ft_size_3(env, argv);
	}
	else
		ft_putendl_fd("setenv : too much arguments", 2);
}
