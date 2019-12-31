# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 14:26:42 by aminewalial       #+#    #+#              #
#    Updated: 2019/12/31 00:28:33 by awali-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRC_FILES =  minishell.c display.c check_command.c envirenement.c free.c line.c\
my_echo.c my_cd.c my_env.c binary_path.c exit_check.c run_command.c set_env.c\
unset_env.c variables.c home_check.c conditions.c

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ_DIR = .obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIB = libft/libft.a

HEADER = includes/minishell.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) $(OBJ) $(LIB) -o $(NAME) 
	clear

$(OBJ) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(FLAGS) -c $< -I $(HEADER) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	
clean :
	make -C libft/ clean
	/bin/rm -rf $(OBJ_DIR)

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re : fclean all
