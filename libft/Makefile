# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 02:54:12 by awali-al          #+#    #+#              #
#    Updated: 2019/11/23 20:53:43 by awali-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c

OBG = ft_arcon.o ft_isalpha.o ft_itoa.o ft_lstdelone.o ft_lstnew.o ft_memchr.o \
ft_memmove.o ft_putendl.o ft_putstr.o ft_strclr.o ft_strdup.o ft_strjoin.o \
ft_strmapi.o ft_strndup.o ft_strrchr.o ft_strtrim.o ft_atoi.o ft_isascii.o \
ft_lstadd.o ft_lstiter.o ft_lstnmap.o ft_memcmp.o ft_memset.o ft_putendl_fd.o \
ft_putstr_fd.o ft_strcmp.o ft_strequ.o ft_strlcat.o ft_strncat.o ft_strnequ.o \
ft_strsplit.o ft_tolower.o ft_bzero.o ft_isdigit.o ft_lstcat.o ft_lstlen.o \
ft_memalloc.o ft_memcpy.o ft_putchar.o ft_putnbr.o ft_strcat.o ft_strcpy.o \
ft_striter.o ft_strlen.o ft_strncmp.o ft_strnew.o ft_strstr.o ft_toupper.o \
ft_isalnum.o ft_isprint.o ft_lstdel.o ft_lstmap.o ft_memccpy.o ft_memdel.o \
ft_putchar_fd.o ft_putnbr_fd.o ft_strchr.o ft_strdel.o ft_striteri.o ft_strmap.o \
ft_strncpy.o ft_strnstr.o ft_strsub.o get_next_line.o arrdup.o space_tab.c \
split_white_spaces.c

HEADER = libft.h

all : $(NAME)

%.o: %.c
	gcc $(FLAGS) $< -I $(HEADER)

$(NAME): $(OBG)
	ar rc $(NAME) $(OBG)
	ranlib $(NAME)

clean :
	/bin/rm -f  $(OBG)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
