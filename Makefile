# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 15:53:18 by rsharipo          #+#    #+#              #
#    Updated: 2018/09/05 10:50:33 by rsharipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./rsharipo.filler

LIB = libft.a

LIBDIR = ./libft

SRC = board.c exit_prog.c find_spot.c get_data.c token.c choose_dir.c \
	  filler.c free_data.c init_data.c token_coor.c mask_board.c \
	  print_func.c mark_invalid.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

SAN = -g -fsanitize=address

all: $(NAME)

$(NAME):
	@cd ./libft && $(MAKE)
	@gcc -c $(CFLAGS) $(SRC)
	@gcc $(CFLAGS) $(OBJ) $(LIBDIR)/$(LIB) -o $(NAME)

f:
	@gcc -c $(CFLAGS) $(SRC)
	@gcc $(CFLAGS) $(OBJ) $(LIBDIR)/$(LIB) -o $(NAME)

s:
	@cd ./libft && $(MAKE) s
	@gcc -c $(SAN) $(CFLAGS) $(SRC)
	@gcc $(SAN) $(CFLAGS) $(OBJ) $(LIBDIR)/$(LIB) -o $(NAME)

d:
	@cd ./libft && $(MAKE) d
	@gcc -g $(CFLAGS) $(SRC) $(LIBDIR)/$(LIB)

clean:
	@cd ./libft && $(MAKE) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@cd ./libft && $(MAKE) fclean
	@/bin/rm -f $(NAME)

re: fclean all
