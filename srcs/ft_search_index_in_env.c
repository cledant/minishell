/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_index_in_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:29:53 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 16:35:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_init_int(int *i, int *index, char **ret)
{
	*i = 0;
	*index = -1;
	*ret = NULL;
}

int				ft_search_index_in_env(char **big, char *little)
{
	char	*ret;
	size_t	len;
	int		index;
	int		size;
	int		i;

	ft_init_int(&i, &index, &ret);
	len = ft_strlen(little);
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
