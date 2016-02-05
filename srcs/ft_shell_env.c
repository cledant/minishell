/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:33:22 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 11:07:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_part_1_5(char ***av, char ***cpy_env)
{
	char	**tmp_env;

	tmp_env = NULL;
	if ((tmp_env = ft_shell_env_tmpenv(*av, *cpy_env)) == NULL)
		return (0);
	ft_switch_char2(&tmp_env, cpy_env);
	if (tmp_env != NULL)
		ft_strdel_char2(&tmp_env);
	return (1);
}

static int		ft_part_1(char ***av, char ***cpy_env,
					int index_size, char *tmp_str)
{
	while (**av != NULL && ft_strchr(**av, '=') != NULL)
	{
		if (ft_search_in_env_with_stop(*cpy_env, **av, '=') != NULL)
		{
			index_size = ft_search_index_in_env_with_stop(*cpy_env, **av, '=');
			if ((tmp_str = ft_strdup(**av)) == NULL)
			{
				ft_strdel_char2(cpy_env);
				ft_putendl_fd("minishell : not enough free memory", 2);
				return (0);
			}
			ft_switch_str(&cpy_env[0][index_size], &tmp_str);
			if (tmp_str != NULL)
				ft_strdel(&tmp_str);
		}
		else
		if (ft_part_1_5(av, cpy_env) == 0)
			return (0);
		(*av)++;
	}
	return (1);
}

static int		ft_part2(char **argv, char **cpy_env, char **i_env)
{
	if (*argv == NULL)
	{
		if (cpy_env == NULL)
			return (0);
		else
			ft_putendl_char2(cpy_env);
	}
	else
	{
		if (ft_strchr(*argv, '/') != NULL)
		{
			if (ft_execute_prog(argv, cpy_env) == -1)
				return (-1);
		}
		else
		{
			if (ft_seek_exec_path(argv, cpy_env, i_env) == -1)
				return (-1);
		}
	}
	return (1);
}

static int		ft_part_0_5(char ***argv, char ***cpy_env, char **env)
{
	(*argv)++;
	if ((*cpy_env = ft_strdup_char2(env)) == NULL)
	{
		ft_putendl_fd("minishell : not enough free memory", 2);
		return (0);
	}
	while (**argv != NULL && ft_strcmp(**argv, "-i") == 0)
	{
		if (*cpy_env != NULL)
			ft_strdel_char2(cpy_env);
		else
			*cpy_env = NULL;
		(*argv)++;
	}
	return (1);
}

int				ft_shell_env(char **argv, char **env, char **i_env)
{
	int		index_size;
	char	**cpy_env;

	index_size = ft_char2_index_size(argv);
	if (ft_check_shell_env_arg(argv) == -1)
		return (0);
	if (index_size == 1 && env != NULL)
		ft_putendl_char2(env);
	else
	{
		if (ft_part_0_5(&argv, &cpy_env, env) == 0)
			return (0);
		if (ft_part_1(&argv, &cpy_env, index_size, NULL) == 0)
			return (0);
		if ((index_size = ft_part2(argv, cpy_env, i_env)) != 1)
			return (index_size);
		if (cpy_env != NULL)
			ft_strdel_char2(&cpy_env);
	}
	return (0);
}
