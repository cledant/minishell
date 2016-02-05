/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2_index_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:31:20 by cledant           #+#    #+#             */
/*   Updated: 2016/01/29 14:54:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char2_index_size(char **argv)
{
	int		count;

	count = 0;
	while (argv != NULL && *argv != '\0')
	{
		count++;
		argv++;
	}
	return (count);
}
