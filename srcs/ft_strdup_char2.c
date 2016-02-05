/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_char2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:23:47 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 14:28:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_strdup_char2(char **str)
{
	int		index_count;
	char	**ret;
	int		i;

	i = 0;
	index_count = ft_char2_index_size(str);
	if ((ret = (char **)malloc(sizeof(char *) * (index_count + 1))) == NULL)
		return (NULL);
	while (i < index_count + 1)
		ret[i++] = NULL;
	i = 0;
	while (i < index_count)
	{
		if ((ret[i] = ft_strdup(str[i])) == NULL)
		{
			ft_strdel_char2(&ret);
			return (NULL);
		}
		i++;
	}
	if (index_count == 0)
		ret[0] = NULL;
	return (ret);
}
