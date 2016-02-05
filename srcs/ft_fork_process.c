/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:44:16 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 14:16:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_fork_process(void)
{
	pid_t	father;
	int		ret;

	ret = 0;
	father = fork();
	if (father == 0)
		return (-1);
	else
		wait(&father);
	return (ret);
}
