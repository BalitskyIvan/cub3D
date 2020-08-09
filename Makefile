# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmallado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 19:21:22 by lmallado          #+#    #+#              #
#    Updated: 2020/07/13 19:21:30 by lmallado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

HEADER = includes/

LIBFT_DIR = ./libft/libft.a

SRCS = ./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c \
	./SRCS/main.c \
	./SRCS/tools/map_reader/map_reader.c \
	./SRCS/tools/map_reader/map_reader_utils.c \
	./SRCS/tools/map_reader/line_parser.c \
	./SRCS/tools/parser/parser.c \
	./SRCS/tools/error_manager.c

O_FILE = $(patsubst %.c,%.o,$(SRCS))
D_FILE = $(patsubst %.c,%.d,$(SRCS))


FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILE)
	$(MAKE) -C libft all
	gcc $(FLAGS) $(O_FILE) $(LIBFT_DIR) -o $(NAME)
	$(MAKE) -C libft fclean

%.o: %.c ./includes/.h
	gcc -c $(FLAGS) -I$(HEADER) -c $< -o $@ -MD

clean:
	rm -f $(O_FILE)
	rm -f $(D_FILE)

fclean: clean
	rm -f $(NAME)

re:		fclean all

include $(wildcards $(D_FILE))

.PHONY : all clean fclean re
