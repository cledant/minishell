# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/02/01 13:11:22 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRC_NAME =	ft_strdup_char2.c ft_strcpy_char2.c ft_switch_char2.c \
			ft_char2_index_size.c ft_strdel_char2.c ft_putendl_char2.c \
			ft_strnew_char2.c ft_switch_str.c ft_strlen_till_char.c \
			ft_is_str_alphanum.c ft_is_str_only_spaces.c ft_shell_exit.c \
			ft_shell_setenv.c ft_shell_unsetenv.c ft_shell_env.c \
			ft_shell_cd.c ft_check_shell_env_arg.c ft_seek_exec_path.c \
			ft_is_cmd_builtin.c ft_execute_builtin.c ft_execute_prog.c \
			ft_fork_process.c ft_search_in_env.c ft_search_in_env_with_stop.c \
			ft_search_index_in_env.c ft_search_index_in_env_with_stop.c \
			ft_get_current_dir.c ft_change_shell_level.c main.c \
			ft_strdel_two_char.c ft_shell_setenv_error.c ft_shell_env_tmpenv.c \
			ft_signal.c

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = minishell

all :	libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -I$(INCLUDES) -I$(INCLUDES_LIBFT) -L$(LIBFT_PATH)

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
