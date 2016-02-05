/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 15:13:06 by cledant           #+#    #+#             */
/*   Updated: 2016/02/01 13:16:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_del_val(char *line, char **argv, char **cpy_env,
						char **i_env)
{
	if (line != NULL)
		ft_strdel(&line);
	if (cpy_env != NULL)
		ft_strdel_char2(&cpy_env);
	if (i_env != NULL)
		ft_strdel_char2(&i_env);
	if (argv != NULL)
		ft_strdel_char2(&argv);
}

static int		ft_init_main(char ***cpy_env, char ***i_env, char **environ)
{
	signal(SIGINT, ft_signal);
	signal(SIGQUIT, ft_signal);
	signal(SIGTSTP, ft_signal);
	if ((*cpy_env = ft_strdup_char2(environ)) == NULL)
	{
		ft_putendl_fd("minishell : not enough free memory", 2);
		return (0);
	}
	ft_change_shell_level(cpy_env);
	if ((*i_env = ft_strdup_char2(environ)) == NULL)
	{
		ft_strdel_char2(cpy_env);
		ft_putendl_fd("minishell : not enough free memory", 2);
		return (0);
	}
	return (1);
}

static int		ft_main_part_1(char **line, char ***argv,
								char ***cpy_env, char ***i_env)
{
	if (ft_is_cmd_builtin(argv[0][0]) > 0)
	{
		if ((ft_execute_builtin(*argv, cpy_env, *line, *i_env)) == -1)
		{
			ft_del_val(*line, *argv, *cpy_env, *i_env);
			return (0);
		}
	}
	else
	{
		if (ft_strchr(argv[0][0], '/') != NULL)
		{
			if (ft_execute_prog(*argv, *cpy_env) == -1)
			{
				ft_del_val(*line, *argv, *cpy_env, *i_env);
				return (0);
			}
		}
		else if (ft_seek_exec_path(*argv, *cpy_env, *i_env) == -1)
		{
			ft_del_val(*line, *argv, *cpy_env, *i_env);
			return (0);
		}
	}
	return (1);
}

static	int		ft_line(char **line)
{
	ft_putchar('\r');
	ft_putstr("$>");
	if (get_next_line(0, line) == -1)
	{
		ft_putendl_fd("minishell : error while reading line", 2);
		return (-1);
	}
	return (0);
}

int				main(void)
{
	char			*line;
	char			**argv;
	extern char		**environ;
	char			**cpy_env;
	char			**i_env;

	if (ft_init_main(&cpy_env, &i_env, environ) == 0)
		return (0);
	while (1)
	{
		ft_line(&line);
		if (*line != '\0' && ft_is_str_only_spaces(line) == 0)
		{
			if ((argv = ft_strsplit_allspace(line)) == NULL)
			{
				ft_del_val(line, NULL, cpy_env, i_env);
				ft_putendl_fd("minishell : not enough free memory", 2);
				return (-1);
			}
			if (ft_main_part_1(&line, &argv, &cpy_env, &i_env) == 0)
				return (0);
			ft_del_val(line, argv, NULL, NULL);
		}
	}
	return (0);
}
