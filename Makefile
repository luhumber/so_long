# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 13:30:54 by luhumber          #+#    #+#              #
#    Updated: 2023/01/23 10:40:15 by luhumber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS =	main.c \
		window.c \
		parsing.c \
		sprite.c \
		hook.c \
		map.c \
		move.c \
		collision.c

OBJS = $(SRCS:.c=.o)
HEADERS = so_long.h
all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) libft
	$(MAKE) mlx
	cc $(OBJS) $(MLXFLAGS) ./libft/libft.a -o $(NAME)

%.o: %.c  $(HEADERS) Makefile 
		cc $(CFLAGS) -Imlx -I. -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C libft/
	$(MAKE) clean -C mlx/
	rm -f $(NAME)

re: fclean $(NAME)

libft:
	$(MAKE) all -C ./libft/
mlx:
	$(MAKE) -C mlx/

.PHONY: clean fclean re libft mlx
