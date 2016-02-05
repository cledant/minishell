/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_unsetenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:49:08 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 12:10:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_error(char ***cpy_env)
{
	ft_strdel_char2(cpy_env);
	ft_putendl_fd("unsetenv : not enough free memory", 2);
}

static int		ft_cpy_env(char ***env, char ***cpy_env, int index, int size)
{
	int		j;

	j = 0;
	while (j < index)
	{
		if ((cpy_env[0][j] = ft_strdup(env[0][j])) == NULL)
		{
			ft_error(cpy_env);
			return (0);
		}
		j++;
	}
	j++;
	while (j < size)
	{
		if ((cpy_env[0][j - 1] = ft_strdup(env[0][j])) == NULL)
		{
			ft_error(cpy_env);
			return (0);
		}
		j++;
	}
	cpy_env[0][j - 1] = NULL;
	return (1);
}

static void		ft_del(char ***env)
{
	if (*env != NULL)
		ft_strdel_char2(env);
	*env = NULL;
}

static char		**ft_part1(int *size, int *index, char **argv, char ***env)
{
	char **cpy_env;

	*size = ft_char2_index_size(*env);
	*index = ft_search_index_in_env(*env, *argv);
	if ((cpy_env = ft_strnew_char2(*size - 1)) == NULL)
	{
		ft_putendl_fd("setenv : not enough free memory", 2);
		return (NULL);
	}
	return (cpy_env);
}

void			ft_shell_unsetenv(char **argv, char ***env)
{
	int		size;
	int		index;
	char	**cpy_env;

	if ((size = ft_char2_index_size(argv)) != 1)
	{
		argv++;
		while (*argv != '\0')
		{
			if (ft_strcmp(*argv, "*") == 0)
				ft_del(env);
			else if (ft_search_in_env(*env, *argv) != NULL)
			{
				if ((cpy_env = ft_part1(&size, &index, argv, env)) == NULL)
					return ;
				if (ft_cpy_env(env, &cpy_env, index, size) == 0)
					return ;
				ft_switch_char2(env, &cpy_env);
				ft_strdel_char2(&cpy_env);
			}
			argv++;
		}
	}
}
