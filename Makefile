# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 14:26:42 by aminewalial       #+#    #+#              #
#    Updated: 2019/11/20 15:17:07 by awali-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRC_FILES =  minishell.c display.c spaces.c check_command.c envirenement.c \
my_echo.c my_cd.c my_env.c binary_path.c

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ_DIR = .obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIB = libft/libft.a

HEADER = includes/minishell.h

all : $(NAME)

$(NAME) : $(OBJ)
	echo $(OBJ)
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
