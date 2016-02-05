/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:02:48 by cledant           #+#    #+#             */
/*   Updated: 2016/01/30 20:48:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_execute_builtin(char **argv, char ***env, char *line, char **i_env)
{
	int		exec;

	exec = ft_is_cmd_builtin(argv[0]);
	if (exec == 5)
		ft_shell_exit(argv, *env, line, i_env);
	else if (exec == 2)
	{
		if (ft_shell_env(argv, *env, i_env) == -1)
			return (-1);
	}
	else if (exec == 3)
		ft_shell_setenv(argv, env);
	else if (exec == 4)
		ft_shell_unsetenv(argv, env);
	else if (exec == 1)
		ft_shell_cd(argv, env, i_env);
	return (0);
}
