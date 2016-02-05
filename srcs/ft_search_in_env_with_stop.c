/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_in_env_with_stop.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:07:27 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 14:13:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_search_in_env_with_stop(char **big, char *little, int c)
{
	char	*ret;
	size_t	len;

	len = ft_strlen_till_char(little, c);
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
