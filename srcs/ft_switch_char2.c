/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_char2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 19:10:07 by cledant           #+#    #+#             */
/*   Updated: 2016/01/28 09:52:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_switch_char2(char ***str1, char ***str2)
{
	char	**tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
