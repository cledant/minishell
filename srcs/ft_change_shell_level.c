/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_shell_level.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:00:02 by cledant           #+#    #+#             */
/*   Updated: 2016/01/31 16:23:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		ft_case_2_int(int *shlvl, char **tmp_2,
								char **tmp, char ***tmp_set)
{
	*shlvl = ft_atoi(*tmp + 6) + 1;
	if ((*tmp_2 = ft_itoa(*shlvl)) == NULL)
	{
		ft_putendl_fd("minishell : not enough memory", 2);
		return (-1);
	}
	if ((*tmp = ft_strjoin("setenv SHLVL ", *tmp_2)) == NULL)
	{
		ft_strdel(tmp_2);
		ft_putendl_fd("minishell : not enough memory", 2);
		return (-1);
	}
	if ((*tmp_set = ft_strsplit_allspace(*tmp)) == NULL)
	{
		ft_strdel(tmp);
		ft_strdel(tmp_2);
		ft_putendl_fd("minishell : not enough memory", 2);
		return (-1);
	}
	return (0);
}

void			ft_change_shell_level(char ***cpy_env)
{
	char	*tmp;
	char	*tmp_2;
	char	**tmp_set;
	int		shlvl;

	if ((tmp = ft_search_in_env(*cpy_env, "SHLVL")) == NULL)
	{
		if ((tmp_set = ft_strsplit_allspace("setenv SHLVL 1")) == NULL)
		{
			ft_putendl_fd("minishell : not enough memory", 2);
			return ;
		}
		ft_shell_setenv(tmp_set, cpy_env);
		ft_strdel_char2(&tmp_set);
	}
	else
	{
		if (ft_case_2_int(&shlvl, &tmp_2, &tmp, &tmp_set) == -1)
			return ;
		ft_shell_setenv(tmp_set, cpy_env);
		ft_strdel_char2(&tmp_set);
		ft_strdel(&tmp);
		ft_strdel(&tmp_2);
	}
}
