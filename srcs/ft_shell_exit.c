/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:18:43 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 18:37:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_shell_exit_clear(char **argv, char **env, char *line,
								char **i_env)
{
	if (i_env != NULL)
		ft_strdel_char2(&i_env);
	if (env != NULL)
		ft_strdel_char2(&env);
	ft_strdel(&line);
	ft_strdel_char2(&argv);
}

static void		ft_exit_part2(char **argv, char **env, char *line,
								char **i_env)
{
	int		ret;

	ret = 0;
	if (ft_is_str_a_number(argv[1]) == 1)
	{
		ret = ft_atoi(argv[1]);
		ft_shell_exit_clear(argv, env, line, i_env);
		exit(ret);
	}
	else
		ft_putendl_fd("exit : need numerical argument", 2);
}

void			ft_shell_exit(char **argv, char **env, char *line,
								char **i_env)
{
	int		size;
	int		ret;

	ret = 0;
	if ((size = ft_char2_index_size(argv)) > 2)
	{
		ft_putendl_fd("exit : too many arguments", 2);
		return ;
	}
	else
	{
		if (size == 1)
		{
			ft_shell_exit_clear(argv, env, line, i_env);
			exit(0);
		}
		else
			ft_exit_part2(argv, env, line, i_env);
	}
}
