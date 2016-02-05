/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_cmd_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 08:51:10 by cledant           #+#    #+#             */
/*   Updated: 2016/01/26 09:01:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_is_cmd_builtin(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (2);
	else if (ft_strcmp(str, "setenv") == 0)
		return (3);
	else if (ft_strcmp(str, "unsetenv") == 0)
		return (4);
	else if (ft_strcmp(str, "exit") == 0)
		return (5);
	else
		return (0);
}
