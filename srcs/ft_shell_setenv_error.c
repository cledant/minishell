/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_setenv_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:08:15 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 09:44:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_shell_setenv_error(char **argv)
{
	if (ft_is_str_alphanum(argv[1]) == 0)
	{
		ft_putendl_fd("setenv : variable name must be alphanumeric", 2);
		return (-1);
	}
	if (ft_isalpha(argv[1][0]) == 0)
	{
		ft_putendl_fd("setenv : variable first char must be a char", 2);
		return (-1);
	}
	return (0);
}
