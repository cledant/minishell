/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:36:20 by cledant           #+#    #+#             */
/*   Updated: 2015/12/10 13:35:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *loc;

	loc = (char *)malloc((size + 1) * sizeof(char));
	if (loc != NULL)
		ft_bzero(loc, (size + 1));
	return (loc);
}
