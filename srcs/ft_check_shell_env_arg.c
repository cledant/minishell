/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_shell_env_arg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:30:18 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 15:35:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_shell_env_arg(char **argv)
{
	while (*argv != NULL)
	{
		if (ft_strncmp(*argv, "=", 1) == 0)
		{
			ft_putendl_fd("env : argument invalid", 2);
			return (-1);
		}
		argv++;
	}
	return (0);
}
