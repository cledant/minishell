/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:44:16 by cledant           #+#    #+#             */
/*   Updated: 2016/01/28 20:18:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_execute_prog(char **argv, char **env)
{
	if (ft_fork_process() == -1)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			ft_putendl_fd("minishell : no such file or directory", 2);
			return (-1);
		}
	}
	else
		return (0);
	return (0);
}
