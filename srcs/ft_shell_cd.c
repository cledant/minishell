/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:15:51 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 15:41:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_setoldpwd(char ***env)
{
	char	*tmp;
	char	*get_env;
	char	**set_env;

	if ((get_env = ft_search_in_env(*env, "PWD")) != NULL)
	{
		if ((tmp = ft_strjoin("setenv OLDPWD ", (get_env + 4))) == NULL)
		{
			ft_putendl_fd("cd : error setting OLDPWD : no free memory", 2);
			return ;
		}
		if ((set_env = ft_strsplit_allspace(tmp)) == NULL)
		{
			ft_strdel(&tmp);
			ft_putendl_fd("cd : error setting OLDPWD : no free memory", 2);
			return ;
		}
		ft_shell_setenv(set_env, env);
		ft_strdel(&tmp);
		ft_strdel_char2(&set_env);
	}
}

static void		ft_setpwd(char ***env, char *get_dir)
{
	char	*tmp;
	char	**set_env;

	if ((get_dir = ft_get_current_dir()) == NULL)
	{
		ft_putendl_fd("cd : error while setting PWD", 2);
		return ;
	}
	if ((tmp = ft_strjoin("setenv PWD ", get_dir)) == NULL)
	{
		ft_strdel(&get_dir);
		ft_putendl_fd("cd : error while setting PWD : no free memory", 2);
		return ;
	}
	if ((set_env = ft_strsplit_allspace(tmp)) == NULL)
	{
		ft_strdel(&get_dir);
		ft_strdel(&tmp);
		ft_putendl_fd("cd : error while setting PWD : no free memory", 2);
		return ;
	}
	ft_shell_setenv(set_env, env);
	ft_strdel(&get_dir);
	ft_strdel(&tmp);
	ft_strdel_char2(&set_env);
}

static int		ft_change_minus(char *argv, char ***env)
{
	char	*tmp;
	char	*dir;

	if ((tmp = ft_search_in_env(*env, "OLDPWD")) == NULL)
	{
		ft_putendl_fd("cd : No OLDPWD set", 2);
		return (-1);
	}
	if (*argv != '\0')
		argv++;
	if ((dir = ft_strjoin((tmp + 7), argv)) == NULL)
	{
		ft_putendl_fd("cd : error : no free memory", 2);
		return (-1);
	}
	if (chdir(dir) == -1)
	{
		ft_putstr_fd("cd : no such directory : ", 2);
		ft_putendl_fd(dir, 2);
		ft_strdel(&dir);
		return (-1);
	}
	ft_strdel(&dir);
	return (0);
}

static int		ft_shell_cd_part1(int argc, char ***env, char **i_env)
{
	char	*tmp;

	if (argc > 2)
	{
		ft_putendl_fd("cd : too many arguments", 2);
		return (-1);
	}
	else if (argc == 1)
	{
		if ((tmp = ft_search_in_env(i_env, "HOME")) == NULL)
		{
			ft_putendl_fd("cd : No home set", 2);
			return (-1);
		}
		if (chdir(tmp + 5) == -1)
		{
			ft_putstr_fd("cd : no such directory : ", 2);
			ft_putendl_fd(tmp + 5, 2);
			return (-1);
		}
		ft_setoldpwd(env);
		ft_setpwd(env, NULL);
		return (1);
	}
	return (0);
}

void			ft_shell_cd(char **argv, char ***env, char **i_env)
{
	int		argc;
	int		ret;

	argc = ft_char2_index_size(argv);
	ret = ft_shell_cd_part1(argc, env, i_env);
	if (ret == -1 || ret == 1)
		return ;
	if (ft_strncmp(argv[1], "-", 1) == 0)
	{
		if (ft_change_minus(argv[1], env) == -1)
			return ;
		ft_setoldpwd(env);
		ft_setpwd(env, NULL);
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			ft_putstr_fd("cd : no such directory : ", 2);
			ft_putendl_fd(argv[1], 2);
			return ;
		}
		ft_setoldpwd(env);
		ft_setpwd(env, NULL);
	}
}
