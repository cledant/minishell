/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_index_in_env_with_stop.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:10:55 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 16:40:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_init_int(int *i, int *index, char **ret)
{
	*i = 0;
	*index = -1;
	*ret = NULL;
}

int				ft_search_index_in_env_with_stop(char **big, char *little,
													int c)
{
	char	*ret;
	size_t	len;
	int		index;
	int		size;
	int		i;

	ft_init_int(&i, &index, &ret);
	len = ft_strlen_till_char(little, c);
	size = ft_char2_index_size(big);
	while (ret == NULL && big != NULL && *big != '\0')
	{
		if (ft_strncmp(*big, little, len) == 0)
		{
			ret = *big;
			index = i;
		}
		if (*(*big + len) != '=')
		{
			index = -1;
			ret = NULL;
		}
		big++;
		i++;
	}
	return (index);
}
