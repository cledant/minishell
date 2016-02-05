/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek_exec_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:48:57 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 15:34:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_disp_error(char **argv)
{
	ft_putstr_fd("minishell : command not found : ", 2);
	ft_putendl_fd(argv[0], 2);
}

static int		ft_seek_while(char **list, char **cpy_list,
								char **env, char **argv)
{
	int		ret;
	char	*tmp;
	char	*path;

	ret = -1;
	while (ret == -1 && *list != '\0')
	{
		if ((tmp = ft_strjoin(*list, "/")) == NULL)
		{
			ft_putendl_fd("minishell : not enough free memory", 2);
			return (-1);
		}
		if ((path = ft_strjoin(tmp, argv[0])) == NULL)
		{
			ft_putendl_fd("minishell : not enough free memory", 2);
			return (-1);
		}
		ret = execve(path, argv, env);
		list++;
		ft_strdel_two_char(&tmp, &path);
	}
	if (*list == '\0')
		ft_disp_error(argv);
	ft_strdel_char2(&cpy_list);
	return (ret);
}

static int		ft_check_path(char **path, char **argv)
{
	*path = *path + 5;
	if (**path == '\0')
	{
		ft_putstr_fd("minishell : command not found : ", 2);
		ft_putendl_fd(argv[0], 2);
		return (-1);
	}
	return (0);
}

static int		ft_part_1(char **argv, char **env,
							char **init_env, char *path)
{
	char	**list;
	char	**cpy_list;
	int		ret;

	if ((path = ft_search_in_env(init_env, "PATH")) == NULL)
	{
		ft_disp_error(argv);
		return (-1);
	}
	else
	{
		if (ft_check_path(&path, argv) != -1)
		{
			if ((list = ft_strsplit(path, ':')) == NULL)
			{
				ft_putendl_fd("minishell : not enough free memory", 2);
				return (-1);
			}
			cpy_list = list;
			ret = ft_seek_while(list, cpy_list, env, argv);
		}
		else
			return (-1);
	}
	return (ret);
}

int				ft_seek_exec_path(char **argv, char **env, char **init_env)
{
	int		ret;

	ret = -1;
	if (ft_fork_process() == -1)
		ret = ft_part_1(argv, env, init_env, NULL);
	else
		return (0);
	return (ret);
}
