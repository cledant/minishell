/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_in_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:31:08 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 14:13:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_search_in_env(char **big, char *little)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(little);
	ret = NULL;
	while (ret == NULL && big != NULL && *big != '\0')
	{
		if (ft_strncmp(*big, little, len) == 0)
			ret = *big;
		if (*(*big + len) != '=')
			ret = NULL;
		big++;
	}
	return (ret);
}
