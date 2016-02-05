/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char2_cpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:41:59 by cledant           #+#    #+#             */
/*   Updated: 2016/01/28 21:09:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_strnew_char2(int size)
{
	char	**ret;
	int		i;

	i = 0;
	if ((ret = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}
